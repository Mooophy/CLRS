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
    using SizeType  = std::size_t;

    /**
     * @brief default ctor
     */
    circular_list():
        keeper(std::make_shared<Node>(12345))
    {
        keeper->prev   =   keeper->next   =   keeper;
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

        inserted->next      =   keeper->next;
        keeper->next->prev  =   inserted;
        keeper->next        =   inserted;
        inserted->prev      =   keeper;
    }

    /**
     * @brief remove
     *
     * @complexity  O(1)
     *
     * implementation for LIST-DELETE' page 238
     */
    void remove(sPointer target) const
    {
        assert(target != keeper);
        target->prev.lock()->next   =   target->next;
        target->next->prev          =   target->prev;
    }

    /**
     * @brief search
     *
     * @complexity  O(n)
     *
     * implementation for LIST-SEARCH' page 239
     */
    sPointer search(const ValueType& val) const
    {
        sPointer ptr = keeper->next;
        while(ptr != keeper && ptr->key != val)
            ptr = ptr->next;

        return ptr;
    }

    /**
     * @brief empty
     */
    bool empty() const
    {
        return keeper->next == keeper;
    }

    /**
     * @brief size
     */
    SizeType size() const
    {
        SizeType size = 0;
        sPointer ptr = keeper;
        while(ptr->next != keeper)
        {
            ++size;
            ptr = keeper->next;
        }
        return size;
    }


private:

    /**
     * @brief keeper
     *
     * used as a dummy sentinel on the list
     */
    sPointer keeper;
};

}//namespace list
}//namespace ch10

#endif // CIRCULAR_LIST_HPP
