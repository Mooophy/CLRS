/***************************************************************************
 *  @file       single_list.hpp
 *  @author     Alan.W
 *  @date       30  May 2014
 *  @remark     Chapter 10, Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

//!
//! ex10.2-1
//! Can you implement the dynamic-set operation INSERT on a singly linked list
//! in O(1) time? How about DELETE ?
//!
//  As shown below, INSERT on a singly linked list in O(1) is able to
//  implment, but DELETE in O(1) is not.The reason is that prev which is not provided
//  needs O(n) time to find.
//!

#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H

#include <list.hpp>

namespace ch10 {
namespace list {

/**
 * @brief  singly linked circular list
 */
template<typename T>
class single_list_ring
{
public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using SizeType  = std::size_t;

    /**
     * @brief default ctor
     */
    single_list_ring():
       count(0), nil(std::make_shared<Node>(12345))
    {
        nil->next   =   nil;
    }

    /**
     * @brief search
     *
     * @complexity  O(n)
     */
    sPointer search(const ValueType& val) const
    {
        sPointer ptr = nil->next;
        while(ptr != nil && ptr->key != val)
            ptr = ptr->next;

        return ptr;
    }

    /**
     * @brief insert
     *
     * @complexity O(1)
     *
     *
     * example: insert(3)
     * before inserting:    [nil][7][8][9]
     *                            ^
     *                            begin
     * after inserting:     [nil][3][7][8][9]
     *                            ^
     *                            begin
     *
     *
     * as ex10.2-1 required.
     */
    void insert(const ValueType& val)
    {
        sPointer inserted   =   std::make_shared<Node>(val);
        inserted->next      =   nil->next;
        nil->next           =   inserted;

        ++count;
    }

    /**
     * @brief remove
     *
     * @param target    shared pointer
     *
     * @complexity  O(n)
     *
     * check ex10.2-1 for detail.
     */
    void remove(sPointer target)
    {
        assert(target != nil && !empty());
        prev(target)->next    =   target->next;

        --count;
    }

    /**
     * @brief size
     *
     * @complexity  O(1)
     */
    SizeType size() const
    {
        return count;
    }

    /**
     * @brief empty
     */
    bool empty() const
    {
        return begin() == end();
    }

    /**
     * @brief begin
     */
    const sPointer& begin() const
    {
        return nil->next;
    }

    /**
     * @brief end
     */
    const sPointer& end() const
    {
        return nil;
    }

private:

    /**
     * @brief size counter
     */
    SizeType count;

    /**
     * @brief nil
     *
     * used as a dummy sentinel on the list
     */
    sPointer nil;

    /**
     * @brief search and return the predecessor of target
     */
    sPointer prev(sPointer target) const
    {
        sPointer ptr = nil;
        while(ptr->next != target)
            ptr = ptr->next;

        return  ptr;
    }
};

template<typename T>
std::ostream& operator <<(std::ostream& os, const single_list_ring<T>& l)
{
    auto ptr = l.begin();
    while (ptr != l.end())
    {
        os << ptr->key << std::endl;
        ptr = ptr->next;
    }
    return os;
}

}//namespace list
}//namespace ch10
#endif // SINGLE_LIST_H
