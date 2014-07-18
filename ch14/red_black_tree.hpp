/***************************************************************************
 *  @file       red_black_tree.hpp
 *  @author     Alan.W
 *  @date       18  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>
#include <functional>
#include <vector>
#include "node.hpp"

namespace ch14
{

/**
 * @brief The RedBlackTree class
 *
 * as the base class
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

    //! @brief  default Ctor
    RedBlackTree():
        nil(std::make_shared<NodeType>())
    {
        root = nil;
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


    virtual ~RedBlackTree(){}
protected:
    sPointer root;
    sPointer nil;


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
     * @brief return the argument's sibling node
     */
    sPointer sibling(sPointer node)
    {
        assert(node != this->root);

        sPointer pnt = node->parent.lock();
        return node->is_left()?     pnt->right  :   pnt->left;
    }
};

}//namespace


#endif // RED_BLACK_TREE_HPP
