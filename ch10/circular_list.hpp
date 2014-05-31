/***************************************************************************
 *  @file       circular_list.hpp
 *  @author     Alan.W
 *  @date       28  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! 10.2-4
//! As written, each loop iteration in the LIST-SEARCH procedure requires two tests:
//! one for x != L.nil and one for x->key != k. Show how to eliminate the test for
//! x ! L.nil in each iteration.
//!
//  as shown below.
//!

#ifndef CIRCULAR_LIST_HPP
#define CIRCULAR_LIST_HPP

#include <memory>
#include <iostream>
#include <assert.h>
#include "list.hpp"

namespace ch10 {
namespace list {

/**
 * @brief doubly linked, circular list
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
        nil(std::make_shared<Node>(12345)),count(0)
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
    void insert(const ValueType& val)
    {
        sPointer inserted = std::make_shared<Node>(val);

        inserted->next      =   nil->next;
        nil->next->prev     =   inserted;
        nil->next           =   inserted;
        inserted->prev      =   nil;

        ++count;
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
        assert(target != nil);
        target->prev.lock()->next   =   target->next;
        target->next->prev          =   target->prev;

        --count;
    }

    /**
     * @brief search
     *
     * @complexity  O(n)
     *
     * implementation for LIST-SEARCH' page 239
     *
     * revised as required in ex10-2.4
     */
    sPointer search(const ValueType& val)
    {
        sPointer ptr =  nil->next;
        nil->key     =  val;        //added for ex10.2-4, 31 may, 2014 @alan
        while(ptr->key != val)
            ptr = ptr->next;

        return ptr;
    }

    /**
     * @brief empty
     */
    bool empty() const
    {
        return nil->next == nil;
    }

    /**
     * @brief size
     */
    SizeType size() const
    {
        return count;
    }


private:

    /**
     * @brief nil
     *
     * used as a dummy sentinel on the list
     */
    sPointer nil;

    /**
     * @brief count for size
     */
    SizeType count;
};

}//namespace list
}//namespace ch10

#endif // CIRCULAR_LIST_HPP


//! test code for ex10.2-4
//#include <iostream>
//#include "circular_list.hpp"

//int main()
//{
//    ch10::list::circular_list<int> l;
//    l.insert(1);
//    l.insert(222);

//    std::cout << l.search(223)->key << std::endl;

//    return 0;
//}
