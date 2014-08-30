/***************************************************************************
 *  @file       stack.h
 *  @author     Alan.W
 *  @date       18  May 2014
 *  @remark     This code is for Introduction to Algorithms 3rd
 *  @note       code style : STL
 ***************************************************************************/

#ifndef STACK_H
#define STACK_H

#include "priority_queue.h"
#include <functional>

namespace ch6 {

/**
 *  @brief forward declaration
 */
template<typename T>
struct element;
template<typename T>
bool operator >(const element<T>& lhs, const element<T>& rhs);
template<typename T>
class stack;


/**
 * @brief The element struct
 */
template<typename T>
struct element
{
    using ValueType     = T;
    using PriorityType  = std::size_t;

    element() = default;
    explicit element(const ValueType& v, PriorityType p):
        value(v),prio(p)
    {}

    ValueType value;
    PriorityType prio;
};

/**
 * @brief operator >
 *
 * used for priority_queue to compare elements
 */
template<typename T>
bool inline
operator >(const element<T>& lhs, const element<T>& rhs)
{
    return lhs.prio > rhs.prio;
}

/**
 *  @brief class stack
 *
 * priority_queue as the underlying data structur as required in ex6.5-7
 */
template<typename T>
class stack
{
public:
    using ValueType     = T;
    using PriorityType  = typename element<ValueType>::PriorityType;

    /**
     * @brief push
     */
    void push(const ValueType &v)
    {
        q.push(element<ValueType>(v, top_priority++));
    }

    /**
     * @brief pop
     */
    void pop()
    {
        q.pop();
        --top_priority;
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
    PriorityType top_priority = 0;
};


}//namespace

#endif // STACK_H
