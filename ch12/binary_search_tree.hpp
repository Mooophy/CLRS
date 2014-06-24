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

//! page 288
//! INORDER-TREE-WALK(x)
//1 if x != NIL
//2     INORDER-TREE-WALK(x.left)
//3     print x.key
//4     INORDER-TREE-WALK(x.right)

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

    /**
     * @brief inorder_print
     *
     * i.e. the interface for inorder_print.
     */
    void inorder_print()const
    {
        inorder_tree_walk(root);
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
};//class binary_search_tree

}//namespace ch12


#endif // BINARY_SEARCH_TREE_H

//! test code for inorder tree walk
//#include <iostream>
//#include <string>
//#include "node.hpp"
//#include "binary_search_tree.hpp"

//int main()
//{
//    ch12::binary_search_tree<int, std::string> tree;

//    tree.insert(1,"001");
//    tree.insert(2,"002");
//    tree.insert(5,"005");

//    tree.inorder_print();

//    return 0;
//}
