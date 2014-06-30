/***************************************************************************
 *  @file       binary_search_tree_succ.hpp
 *  @author     Alan.W
 *  @date       26  June 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
//!
//! 12.3-5
//! Suppose that instead of each node x keeping the attribute x.p, pointing to x’s
//! parent, it keeps x.succ, pointing to x’s successor. Give pseudocode for SEARCH ,
//! INSERT , and DELETE on a binary search tree T using this representation. These
//! procedures should operate in time O(h), where h is the height of the tree T .
//! (Hint:You may wish to implement a subroutine that returns the parent of a node.)
//!
//  Note:   1.Predecessor and successor ,if not nil, must be ancestors of new node.
//          2.Along the path downwared, Predecessor should be the last node with a
//            key less than that of the new node, whereas successor the last one with
//            greater key than new node.
//          3.This can be found from the pseudo codes for predcessor and successor in
//            this chapter.
//
/*      insert(inserted)    //O(h)
 * 1    def parent, predecessor, successor
 * 2    def curr = root
 * 3    while(curr)
 * 4        parent = curr
 * 5        if(inserted->key < curr->key)
 * 6            successor = curr
 * 7            curr = curr->left
 * 8        else
 *              predecessor = curr
 * 9            curr = curr->right
 * 10   if(!parent)
 * 11       root    =   inserted
 * 12   else
            (inserted->key < parent->key?   parent->left    :   parent->right)
                    =   inserted;
 * 13   inserted->sucessor = successor
 * 14   if(predecessor)
 * 15       predecessor->successor = inserted
 */

/*      search(key)
 * 1    def curr = root
 * 2    while(curr  && key != curr->key)
 * 3        curr = (key < curr->key?    curr->left  :   curr->right)
 * 4    return curr
 */

#ifndef BINARY_SEARCH_TREE_SUCC_HPP
#define BINARY_SEARCH_TREE_SUCC_HPP

#include "node.hpp"
#include <memory>
#include <assert.h>

namespace ch12 {

/**
 * @brief binary_search_tree_succ
 *
 * for ex12.3-5, using node with successor
 */
template<typename K, typename D>
class binary_search_tree_succ
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using Node      =   node<K,D>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;

    /**
     * @brief insert
     * @param key
     * @param data
     *
     * @complexity  O(h)
     */
    void insert(const KeyType& key, const DataType& data)
    {
        sPointer inserted = std::make_shared<Node>(key, data);
        insert(inserted);
    }

    /**
     * @brief insert
     * @param inserted node
     *
     * @complexity  O(h)
     */
    void insert(sPointer inserted)
    {
        //! find all
        sPointer parent, predecessor, successor;
        sPointer curr = root;
        while(curr)
        {
            parent = curr;
            if(inserted->key    <   curr->key)
            {
                successor   =   curr;
                curr        =   curr->left;
            }
            else
            {
                predecessor =   curr;
                curr        =   curr->right;
            }
        }

        //! graft on the inserted node.
        if(!parent)
            root    =   inserted;
        else
            (inserted->key < parent->key?   parent->left    :   parent->right)
                    =   inserted;

        //! maintain successor and predecessor's successor
        inserted->successor         =   successor;
        if(predecessor)
            predecessor->successor  =   inserted;
    }

    /**
     * @brief search
     * @param key
     *
     * @complexity  O(h)=O(lg n)
     */
    sPointer search(const KeyType& key)const
    {
        sPointer curr = root;
        while(curr && key != curr->key)
            curr    =   key<curr->key?  curr->left  :   curr->right;
        return curr;
    }

    /**
     * @brief inorder_print
     *
     * @complexity  O(n)
     *
     * i.e. the interface for inorder_print.
     */
    void inorder_print()const
    {
        inorder_tree_walk(root);
    }

    /**
     * @brief maximum
     * @param node
     *
     * @complexity
     */
    sPointer maximum(sPointer node)const
    {
        assert(node);
        while(node->left)
            node    =   node->left;
        return node;
    }


    /**
     * @brief maximum
     * @param node
     *
     * @complexity  O(h) = O(lg n)
     */
    sPointer minimum(sPointer node)const
    {
        assert(node);
        while(node->right)
            node    =   node->right;
        return node;
    }

    /**
     * @brief predessor
     * @param node
     *
     * @complexity  O(h) = O(lg n)
     */
    sPointer predessor(sPointer node)const
    {
        if(node->left)
            return maximum(node->left);
        else
        {
            sPointer curr = root;
            sPointer pred = nullptr;
            while(curr && curr->key != node->key)
            {
                if(curr->key > node->key)
                    curr    =   curr->left;
                else
                {
                    pred    =   curr;
                    curr    =   curr->right;
                }
            }
            return pred;
        }
    }

    /**
     * @brief parent
     * @param target
     *
     * @complexity  O(n)
     */
    sPointer parent(sPointer target)const
    {
        sPointer curr = root;
        sPointer tracker = nullptr;
        while(curr && curr->key != target->key)
        {
            tracker =   curr;
            curr    =   target->key < curr->key?    curr->left  :   curr->right;
        }
        return tracker;
    }

private:
    sPointer root;

    /**
     * @brief inorder_tree_walk
     * @param node
     *
     * @complexity  O(n)
     */
    void inorder_tree_walk(sPointer node)const
    {
        if(node)
        {
            inorder_tree_walk(node->left);
            node->print();
            inorder_tree_walk(node->right);
        }
    }
};

}//namespace ch12

#endif // BINARY_SEARCH_TREE_SUCC_HPP

//#include <iostream>
//#include <string>
//#include "binary_search_tree_succ.hpp"

//int main()
//{
//    ch12::binary_search_tree_succ<int,std::string> tree;

//    tree.insert(1,"001");
//    tree.insert(9,"009");
//    tree.insert(99,"099");
//    tree.insert(5,"005");

//! for testing inorder tree walk, i.e. print in sorted order
//    tree.inorder_print();

//! for testing search()
//    tree.search(99)->print();

//! for testing predessor()
//    tree.predessor(tree.search(5))->print();

//! for testing parent
//    tree.parent(tree.search(0))->print();


//    return 0;
//}
