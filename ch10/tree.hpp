/***************************************************************************
 *  @file       queue_by_2stacks.hpp
 *  @author     Alan.W
 *  @date       2   Jun 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
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
//! ex 10.4-3
//! Write an O(n)-time nonrecursive procedure that, given an n-node binary tree,
//! prints out the key of each node in the tree. Use a stack as an auxiliary data structure.
//!
/*      print_with_stack(node)
 * 1    if(node)
 * 2        def stack
 * 3        stack.push(node)
 * 4        while( ! stack.empty())
 * 5            def current = stack.pop()
 * 6            cout << current->key
 * 7            if (current->left)
 * 8                stack.push(current->left)
 * 9            if (current->right)
 * 10               stack.push(current->right)
 */

//!
//! ex 10.4-4
//! Write an O(n)time procedure that prints all the keys of an arbitrary rooted tree
//! with n nodes, where the tree is stored using the left-child, right-sibling representa-
//! tion.
//!
/*      print(node)
 * 1    if(node)
 * 2        cout << node->key
 * 3        print(node->left)
 * 4        print(node->right)
 */

//!
//! ex 10.4-5 *
//! Write an O(n)-time nonrecursive procedure that, given an n-node binary tree,
//! prints out the key of each node. Use no more than constant extra space outside
//! of the tree itself and do not modify the tree, even temporarily, during the proce-
//! dure.
//!
/*      print_with_prev(node)
 * 1    def prev = null
 * 2    def current = node
 * 3    while(current)
 * 4        if(prev == current->parent)
 * 5            cout << current->key
 * 6            prev = current
 * 7            current =   current->left?    current->left   :
 *                              current->right? current->right  :   current->parent
 * 8        else if (prev == current->left && current->right)
 * 9            prev = current
 * 10           current = current->right
 * 11       else
 *              prev = current
 * 12           current = current->parent
 */


#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include <iostream>
#include <stack.hpp>

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

    /**
     * @brief print_by_recursion
     *
     * just an interface,check recur_print() for real work.
     */
    void print_by_recursion() const
    {
        recur_print(root);
    }

    /**
     * @brief print_with_stack
     *
     * just an interface, check recur_print() for real work.
     */
    void print_with_stack() const
    {
        nonrecur_print(root);
    }

    /**
     * @brief print_with_prev
     *
     * just an interface, checking_prev_print() for real work.
     */
    void print_with_prev() const
    {
        checking_prev_print(root);
    }


private:
    sPointer root;

    /**
     * @brief recur_add
     *
     * actual work for insert interface
     */
    void recur_add(sPointer& current, const ValueType& val, sPointer prev = nullptr)
    {
        if(current == nullptr)
        {
            current = std::make_shared<Node>(val);
            current->parent = prev;
            return;
        }
        else
        {
            if(current->key > val)
                recur_add(current->left  , val, current);
            else
                recur_add(current->right , val, current);
        }
    }

    /**
     * @brief recur_print
     *
     * @complexity O(n)
     *
     * implemented for ex10.4-2
     * check above for pseudocode, below for test code.
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

    /**
     * @brief nonrecur_print
     *
     * @complexity  O(n)
     *
     * implemented for ex10.4-3
     * check above for pseudocode, below for test code.
     */
    void nonrecur_print(sPointer node) const
    {
        if(node)
        {
            ch10::stack<sPointer> stack;
            stack.push(node);
            while(!stack.empty())
            {
                sPointer current = stack.top();
                stack.pop();
                std::cout << current->key << std::endl;

                if(current->left)
                    stack.push(current->left);
                if(current->right)
                    stack.push(current->right);
            }
        }
    }

    /**
     * @brief checking_prev_print
     *
     * @complexity  O(2n) = O(n)
     *
     * for ex10.4-5 *
     * check above for pseudocode, below for test code.
     */
    void checking_prev_print(sPointer node) const
    {
        sPointer prev    = nullptr;
        sPointer current = node;

        while(current)
        {
            if(prev == current->parent.lock())
            {
                std::cout << current->key << std::endl;
                prev = current;

                current = current->left?    current->left :
                    current->right? current->right  :   current->parent.lock();
            }
            else if(prev == current->left && current->right)
            {
                prev = current;
                current = current->right;
            }
            else
            {
                prev = current;
                current = current->parent.lock();
            }
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

//! test code for ex10.4-3
//#include <iostream>
//#include "tree.hpp"

//int main()
//{
//    ch10::tree::binary_tree<int> tree;

//    for(int i=0; i != 100; ++i)
//        tree.insert(i);
//    tree.print_with_stack();
//}

//! test code for ex10.4-5
//#include <iostream>
//#include "tree.hpp"

//int main()
//{
//    ch10::tree::binary_tree<int> tree;

//    for(int i=50; i != 100; ++i)
//        tree.insert(i);

//    tree.print_with_prev();
//}
