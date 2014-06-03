/***************************************************************************
 *  @file       queue_by_2stacks.hpp
 *  @author     Alan.W
 *  @date       2   Jun 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 *  @attention  bug found, check issue #2 for detail.
 ***************************************************************************/

#ifndef TREE_HPP
#define TREE_HPP

#include <memory>

namespace ch10 {
namespace tree {

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
class B_tree
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

}//namespace tree
}//namespace ch10

#endif // TREE_HPP
