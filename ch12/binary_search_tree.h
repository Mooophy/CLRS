/***************************************************************************
 *  @file       binary_search_tree.hpp
 *  @author     Alan.W
 *  @date       24  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/
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
     * @brief insert interface
     *
     * @complexity  O(lg n)
     */
    void insert(const KeyType& key, const DataType& data)
    {
        sPointer inserted = std::make_shared<Node>(key,data);
        recur_add(root, inserted);
    }

private:
    sPointer root;

    /**
     * @brief recur_add
     *
     * @complexity  O(lg n)
     */
    void recur_add(sPointer& curr,const sPointer& added, sPointer prev = nullptr)
    {
        if(!curr)
        {
            curr            =   added;
            curr->parent    =   prev;
        }
        else
        {
            if(added->key   <   curr->key)
                recur_add(curr->left,   added,  curr);
            else
                recur_add(curr->right,  added,  curr);
        }
    }
};

}//namespace ch12


#endif // BINARY_SEARCH_TREE_H
