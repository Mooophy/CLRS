/***************************************************************************
 *  @file       queue_by_2stacks.hpp
 *  @author     Alan.W
 *  @date       2   Jun 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 *  @attention  bug found, check issue #2 for detail.
 ***************************************************************************/
//!
//! ex 10.4-2
//! Write an O(n)-time recursive procedure that, given an n-node binary tree, prints
//! out the key of each node in the tree.
//!
/*      print_recur(Node* node)
 * 1    if(node != null)
 * 2        cout << node->data << endl
 * 3        print_recur(node->left)
 * 4        print_recur(node->right)
 */

//!
//! ex10.4-3
//! Write an O(n)-time nonrecursive procedure that, given an n-node binary tree,
//! prints out the key of each node in the tree. Use a stack as an auxiliary data structure.
//!
/*      print_with_stack(node)
 * 1    if(node)
 * 2        def stack
 * 3        stack.push(node)
 * 4        def current = null
 * 5        while( ! stack.empty())
 * 6            current = stack.pop()
 * 7            cout << current->key
 * 8            if (current->left)
 * 9                stack.push(current->left)
 * 10           if (current->right)
 * 11               stack.push(current->right)
 */

#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>

namespace ch10 {
namespace tree {

template<typename T>
struct node;

template<typename T>
class binary_tree;



/**
 * @brief node
 *
 * used for binary tree.
 */
template<typename T>
struct node
{
    using ValueType =   T;
    using Node      =   node<ValueType>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;

    /**
     * @brief default ctor
     */
    node() = default;

    /**
     * @brief ctor with a key
     */
    explicit node(const ValueType& val):
        key(val)
    {}

    ValueType   key     = ValueType();
    wPointer    parent;
    sPointer    left    = nullptr;
    sPointer    right   = nullptr;
};

/**
 * @brief binary tree
 */
template<typename T>
class binary_tree
{
public:
    using ValueType =   T;
    using Node      =   node<ValueType>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;

    /**
     * @brief insert interface
     */
    void insert(const ValueType& val)
    {
        recur_add(root, val);
    }

    void print_by_recursion() const
    {
        recur_print(root);
    }

private:
    sPointer root;

    /**
     * @brief recur_add
     *
     * actual work for insert interface
     */
    void recur_add(sPointer& ptr, const ValueType& val)
    {
        if(ptr == nullptr)
        {
            ptr = std::make_shared<Node>(val);
            return;
        }
        else
        {
            if(ptr->key > val)
                recur_add(ptr->left  , val);
            else
                recur_add(ptr->right , val);
        }
    }

    /**
     * @brief recur_print
     *
     * @complexity O(n)
     *
     * implemented for ex10.4-2
     */
    void recur_print(sPointer node) const
    {
        if(node != nullptr)
        {
            std::cout << node->key << std::endl;
            recur_print(node->left);
            recur_print(node->right);
        }
    }
};

}//namespace tree
}//namespace ch10

#endif // TREE_HPP

//! test code for ex10.4-2
//#include <iostream>
//#include "tree.hpp"

//int main()
//{
//    ch10::tree::node<int> n;
//    ch10::tree::binary_tree<int> tree;

//    for(int i=0; i != 100; ++i)
//        tree.insert(i);

//    tree.print_by_recursion();
//}
