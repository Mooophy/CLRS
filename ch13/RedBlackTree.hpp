/***************************************************************************
 *  @file       RedBlackTree.hpp
 *  @author     Yue Wang
 *  @date       02  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.hpp"

namespace ch13{

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
        if(target->parent   ==  this->nil)
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

};

}//namespace ch13
#endif // REDBLACKTREE_H
