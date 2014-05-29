/***************************************************************************
 *  @file       circular_list.hpp
 *  @author     Alan.W
 *  @date       28  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
#ifndef CIRCULAR_LIST_HPP
#define CIRCULAR_LIST_HPP

#include <memory>
#include <iostream>
#include <assert.h>
#include "list.hpp"

namespace ch10 {
namespace list {

/**
 * @brief circular_list
 *
 * sentinel is used to build this doubly linked list circle,
 * check page 238 - 240 for detail.
 */
template<typename T>
class circular_list
{
public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;

    /**
     * @brief default ctor
     */
    circular_list():
        nil(std::make_shared<Node>(12345))
    {
        nil->prev   =   nil->next   =   nil;
    }

    /**
     * @brief insert
     *
     * @complexity O(1)
     *
     * check LIST-INSERT' page 240 for detail
     */
    void insert(const ValueType& val) const
    {
        sPointer inserted = std::make_shared<Node>(val);

        inserted->next  = nil->next;
        nil->next->prev = inserted;
        nil->next       = inserted;
        inserted->prev  = nil;
    }

private:
    sPointer nil;

};
}//namespace list
}//namespace ch10



#endif // CIRCULAR_LIST_HPP
