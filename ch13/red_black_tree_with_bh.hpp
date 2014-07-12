/***************************************************************************
 *  @file       red_black_tree_no_parent.h
 *  @author     Alan.W
 *  @date       12  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
//!
//! Problem 13-2 Join operation on red-black trees
//!
//! a. Given a red-black tree T , let us store its black-height as the new attribute T:bh.
//! Argue that RB-INSERT and RB-DELETE can maintain the bh attribute with-
//! out requiring extra storage in the nodes of the tree and without increasing the
//! asymptotic running times. Show that while descending through T , we can de-
//! termine the black-height of each node we visit in O(1) time per node visited.
//!
//  Insert  :   as shown by running the testing code below, black hight only increments
//              when the root changes to red. This property can also be proven  through
//              its symmetry.
//              So black height can be maintained like so.
//!

#ifndef RED_BLACK_TREE_WITH_BH_HPP
#define RED_BLACK_TREE_WITH_BH_HPP

#include "redblacktree.hpp"

namespace ch13
{

/**
 * @brief The RedBlackTreeWithBh class
 *
 * for problem 13-2.a
 */
template<typename K, typename D>
class RedBlackTreeWithBh : public RedBlackTree<K,D>
{
public:
    using Base      =   RedBlackTree<K,D>;
    using sPointer  =   typename Base::sPointer;
    using KeyType   =   typename Base::KeyType;
    using DataType  =   typename Base::DataType;
    using NodeType  =   typename Base::NodeType;
    using SizeType  =   std::size_t;

    /**
     * @brief default Ctor
     */

    RedBlackTreeWithBh():
        Base(),black_height(0)
    {}

    /**
     * @brief print
     */
    virtual void print() const
    {
        RedBlackTree<K,D>::print();
        std::cout << debug::yellow("black Height = ")
                  << black_height
                  << std::endl;


        std::cout << "\n" << std::endl;
    }

    /**
     * @brief insert
     * @param key
     * @param data
     */
    virtual void insert(const KeyType &key, const DataType& data)
    {
        sPointer added = std::make_shared<NodeType>(key,data);
        insert(added);
    }

    /**
     * @brief insert
     * @param key
     */
    virtual void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    virtual void remove(sPointer target)
    {
        sPointer x,y;
        Color  y_original_color;

        if(target->left == this->nil)
        {
            y = target;
            y_original_color = y->color;
            x = y->right;
            Base::transplant(target,x);
        }
        else if(target->right   ==  this->nil)
        {
            y = target;
            y_original_color = y->color;
            x = y->left;
            Base::transplant(target,x);
        }
        else
        {
            y = Base::minimum(target->right);
            y_original_color = y->color;
            x = y->right;

            if(y->parent.lock() ==  target)
                x->parent   =   y;
            else
            {
                Base::transplant(y,x);
                y->right    =   target->right;
                y->right->parent    =   y;
            }

            Base::transplant(target, y);
            y->left         =   target->left;
            y->left->parent =   y;
            y->color        =   target->color;
        }

        if(y_original_color ==  Color::BLACK)
            remove_fixup(x);

    }

    virtual ~RedBlackTreeWithBh(){ }
protected:
    SizeType    black_height;

    /**
     * @brief insert
     * @param added
     *
     * @complx  O(h)
     */
    virtual void insert(sPointer added)
    {
        sPointer tracker = Base::nil;
        sPointer curr = Base::root;
        while(curr != Base::nil)
        {
            tracker =   curr;
            curr    =   curr->key > added->key?     curr->left  :   curr->right;
        }

        added->parent   =   tracker;
        if(tracker == Base::nil)
            Base::root    =   added;
        else
            (added->key < tracker->key?     tracker->left   :   tracker->right)
                    =   added;

        added->left =   added->right    =   Base::nil;
        added->color=   Color::RED;

        insert_fixup(added);
    }

    /**
     * @brief insert_fixup
     * @param added
     *
     * @complx O(h)
     */
    virtual void insert_fixup(sPointer added)
    {
        while(Base::ascend(added,1)->color   ==  Color::RED)
        {
            if(Base::ascend(added,1)->is_left())
            {
                sPointer uncle = Base::ascend(added,2)->right;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color            =   Color::BLACK;
                    Base::ascend(added,1)->color  =   Color::BLACK;
                    Base::ascend(added,2)->color  =   Color::RED;
                    added   =   Base::ascend(added,2);
                }
                else
                {
                    if(added->is_right())
                    {
                        added   =   Base::ascend(added,1);
                        Base::left_rotate(added);
                    }
                    Base::ascend(added,1)->color  =   Color::BLACK;
                    Base::ascend(added,2)->color  =   Color::RED;
                    Base::right_rotate(Base::ascend(added,2));
                }
            }
            else
            {
                sPointer uncle = Base::ascend(added,2)->left;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color                    =   Color::BLACK;
                    Base::ascend(added,1)->color    =   Color::BLACK;
                    Base::ascend(added,2)->color    =   Color::RED;
                    added   =   Base::ascend(added,2);
                }
                else
                {
                    if(added->is_left())
                    {
                        added   =   Base::ascend(added,1);
                        Base::right_rotate(added);
                    }
                    Base::ascend(added,1)->color    =   Color::BLACK;
                    Base::ascend(added,2)->color    =   Color::RED;
                    Base::left_rotate(Base::ascend(added,2));
                }
            }
        }

        //! @attention:
        //!     maintain the black height data member
        //!     as required in problem 13-1.a
        if(Base::root->color    ==  Color::RED
                &&
                    (Base::root->left    !=  Base::nil
                        ||
                            Base::root->right   !=  Base::nil))
            ++black_height;

        Base::root->color = Color::BLACK;
    }

    /**
     * @brief remove_fixup
     * @param x
     *
     * @complx  O(lg n)
     * @todo    find a way to maintain bh when deleting
     */
    virtual void remove_fixup(sPointer x)
    {
        while(x != Base::root   &&   x->color == Color::BLACK)
        {
            if(x->is_left())
            {
                sPointer sister = Base::sibling(x);

                //! case 1
                if(sister->color    ==  Color::RED)
                {
                    sister->color               =   Color::BLACK;
                    Base::ascend(x,1)->color    =   Color::RED;
                    Base::left_rotate(Base::ascend(x,1));
                    sister                      =   Base::ascend(x,1)->right;
                }

                //! case 2
                if(sister->left->color  ==  Color::BLACK
                        &&
                            sister->right->color  ==  Color::BLACK)
                {
                    sister->color   =   Color::RED;
                    x   =   Base::ascend(x,1);
                }
                else
                {
                    //! case 3
                    if(sister->right->color ==  Color::BLACK)
                    {
                        sister->left->color =   Color::BLACK;
                        sister->color       =   Color::BLACK;
                        Base::right_rotate(sister);
                        sister              =   Base::sibling(x);
                    }

                    //! case 4
                    sister->color           =   Base::ascend(x,1)->color;
                    Base::ascend(x,1)->color=   Color::BLACK;
                    sister->right->color    =   Color::BLACK;
                    Base::left_rotate(Base::ascend(x,1));
                    x   =   Base::root;
                }
            }
            else
            {
                sPointer sister = Base::sibling(x);

                //! case 1
                if(sister->color    ==  Color::RED)
                {
                    sister->color               =   Color::BLACK;
                    Base::ascend(x,1)->color    =   Color::RED;
                    Base::right_rotate(Base::ascend(x,1));
                    sister                      =   Base::ascend(x,1)->left;
                }

                //! case 2
                if(sister->left->color  ==  Color::BLACK
                        &&
                            sister->right->color  ==  Color::BLACK)
                {
                    sister->color   =   Color::RED;
                    x   =   Base::ascend(x,1);
                }

                else
                {
                    //! case 3
                    if(sister->left->color ==  Color::BLACK)
                    {
                        sister->right->color    =   Color::BLACK;
                        sister->color           =   Color::BLACK;
                        Base::left_rotate(sister);
                        sister  =  Base::sibling(x);
                    }

                    //! case 4
                    sister->color               =   Base::ascend(x,1)->color;
                    Base::ascend(x,1)->color    =   Color::BLACK;
                    sister->left->color         =   Color::BLACK;
                    Base::right_rotate(Base::ascend(x,1));
                    x   =   Base::root;
                }
            }
        }

        x->color  =  Color::BLACK;
    }
};

}//namespace
#endif // RED_BLACK_TREE_WITH_BH_HPP

//! code for testing problem 13-2.a insert part
//#include <iostream>
//#include <vector>
//#include "red_black_tree_with_bh.hpp"

//int main()
//{
//    ch13::RedBlackTreeWithBh<int, std::string> tree;

//    std::vector<int> v = {41,38,31,12,19,8,7,5,2,0};
//    for(auto i : v)
//        tree.insert(i);

//    tree.print();
//    return 0;
//}
