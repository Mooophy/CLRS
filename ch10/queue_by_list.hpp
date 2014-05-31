/***************************************************************************
 *  @file       stack_by_list.hpp
 *  @author     Alan.W
 *  @date       30  May 2014
 *  @remark     Chapter 10, Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! 10.2-3
//! Implement a queue by a singly linked list L. The operations ENQUEUE and DE-
//! QUEUE should still take O(1) time.
//!

#ifndef QUEUE_BY_LIST_H
#define QUEUE_BY_LIST_H

#include "list.hpp"
#include <assert.h>

namespace ch10{
namespace list{

template<typename T>
class queue_by_list
{
public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using SizeType  = std::size_t;

    queue_by_list() = default;

    /**
     * @brief enqueue
     *
     * @complexity  O(1)
     *
     * as required in ex10.2-3
     */
    void enqueue (const ValueType& val)
    {
        sPointer added = std::make_shared<Node>(val);
        if(count == 0)
        {
            head = tail = added;
            count = 1;
        }
        else
        {
            tail->next  =   added;
            tail        =   added;
            ++count;
        }
    }


    /**
     * @brief dequeue
     *
     * @complexity  O(1)
     *
     * as required in ex10.2-3
     */
    ValueType dequeue()
    {
        assert( count > 0);

        ValueType ret = head->key;
        head = head->next;
        --count;

        return ret;
    }

    SizeType size() const
    {
        return count;
    }

    bool empty() const
    {
        return head == tail == nullptr;
    }

private:
    sPointer head;
    sPointer tail;
    SizeType count = 0;
};


}// namespace list
}// namespace ch10


#endif // QUEUE_BY_LIST_H


//! testing code:

//#include <iostream>
//#include "queue_by_list.hpp"

//int main()
//{
//    ch10::list::queue_by_list<long> q;

//    for(int i = 0; i != 10; ++i)
//        q.enqueue(i);

//    for(int i = 0; i != 10; ++i)
//        std::cout << q.dequeue() << std::endl;

//    return 0;
//}
