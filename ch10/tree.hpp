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

template<typename T>
struct node
{
    using ValueType =   T;
    using Node      =   node<ValueType>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;

    wPointer parent;
    sPointer left;
    sPointer right;
};

template<typename T>
class B_tree
{
public:
    using ValueType =   T;
    using Node      =   node<ValueType>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;


private:
    sPointer root;
};

}//namespace tree
}//namespace ch10

#endif // TREE_HPP
