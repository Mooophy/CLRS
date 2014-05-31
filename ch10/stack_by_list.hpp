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
    using List      =   single_list_ring<ValueType>;

    /**
     * @brief default ctor
     */
    stack_by_list() = default;

    SizeType size() const
    {
        return data.size();
    }

    bool empty() const
    {
        return data.empty();
    }

    void print() const
    {
        std::cout << data;
    }

    /**
     * @brief enqueue
     *
     * @complexity  O(1)
     *
     * as required in ex10.2-2
     */
    void enqueue(const ValueType& val)
    {
        data.insert(val);
    }

    /**
     * @brief dequeue
     *
     * @complexity  O(1)
     *
     * as required in ex10.2-2
     */
    ValueType dequeue()
    {
        ValueType top = data.begin()->key;
        data.remove(data.begin());

        return top;
    }
private:
    List data;
};


}//namespace list
}//namespace ch10

#endif // STACK_BY_LIST_H

