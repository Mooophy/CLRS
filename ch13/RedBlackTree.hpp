/***************************************************************************
 *  @file       RedBlackTree.hpp
 *  @author     Yue Wang
 *  @date       02  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <functional>
#include "Node.hpp"


namespace ch13{

/**
 * @brief Red Black Tree
 */
template<typename K, typename D>
class RedBlackTree
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using sPointer  =   std::shared_ptr<Node<K,D> >;
    using wPointer  =   std::weak_ptr<Node<K,D> >;

    /**
     * @brief default ctor
     */
    RedBlackTree():
        root(),nil(std::make_shared<Node<K,D>>())
    {}

    /**
     * @brief insert
     * @param key
     * @param data
     *
     * overloading insert()
     */
    void insert(const KeyType& key, const DataType& data)
    {
        sPointer added = std::make_shared<Node<KeyType,DataType>>(key, data);
        insert(added);
    }

    /**
     * @brief insert
     *
     * @complexity  O(h)
     *
     * based on that of Page 316
     */
    void insert(sPointer added)
    {
        sPointer tracker    =   this->nil;
        sPointer curr       =   this->root;
        while(curr != this->nil)
        {
            tracker =   curr;
            curr    =   (curr->key > added->key?    curr->left  :   curr->right);
        }

        added->parent   =   tracker;
        if(tracker  ==  this->nil)
            this->root  =   added;
        else
            (added->key < tracker->key?     tracker->left   :   tracker->right)
                        =   added;

        added->left     =   added->right    =   this->nil;
        added->color    =   Color::Red;
        insert_fixup(added);
    }

    /**
     * @brief print
     *
     * @compplexity O(n)
     *
     * i.e. inorder_walk
     */
    void print()const
    {
        std::function<void(sPointer)> inorder_walk =
                [&](const sPointer& node)
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

private:
    sPointer root;
    sPointer nil;

    /**
     * @brief left_rotate
     *
     * @complexity  O(1)
     *
     * based on LEFT-ROTATE     Page 313
     *      x   :   target
     *      y   :   new_parent
     */
    void left_rotate(sPointer target)
    {
        sPointer new_parent = target->right;

        //! turn new_parent's left subtree into target's right subtree
        target->right   =   new_parent->left;
        if(target->left != this->nil)
            new_parent->left->parent.lock()  =  target;

        //! link target's parent to new_parent
        new_parent->parent  =   target->parent;
        if(target->parent.lock()   ==  this->nil)
            this->root  =   new_parent;
        else
        {
            sPointer pnt = target->parent.lock();
            (target == pnt->left?   pnt->left   :   pnt->right)    =   new_parent;
        }

        //! put target on new_parent’s left
        new_parent->left    =   target;
        target->parent      =   new_parent;
    }

    /**
     * @brief right_rotate
     *
     * @complexity  O(1)
     *
     * as required for ex13.2-1
     */
    void right_rotate(sPointer target)
    {
        sPointer new_parent = target->left;

        //! turn new_parent's right subtree into target's left subtree
        target->left    =   new_parent->right;
        if(new_parent->right    !=  this->nil)
            new_parent->right->parent.lock()    =   target;

        //! link target's parent to new_parent
        if(target->parent.lock()    ==  this->nil)
            this->root  =   new_parent;
        else
        {
            sPointer pnt = target->parent.lock();
            (target == pnt->left?   pnt->left   :   pnt->right)     =   new_parent;
        }

        //! put target on new_parent’s right
        new_parent->right   =   target;
        target->parent      =   new_parent;
    }

    /**
     * @brief insert_fixup
     *
     * @complexity  O(1)
     *
     * based on that on Page 316
     */
    void insert_fixup(sPointer target)
    {
        while(target->parent.lock()->color ==  Color::Red)
        {
            if(target->parent.lock()    ==
               target->parent.lock()->parent.lock()->left)
            {
                sPointer uncle  =   target->parent.lock()->parent.lock()->right;
                if(uncle->color ==  Color::Red)
                {
                    uncle->color = Color::Black;
                    target->parent.lock()->color = Color::Black;
                    target->parent.lock()->parent.lock()->color = Color::Red;
                }
                else
                {
                    if(target   ==  target->parent.lock()->right)
                    {
                        target  =   target->parent.lock();
                        left_rotate(target);
                    }
                    target->parent.lock()->color                =   Color::Black;
                    target->parent.lock()->parent.lock()->color =   Color::Red;
                    right_rotate(target->parent.lock()->parent.lock());
                }
            }
            else
            {
                sPointer uncle  =   target->parent.lock()->parent.lock()->left;
                if(uncle->color ==  Color::Red)
                {
                    uncle->color = Color::Black;
                    target->parent.lock()->color = Color::Black;
                    target->parent.lock()->parent.lock()->color = Color::Red;
                }
                else
                {
                    if(target   ==  target->parent.lock()->left)
                    {
                        target  =   target->parent.lock();
                        right_rotate(target);
                    }
                    target->parent.lock()->color                =   Color::Black;
                    target->parent.lock()->parent.lock()->color =   Color::Red;
                    left_rotate(target->parent.lock()->parent.lock());
                }
            }
        }
    }
};

}//namespace ch13
#endif // REDBLACKTREE_H
