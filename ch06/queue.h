/***************************************************************************
 *  @file       queue.h
 *  @author     Alan.W
 *  @date       18  May 2014
 *  @remark     This code is for Introduction to Algorithms 3rd
 *  @note       code style : STL
 ***************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include "priority_queue.h"
#include "stack"

namespace ch6 {

/**
 * @brief operator <
 *
 * used for priority_queue to compare elements
 */
template<typename T>
bool operator <(const element<T>& lhs, const element<T>& rhs)
{
    return lhs.prio < rhs.prio;
}


/**
 *  @brief class queue
 *
 * priority_queue as underlying data structur, as required in ex6.5-7
 */
template<typename T>
class queue
{
public:
    using ValueType     = T;
    using PriorityType  = typename element<ValueType>::PriorityType;

    /**
     * @brief ctor
     */
    queue():
        q(std::less<element<ValueType>>()), current(0)
    {}

    /**
     * @brief push
     */
    void push(const ValueType &v)
    {
        assert(current != 4294967295 && "over range");
        q.push(element<ValueType>(v, current++));
    }

    /**
     * @brief pop
     */
    void pop()
    {
        q.pop();
    }

    /**
     * @brief top
     */
    const ValueType& top()
    {
        return q.top().value;
    }

    /**
     * @brief check if empty
     */
    bool empty()
    {
        return q.empty();
    }

private:
    priority_queue<element<ValueType>> q;
    PriorityType current;
};


}//namespace

#endif // QUEUE_H
