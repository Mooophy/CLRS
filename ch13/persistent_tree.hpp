/***************************************************************************
 *  @file       redblacktree.hpp
 *  @author     Yue Wang
 *  @date       09  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
//!
//! Problem
//! 13-1 Persistent dynamic sets
//! During the course of an algorithm, we sometimes find that we need to maintain past
//! versions of a dynamic set as it is updated. We call such a set persistent. One way to
//! implement a persistent set is to copy the entire set whenever it is modified, but this
//! approach can slow down a program and also consume much space. Sometimes, we
//! can do much better.
//! Consider a persistent set S with the operations I NSERT , D ELETE , and S EARCH ,
//! which we implement using binary search trees as shown in Figure 13.8(a). We
//! maintain a separate root for every version of the set. In order to insert the key 5
//! into the set, we create a new node with key 5. This node becomes the left child
//! of a new node with key 7, since we cannot modify the existing node with key 7.
//! Similarly, the new node with key 7 becomes the left child of a new node with
//! key 8 whose right child is the existing node with key 10. The new node with key 8
//! becomes, in turn, the right child of a new root r 0 with key 4 whose left child is the
//! existing node with key 3. We thus copy only part of the tree and share some of the
//! nodes with the original tree, as shown in Figure 13.8(b).
//! Assume that each tree node has the attributes key, left, and right but no parent.
//! (See also Exercise 13.3-6.)
//!
//! a. For a general persistent binary search tree, identify the nodes that we need to
//! change to insert a key k or delete a node y
//  For k, nodes on the path to search for it need to be changed.
//  For y, when less than 2 children, same as k. when 2 children nodes on path to search
//  for y's replacer need to be changed.
//!
//! b. Write a procedure P ERSISTENT -T REE -I NSERT that, given a persistent tree T
//! and a key k to insert, returns a new persistent tree T 0 that is the result of insert-
//! ing k into T .
//!
//  Shown as the class PersistentTree below
//!

#ifndef PERSISTENT_TREE_HPP
#define PERSISTENT_TREE_HPP

#include "node.hpp"
#include <vector>

namespace ch13 {

template<typename K, typename D>
class PersistentTree
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using NodeType  =   Node<K,D>;
    using sPointer  =   std::shared_ptr<NodeType>;
    using wPointer  =   std::weak_ptr<NodeType>;
    using Vector    =   std::vector<sPointer>;

    /**
     * @brief insert
     * @param key
     * @param data
     *
     * @complx  O(lg n)
     * overloaded as an interface
     */
    void insert(const KeyType &key, const DataType &data)
    {
        sPointer added = std::make_shared<NodeType>(key,data);
        insert(added);
    }

    /**
     * @brief insert
     * @param key
     *
     * @complx  O(lg n)
     * overloaded as an interface
     */
    void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    bool empty()const
    {
        return versions.empty();
    }


private:
    Vector  versions;

    /**
     * @brief insert
     * @param added
     *
     * @complx  O(lg n)
     *
     * @page    332 ,   i.e. Problem 13-1.b
     */
    void insert(sPointer added)
    {
        if(versions.empty())
            versions.push_back(added);
        else
        {
            sPointer old_curr = versions.back();
            sPointer new_root = std::make_shared<NodeType>(*versions.back());
            versions.push_back(new_root);
            sPointer new_curr = new_root;

            while(true)
            {
                if(old_curr->key    <   added->key)
                {
                    new_curr->left  =   old_curr->left;
                    if(old_curr->right)
                    {
                        new_curr->right =
                                std::make_shared<NodeType>(*old_curr->right);
                        new_curr    =   new_curr->right;
                        old_curr    =   old_curr->right;
                    }
                    else
                        break;
                }
                else
                {
                    new_curr->right =   old_curr->right;
                    if(old_curr->left)
                    {
                        new_curr->left  =
                                std::make_shared<NodeType>(*old_curr->left);
                        new_curr    =   new_curr->left;
                        old_curr    =   old_curr->right;
                    }
                    else
                        break;
                }
            }

            //! graft on the inserted node
            (new_curr->key < added->key?   new_curr->left  :   new_curr->right)
                    =   added;
        }
    }
};

}//namespace















#endif // PERSISTENT_TREE_HPP
