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
//              when the root changes to red.So black height can be maintained like so.
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
        RedBlackTree<K,D>(),black_height(0)
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

    /**
     * @brief insert
     * @param added
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

    virtual ~RedBlackTreeWithBh(){ }


protected:

    SizeType    black_height;

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
        if(Base::root->color    ==  Color::RED)
            ++black_height;

        Base::root->color = Color::BLACK;
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
