/***************************************************************************
 *  @file       single_list.hpp
 *  @author     Alan.W
 *  @date       30  May 2014
 *  @remark     Chapter 10, Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! related part
//!
//! ex10.2-1
//! Can you implement the dynamic-set operation INSERT on a singly linked list
//! in O(1) time? How about DELETE ?
//!
//  As shown in the following, INSERT on a singly linked list in O(1) is able to
//  implment,   but DELETE in O(1) is not.The reason is that prev is not provided
//  and required O(n) time to find prev.
//!

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include <list.hpp>

namespace ch10 {
namespace list {

template<typename T>
class single_list
{

public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using SizeType  = std::size_t;

    /**
     * @brief default ctor
     */
    single_list():
        nil(std::make_shared<Node>(12345))
    {
        nil->next   =   nil;
    }

    /**
     * @brief insert
     *
     * @complexity O(1)
     *
     * as ex10.2-1 required.
     */
    void insert(const ValueType& val) const
    {
        sPointer inserted   =   std::make_shared<Node>(val);
        inserted->next      =   nil->next;
        nil->next           =   inserted;
    }

private:

    /**
     * @brief nil
     *
     * used as a dummy sentinel on the list
     */
    sPointer nil;
};


}//namespace list
}//namespace ch10
#endif // SINGLE_LIST_H
