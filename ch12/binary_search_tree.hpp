/***************************************************************************
 *  @file       binary_search_tree.hpp
 *  @author     Alan.W
 *  @date       24  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/
//!     page 294
//!     tree-insert(T,z)
/* 1    y = nil
 * 2    x = T.root
 * 3    whie x != nil
 * 4        y = x
 * 5        if z.key < x.key
 * 6            x = x.left
 * 7        else
 *              x = x.right
 * 8    z.parent = y
 * 9    if y == nil
 * 10       T.root = z  //i.e. was empty
 * 11   elseif z.key <y.key
 * 12       y.left = z
 * 13   else    y.right = z
 */

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "node.hpp"

namespace ch12 {

/**
 * @brief binary search tree
 */
template<typename K, typename D>
class binary_search_tree
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
     * @complexity  O(lg n)
     */
    void insert(const KeyType& key, const DataType& data)
    {
        sPointer inserted = std::make_shared<Node>(key, data);
        insert(inserted);
    }

    /**
     * @brief insert
     * @param inserted  i.e. the new node
     *
     * @complexity  O(lg n)
     */
    void insert(sPointer inserted)
    {
        sPointer last = nullptr;
        sPointer curr = root;

        //! find the appropiate position
        while(curr)
        {
            last = curr;
            curr = (inserted->key < curr->key)?  curr->left  :  curr->right;
        }

        //! graft on the inserted.
        inserted->parent    =   last;
        if(!last)
            root = inserted;
        else if(inserted->key   <   last->key)
            last->left      =   inserted;
        else
            last->right     =   inserted;
    }

private:
    sPointer root;
};//class binary_search_tree

}//namespace ch12


#endif // BINARY_SEARCH_TREE_H
