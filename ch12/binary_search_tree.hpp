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

//! ex 12.1-3
//! Give a nonrecursive algorithm that performs an inorder tree walk. (Hint: An easy
//! solution uses a stack as an auxiliary data structure. A more complicated, but ele-
//! gant, solution uses no stack but assumes that we can test two pointers for equality.)
//!
//!     inorder_walk_nonrecur_with_stack(node)
/*      if(node)
 *          def stack
 *          while(node || !stack.empty())
 *              while(node)
 *                  stack.push(node)
 *                  node = node->left
 *              if(!stack.empty())
 *                  node = stack.pop()
 *                  node.print()
 *                  node = node->right
 */
//! based on ch10::tree::binary_tree::checking _prev_print
//! can be found here:
//! https://github.com/Mooophy/CLRS/blob/master/ch10/tree.hpp
//!
//!     inorder_walk_by_checking_prev(node)
/*      def prev = null
 *      def curr = node
 *      while(curr)
 *
 *          if(!curr->left  ||  prev == curr->left)     //  for printing
 *              curr->print
 *
 *          if(prev == curr->parent)
 *              prev    =   curr
 *              curr    =   curr->left? left    :
 *                          curr->right?    curr->right :   curr->parent
 *          else if (prev == left && curr->right)
 *              prev    =   curr
 *              curr    =   curr->right
 *          else
 *              prev    =   curr
 *              curr    =   curr->parent
 */

//! ex12.1-4
//! Give recursive algorithms that perform preorder and postorder tree walks in
//! O(n) time on a tree of n nodes.

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "node.hpp"
#include <stack>

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

    /**
     * @brief inorder_print_nonrecur
     *
     * for ex12.1-3
     */
    void inorder_print_nonrecur()const
    {
        sPointer prev = nullptr;
        sPointer curr = root;
        while(curr)
        {
            //! print
            if(!curr->left  ||  prev==curr->left)
                curr->print();

            //! move curr to next node.
            if(prev == curr->parent.lock())
            {
                prev    =   curr;
                curr    =   curr->left?    curr->left   :
                            curr->right?   curr->right  :   curr->parent.lock();
            }
            else if(prev == curr->left && curr->right)
            {
                prev    =   curr;
                curr    =   curr->right;
            }
            else
            {
                prev    =   curr;
                curr    =   curr->parent.lock();
            }
        }

    }

    /**
     * @brief inoder_print_nonrecur_with_stack
     *
     * i.e. the interface for inorder_tree_walk_nonrecur_with_stack
     */
    void inoder_print_nonrecur_with_stack()const
    {
        inorder_tree_walk_nonrecur_with_stack(root);
    }

    /**
     * @brief preorder_print
     */
    void preorder_print()const
    {
        preorder_tree_walk(root);
    }

    /**
     * @brief postorder_print
     */
    void postorder_print()const
    {
        postorder_tree_walk(root);
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

    /**
     * @brief inorder_tree_walk_nonrecur_with_stack
     * @param node
     *
     * for ex 12-1.2
     */
    void inorder_tree_walk_nonrecur_with_stack(sPointer node)const
    {
        if(node)
        {
            std::stack<sPointer> stk;
            while(node  ||  !stk.empty())
            {
                while(node)
                {
                    stk.push(node);
                    node    =   node->left;
                }
                if(!stk.empty())
                {
                    node    =   stk.top();
                    stk.pop();
                    node->print();
                    node    =   node->right;
                }
            }
        }
    }

    /**
     * @brief preorder_tree_walk
     */
    void preorder_tree_walk(sPointer node) const
    {
        if(node)
        {
            node->print();
            inorder_tree_walk(node->left);
            inorder_tree_walk(node->right);
        }
    }

    /**
     * @brief postorder_tree_walk
     */
    void postorder_tree_walk(sPointer node)const
    {
        if(node)
        {
            inorder_tree_walk(node->left);
            inorder_tree_walk(node->right);
            node->print();
        }
    }
};//class binary_search_tree

}//namespace ch12


#endif // BINARY_SEARCH_TREE_H

//! test code for inorder tree walk, ex12.1-3 and ex12.1-4
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
//    tree.inoder_print_nonrecur_with_stack();
//    tree.inorder_print_nonrecur();

//    tree.preorder_print();
//    tree.postorder_print();
//
//    return 0;
//}
