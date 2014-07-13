/***************************************************************************
 *  @file       redblacktree.hpp
 *  @author     Alan.W
 *  @date       05  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include <memory>
#include <functional>
#include <vector>
#include "node.hpp"

namespace ch13{

/**
 * @brief The RedBlackTree class
 */
template<typename K, typename D>
class RedBlackTree
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using NodeType  =   Node<K,D>;
    using sPointer  =   std::shared_ptr<NodeType>;
    using wPointer  =   std::weak_ptr<NodeType>;


    RedBlackTree():
        nil(std::make_shared<NodeType>())
    {
        root = nil;
    }

    /**
     * @brief remove
     *
     * @compx   O(lg n)
     *
     * @page    324
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
        {
            remove_fixup(x);
        }
    }

    /**
     * @brief print
     *
     * O(n)
     */
    virtual void print()const
    {
        std::cout << "-----------------------------\n";
        std::cout << debug::yellow("root= ") << root
                  << " key = " << root->key  << std::endl;
        std::cout << debug::yellow("nil = ") << nil
                  << std::endl;

        if(root == nil)
        {
            std::cout << debug::yellow("this is an EMPTY TREE!\n");
            return;
        }

        std::function<void(sPointer node)> inorder_walk =
                [&inorder_walk,this](sPointer node)
        {
            if(node != nil)
            {
                inorder_walk(node->left);
                node->print();
                inorder_walk(node->right);
            }
        };
        inorder_walk(root);
    }

    /**
     * @brief insert
     * @param key
     *
     * just an interface
     */
    virtual void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    /**
     * @brief insert
     * @param key
     * @param data
     *
     * just an interface
     */
    virtual void insert(const KeyType &key, const DataType& data)
    {
        sPointer added = std::make_shared<NodeType>(key,data);
        insert(added);
    }

    /**
     * @brief insert
     * @param added
     *
     * @page    315
     * O(h)
     */
    virtual void insert(sPointer added)
    {
        sPointer tracker = nil;
        sPointer curr = root;
        while(curr != nil)
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
     * @brief search
     * @param key
     *
     * @complx  O(h)
     */
    sPointer search(const KeyType& key)const
    {
        sPointer ret  = nullptr;
        sPointer curr = this->root;
        while(curr)
        {
            if(curr->key    ==  key)
            {
                ret = curr;
                break;
            }
            else
                curr = (curr->key > key?    curr->left  :   curr->right);
        }
        return ret;
    }

    /**
     * @brief left_rotate
     * @param x
     *
     *      [x]                    [y]
     *         \         =>       /
     *          [y]            [x]
     *
     * @complx  o(1)
     *
     * @page    313
     */
    void left_rotate(sPointer x)
    {
        sPointer y = x->right;      //  set y

        x->right    =   y->left;    //  turn y's left into x's right
        if(y->left  !=  this->nil)
            y->left->parent = x;

        y->parent   =   x->parent;  //  link x's parent to y
        if(x->parent.lock()    ==  this->nil)
            this->root  =   y;
        else
            (x->is_left()?  x->parent.lock()->left  :  x->parent.lock()->right)
                        =   y;

        y->left     =   x;
        x->parent   =   y;
    }

    /**
     * @brief right_rotate
     * @param y
     *
     *          [y]             [x]
     *          /        =>        \
     *        [x]                   [y]
     *
     * @complx  O(1)
     */
    void right_rotate(sPointer y)
    {
        sPointer x = y->left;

        y->left = x->right;
        if(x->right != this->nil)
            x->right->parent    =   y;

        x->parent   =   y->parent;
        if(y->parent.lock() ==  this->nil)
            root    =   x;
        else
            (y->is_left()?  y->parent.lock()->left  :  y->parent.lock()->right)
                    =   x;

        x->right    =   y;
        y->parent   =   x;
    }

    /**
     * @brief return the argument's sibling node
     */
    sPointer sibling(sPointer node)
    {
        assert(node != this->root);

        sPointer pnt = node->parent.lock();
        return node->is_left()?     pnt->right  :   pnt->left;
    }

    virtual ~RedBlackTree(){}

protected:

    /**
     * @brief transplant
     * @param to
     * @param from
     *
     * @note    a bit different from the BST version
     * @complx  O(1)
     * @page    323
     */
    void transplant(sPointer to, sPointer from)    
    {
        if(ascend(to,1) == this->nil)
            this->root  =   from;
        else
            (to->is_left()?     ascend(to,1)->left    :   ascend(to,1)->right)
                        =   from;

        from->parent    =   to->parent;
    }

    /**
     * @brief minimum
     */
    sPointer minimum(sPointer node)
    {
        assert(node != this->nil);

        sPointer tracker = node;
        while(node != this->nil)
        {
            tracker =   node;
            node    =   node->left;
        }

        return tracker;
    }

    /**
     * @brief ascend
     *
     * used for insert_fixup
     */
    sPointer ascend(sPointer node, int level)
    {
        while(level--)
            node = node->parent.lock();
        return node;
    }

    /**
     * @brief insert_fixup
     *
     * @complx  O(1)
     *
     * based on the pyseudocode on Page 316
     */
    void insert_fixup(sPointer added)
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
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    left_rotate(ascend(added,2));
                }
            }
        }
        root->color = Color::BLACK;
    }

    /**
     * @brief remove_fixup
     * @param x
     *
     * @complx  O(lg n)
     * @page    326
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
                    sister->color       =   Color::BLACK;
                    ascend(x,1)->color  =   Color::RED;
                    left_rotate(ascend(x,1));
                    sister              =   ascend(x,1)->right;
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
                    sister->color       =   Color::BLACK;
                    ascend(x,1)->color  =   Color::RED;
                    right_rotate(ascend(x,1));
                    sister              =   ascend(x,1)->left;
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
                    sister->color           =   ascend(x,1)->color;
                    ascend(x,1)->color      =   Color::BLACK;
                    sister->left->color     =   Color::BLACK;
                    right_rotate(ascend(x,1));
                    x   =   root;
                }
            }
        }
        x->color  =  Color::BLACK;
    }

    sPointer root;
    sPointer nil;
};
}//namespace


#endif // REDBLACKTREE_HPP

//! testing insert()
//#include <iostream>
//#include <vector>
//#include <node.hpp>
//#include "redblacktree.hpp"

//int main()
//{
//    std::vector<int> v =
//        {6,5,1,1,2,34,5,6,7,8,9,8,7,4,3,2,2,3,5,6,7,2,345};
//    ch13::RedBlackTree<int,std::string> tree;

//    for(auto i : v)
//        tree.insert(i);

//    tree.print();
//    std::cout << "length = " << v.size() << std::endl;

//    return 0;
//}

//! testing remove()
//#include <iostream>
//#include <vector>
//#include <node.hpp>
//#include "redblacktree.hpp"

//int main()
//{
//    std::vector<int> v =
//        {2,3,6,99,22,33,5,67};
//    ch13::RedBlackTree<int,std::string> tree;

//    for(auto i : v)
//        tree.insert(i);
//    tree.print();

//    tree.remove(tree.search(6));
//    tree.print();

//    std::cout << debug::green("\n====end====") << std::endl;

//    return 0;
//}

//!
//! ex13.4-3
//! In Exercise 13.3-2, you found the red-black tree that results from successively
//! inserting the keys 41; 38; 31; 12; 19; 8 into an initially empty tree. Now show the
//! red-black trees that result from the successive deletion of the keys in the order
//! 8; 12; 19; 31; 38; 41.
//!
//#include <iostream>
//#include <vector>
//#include <node.hpp>
//#include "redblacktree.hpp"

//int main()
//{
//    std::vector<int> v =
//        {41,38,31,12,19,8};
//    ch13::RedBlackTree<int,std::string> tree;

//    for(auto i : v)
//        tree.insert(i);
//    tree.print();

//    tree.remove(tree.search(8));
//    tree.print();
//    tree.remove(tree.search(12));
//    tree.print();
//    tree.remove(tree.search(19));
//    tree.print();
//    tree.remove(tree.search(31));
//    tree.print();
//    tree.remove(tree.search(38));
//    tree.print();
//    tree.remove(tree.search(41));
//    tree.print();

//    std::cout << debug::green("\n====end====") << std::endl;

//    return 0;
//}
//!
//! ex13.4-7
//! Suppose that a node x is inserted into a red-black tree with RB-I NSERT and then
//! is immediately deleted with RB-D ELETE . Is the resulting red-black tree the same
//! as the initial red-black tree? Justify your answer.
//!
//#include <iostream>
//#include <vector>
//#include "redblacktree.hpp"

//int main()
//{
//    std::vector<int> v =
//        {5,1,8};
//    ch13::RedBlackTree<int,std::string> tree;

//    for(auto i : v)
//        tree.insert(i);
//    tree.print();

//    //! insert node with key = 3
//    tree.insert(3);
//    tree.print();

//    //! delete it
//    tree.remove(tree.search(3));
//    tree.print();

//    std::cout << debug::green("\n====end====") << std::endl;

//    return 0;
//}
