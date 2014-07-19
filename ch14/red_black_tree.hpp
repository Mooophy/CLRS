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
    void print()const
    {
        std::cout << "--------------------------------\n";
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
    void insert(const KeyType& key)
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
    void insert(const KeyType &key, const DataType& data)
    {
        sPointer added = std::make_shared<NodeType>(key,data);
        insert(added);
    }

    /**
     * @brief remove
     *
     * @compx   O(lg n)
     *
     * @page    324
     */
    void remove(sPointer target)
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

    virtual ~RedBlackTree(){}
protected:
    sPointer root;
    sPointer nil;

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
     * @brief insert_first_part
     * @param added
     *
     * @complx  O(h)
     */
    void insert_first_part(sPointer added)
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
        insert_first_part(added);
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
     *
     * @attention modified to be virtual for this chapter
     */
    virtual void left_rotate(sPointer x)
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
    virtual void right_rotate(sPointer y)
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

    /**
     * @brief remove_fixup
     * @param x
     *
     * @complx  O(lg n)
     * @page    326
     */
    void remove_fixup(sPointer x)
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
};

}//namespace


#endif // RED_BLACK_TREE_HPP
