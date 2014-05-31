/***************************************************************************
 *  @file       stack_by_list.hpp
 *  @author     Alan.W
 *  @date       30  May 2014
 *  @remark     Chapter 10, Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

//!
//! ex10.2-2
//! Implement a stack using a singly linked list L. The operations PUSH and POP
//! should still take O(1) time.
//!

#ifndef STACK_BY_LIST_H
#define STACK_BY_LIST_H

#include "single_list.hpp"

namespace ch10{
namespace list{

template<typename T>
class stack_by_list
{
public:
    using ValueType =   T;
    using Node      =   node<ValueType>;
    using sPointer  =   std::shared_ptr<Node>;
    using SizeType  =   std::size_t;
    using List      =   ch10::list::single_list<ValueType>;

    stack_by_list() = default;

    SizeType size() const
    {
        return list.size();
    }

private:
    List list;
};


}//namespace list
}//namespace ch10

#endif // STACK_BY_LIST_H
