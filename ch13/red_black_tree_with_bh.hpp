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
//
//  Deletion:   to be done.
//
//  deterining the node's bh in O(1) time:
//              as get_bh() shows.
//
//!
//! b.  Assume that T1.bh >= T2.bh. Describe an O(lg n)-time algorithm that finds a
//!     black node y in T1 with the largest key from among those nodes whose black-
//!     height is T2.bh.
//!
//  As shown in join() function below.
//!
//! c.  Let Ty be the subtree rooted at y. Describe how Ty U {x} U T2 can replace Ty
//!     in (1) time without destroying the binary-search-tree property.
//!
//  As shown in join() function below.
//!
//! d.  What color should we make x so that red-black properties 1, 3, and 5 are main-
//!     tained? Describe how to enforce properties 2 and 4 in O(lg n) time.
//      obviously red.
//      using the same method as in RB-INSERT-FIXUP() can enforce properties 2 and 4
//          --  this one is not implemented.
//! e.  Argue that no generality is lost by making the assumption in part (b). Describe
//!     the symmetric situation that arises when T1.bh <= T2.bh.
//!
//      skipped
//!
//! f. Argue that the running time of RB-JOIN is O(lg n)
//!
//      obviously
//!


#ifndef RED_BLACK_TREE_WITH_BH_HPP
#define RED_BLACK_TREE_WITH_BH_HPP

#include "redblacktree.hpp"

namespace ch13
{
/**
 *  @brief  foward declarations
 */
template<typename K, typename D>
class RedBlackTreeWithBh;

template<typename K, typename D>
RedBlackTreeWithBh<K,D>
join(
                RedBlackTreeWithBh<K,D>& lhs,
     typename   RedBlackTreeWithBh<K,D>::sPointer x,
                RedBlackTreeWithBh<K,D>& rhs
    );




/**
 * @brief The RedBlackTreeWithBh class
 *
 * for problem 13-2.a
 */
template<typename K, typename D>
class RedBlackTreeWithBh : public RedBlackTree<K,D>
{
    friend  RedBlackTreeWithBh<K,D> join<K,D>
                (
                                RedBlackTreeWithBh<K,D>& lhs,
                    typename    RedBlackTreeWithBh<K,D>::sPointer x,
                                RedBlackTreeWithBh<K,D>& rhs
                );
public:
    //! types def
    using Base      =               RedBlackTree<K,D>;
    using sPointer  =   typename    Base::sPointer;
    using KeyType   =   typename    Base::KeyType;
    using DataType  =   typename    Base::DataType;
    using NodeType  =   typename    Base::NodeType;
    using SizeType  =               std::size_t;

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

    /**
     * @brief remove
     * @param target
     *
     * @todo    find a way to record bh decrementing
     */
    virtual void remove(sPointer target)
    {
        sPointer x,y;
        Color  y_original_color;

        if(target->left == this->nil)
        {
            y = target;
            y_original_color = y->color;
            x = y->right;
            transplant(target,x);
        }
        else if(target->right   ==  this->nil)
        {
            y = target;
            y_original_color = y->color;
            x = y->left;
            transplant(target,x);
        }
        else
        {
            y = minimum(target->right);
            y_original_color = y->color;
            x = y->right;

            if(y->parent.lock() ==  target)
                x->parent   =   y;
            else
            {
                transplant(y,x);
                y->right    =   target->right;
                y->right->parent    =   y;
            }

            transplant(target, y);
            y->left         =   target->left;
            y->left->parent =   y;
            y->color        =   target->color;
        }

        if(y_original_color ==  Color::BLACK)
            remove_fixup(x);
    }

    /**
     * @brief get_bh
     * @param key
     *
     * @complx O(h)
     *
     * @note    this function takes O(h) time for decending
     *          but the running time for getting black_height of each node
     *          visited takes O(1)
     */
    SizeType get_bh(const KeyType& key)const
    {
        SizeType bh = black_height;
        sPointer curr = root;
        while(curr != nil  &&  curr->key != key)
        {
            if(curr != root  &&  curr->color == Color::BLACK)
                --bh;

            curr = (curr->key < key?    curr->right     :   curr->left);
        }

        assert(curr != nil);
        return bh;
    }

    virtual ~RedBlackTreeWithBh(){ }
protected:
    SizeType    black_height;

    //! members from base class
    using Base::transplant;
    using Base::ascend;
    using Base::left_rotate;
    using Base::right_rotate;
    using Base::minimum;
    using Base::sibling;

    using Base::nil;
    using Base::root;

    /**
     * @brief update_nil
     * @param new_nil
     *
     * this function is needed for join () function.
     */
    void update_nil(sPointer new_nil)
    {
        //! lambda for update nil recursively
        std::function<void(sPointer)> preorder_walk
                =   [&](sPointer node)
        {
            if(node != new_nil)
            {
                if(node->left   ==  nil)        node->left  =   new_nil;
                if(node->right  ==  nil)        node->right =   new_nil;

                preorder_walk(node->left);
                preorder_walk(node->right);
            }
        };

        //! update
        preorder_walk(root);
        root->parent    =   nil    =   new_nil;
    }

    /**
     * @brief insert
     * @param added
     *
     * @complx  O(h)
     */
    virtual void insert(sPointer added)
    {
        sPointer tracker = nil;
        sPointer curr = root;
        while(curr != Base::nil)
        {
            tracker =   curr;
            curr    =   curr->key > added->key?     curr->left  :   curr->right;
        }

        added->parent   =   tracker;
        if(tracker == nil)
            root    =   added;
        else
            (added->key < tracker->key?     tracker->left   :   tracker->right)
                    =   added;

        added->left =   added->right    =   nil;
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
        while(ascend(added,1)->color   ==  Color::RED)
        {
            if(ascend(added,1)->is_left())
            {
                sPointer uncle = ascend(added,2)->right;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color            =   Color::BLACK;
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    added   =   ascend(added,2);
                }
                else
                {
                    if(added->is_right())
                    {
                        added   =   ascend(added,1);
                        left_rotate(added);
                    }
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    right_rotate(ascend(added,2));
                }
            }
            else
            {
                sPointer uncle = ascend(added,2)->left;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color            =   Color::BLACK;
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    added   =   ascend(added,2);
                }
                else
                {
                    if(added->is_left())
                    {
                        added   =   ascend(added,1);
                        right_rotate(added);
                    }
                    ascend(added,1)->color    =   Color::BLACK;
                    ascend(added,2)->color    =   Color::RED;
                    left_rotate(ascend(added,2));
                }
            }
        }

        //! @attention:
        //!     maintain the black height data member
        //!     as required in problem 13-1.a
        if(root->color    ==  Color::RED
                &&
                    (root->left    !=  nil
                        ||
                            root->right   !=  nil))
            ++black_height;

        root->color = Color::BLACK;
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
        while(x != root   &&   x->color == Color::BLACK)
        {
            if(x->is_left())
            {
                sPointer sister = sibling(x);

                //! case 1
                if(sister->color    ==  Color::RED)
                {
                    sister->color               =   Color::BLACK;
                    ascend(x,1)->color          =   Color::RED;
                    left_rotate(ascend(x,1));
                    sister                      =   ascend(x,1)->right;
                }

                //! case 2
                if(sister->left->color  ==  Color::BLACK
                        &&
                            sister->right->color  ==  Color::BLACK)
                {
                    sister->color   =   Color::RED;
                    x   =   ascend(x,1);
                }
                else
                {
                    //! case 3
                    if(sister->right->color ==  Color::BLACK)
                    {
                        sister->left->color =   Color::BLACK;
                        sister->color       =   Color::BLACK;
                        right_rotate(sister);
                        sister              =   sibling(x);
                    }

                    //! case 4
                    sister->color           =   ascend(x,1)->color;
                    ascend(x,1)->color      =   Color::BLACK;
                    sister->right->color    =   Color::BLACK;
                    left_rotate(ascend(x,1));
                    x   =   root;
                }
            }
            else
            {
                sPointer sister = sibling(x);

                //! case 1
                if(sister->color    ==  Color::RED)
                {
                    sister->color               =   Color::BLACK;
                    ascend(x,1)->color          =   Color::RED;
                    right_rotate(ascend(x,1));
                    sister                      =   ascend(x,1)->left;
                }

                //! case 2
                if(sister->left->color  ==  Color::BLACK
                        &&
                            sister->right->color  ==  Color::BLACK)
                {
                    sister->color   =   Color::RED;
                    x   =   ascend(x,1);
                }

                else
                {
                    //! case 3
                    if(sister->left->color ==  Color::BLACK)
                    {
                        sister->right->color    =   Color::BLACK;
                        sister->color           =   Color::BLACK;
                        left_rotate(sister);
                        sister  =  sibling(x);
                    }

                    //! case 4
                    sister->color       =   ascend(x,1)->color;
                    ascend(x,1)->color  =   Color::BLACK;
                    sister->left->color =   Color::BLACK;
                    right_rotate(ascend(x,1));
                    x   =   root;
                }
            }
        }

        x->color  =  Color::BLACK;
    }
};

/**
 * @brief join
 * @param lhs
 * @param x
 * @param rhs
 *
 * @note    as required, this procedure destories both lhs and rhs
 *
 * for problem 13-2.b c d e
 */
template<typename K, typename D>
inline RedBlackTreeWithBh<K,D>
join(
                RedBlackTreeWithBh<K,D>& lhs,
     typename   RedBlackTreeWithBh<K,D>::sPointer x,
                RedBlackTreeWithBh<K,D>& rhs
        )
{
    using Tree      =               RedBlackTreeWithBh<K,D>;
    using sPointer  =   typename    Tree::sPointer;
    using SizeType  =   typename    Tree::SizeType;

    Tree& low       =   (lhs.black_height < rhs.black_height?   lhs :   rhs);
    Tree& high      =   (lhs.black_height < rhs.black_height?   rhs :   lhs);


    //! problem 13-2. part b
    //! find the node with largest key and bh equal to sml.bh
    //! at the end of while loop, curr is just the y looked for
    sPointer curr   =   high.root;
    SizeType bh     =   high.black_height;
    while(bh != low.black_height)
    {
        assert(curr != high.nil);

        bh  -=  (curr != high.root  &&  curr->color == Color::BLACK)?  1  :  0;
        curr =  (curr->right != high.nil?     curr->right     :   curr->left);
    }


    //! problem 13-2    part c
    //! graft on the smaller tree.

    //! @attention
    //!     each tree has an unique nil, which need to manange.
    low.update_nil(high.nil);

    high.transplant(curr, x);
    x->color        =   Color::RED;
    x->left         =   curr;
    x->right        =   low.root;
    curr->parent    =   low.root->parent    =   x;
    Tree ret = high;

    //! destroy old trees, as required
    high    =   low     =   Tree();

    return ret;
}


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

//! for testing geting bh when visiting a node
//    std::cout << tree.get_bh(41) << std::endl;

//    return 0;
//}

//! for testing join
//#include <iostream>
//#include <vector>
//#include "red_black_tree_with_bh.hpp"

//int main()
//{
//    using Tree      =   ch13::RedBlackTreeWithBh<int, std::string>;
//    using NodeType  =   ch13::Node<int, std::string>;
//    using sPointer  =   typename ch13::RedBlackTree<int, std::string>::sPointer;
//    using namespace ch13;

//    std::vector<int> v;

//    Tree lhs;
//    v = {41,38,31,12,19,8,7,5,2,0};
//    for(auto i : v)
//        lhs.insert(i);
//    lhs.print();

//    Tree rhs;
//    v = {333,888,111,222};
//    for(auto i : v)
//        rhs.insert(i);
//    rhs.print();

//    std::cout << debug::green("join:\n");
//    sPointer x = std::make_shared<NodeType>(100);

//    auto sum = join(lhs,x,rhs);
//    sum.print();

//    lhs.print();
//    rhs.print();
//    std::cout << "end\n";

//    return 0;
//}

