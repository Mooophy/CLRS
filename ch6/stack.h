/***************************************************************************
 *  @file       stack.h
 *  @author     Alan.W
 *  @date       17  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <utility>
#include "priority_queue.h"

namespace ch6 {

template<typename T>
class stack
{
public:
    using ValueType       = T;
    using PriorityType  = std::size_t;

    /**
     * @brief The Element struct
     */
    struct Element
    {
        Element() = delete;

        Element(PriorityType p, const ValueType& v):
            priority(p), value(v)
        {}

        ~Element()= default;

        PriorityType priority;
        ValueType value;
    };

    /**
     * @brief The Greater functor
     */
    struct Greater
    {
        bool operator ()(const Element& lhs, const Element& rhs) const
        {
            return lhs.priority > rhs.priority;
        }
    };

    /**
     * @brief default ctor
     */
    stack() = default;

    /**
     * @brief get current priority
     * @return
     */
    PriorityType get_current()
    {
        return current;
    }

    /**
     * @brief push
     * @param new_value
     */
    void push(const ValueType& new_value)
    {
        q.push(Element(current++, new_value));
    }

    /**
     * @brief default dtor
     */
    ~stack()= default;
private:
    priority_queue<Element, Greater> q;
    PriorityType current = 0;

};

}//namespace


#endif // STACK_H
