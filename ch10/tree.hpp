/***************************************************************************
 *  @file       queue_by_2stacks.hpp
 *  @author     Alan.W
 *  @date       2   Jun 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 *  @attention  bug found, check issue #2 for detail.
 ***************************************************************************/
//! 10.4-2
//! Write an O(n)-time recursive procedure that, given an n-node binary tree, prints
//! out the key of each node in the tree.
//!
/*      print_recur(Node* node)
 * 1    if(node != null)
 * 2        cout << node->data << endl
 * 3        print_recur(node->left)
 * 4        print_recur(node->right)
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

template<typename T>
void recur_print(std::shared_ptr<node<T>> node);

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
    friend void recur_print<T>(std::shared_ptr<node<T>> node);
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
};

/**
 * @brief recur_print
 *
 * @complexity O(n)
 *
 * implemented for ex10.4-2
 */
template<typename T>
inline void recur_print(std::shared_ptr<node<T>> node)
{
    if(node != nullptr)
    {
        std::cout << node->key << std::endl;
        recur_print(node->left);
        recur_print(node->right);
    }
}

}//namespace tree
}//namespace ch10

#endif // TREE_HPP
