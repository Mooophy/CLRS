/***************************************************************************
 *  @file       element.hpp
 *  @author     Yue Wang
 *  @date       2  Sep 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <utility>

namespace clrs {namespace ch6 {

/**
 * @brief The Element class template
 * for stack and queue
 */
template<typename T>
struct Element
{
    using PriorityType  =   std::size_t;

    T data;
    PriorityType prio;
};

/**
 * @brief operator <
 */
template<typename T>
inline bool
operator <(const Element<T>& lhs, const Element<T>& rhs)
{
    return lhs.prio < rhs.prio;
}

template<typename T>
inline bool
operator >(const Element<T>& lhs, const Element<T>& rhs)
{
    return lhs.prio > rhs.prio;
}

}}//namespace
#endif // ELEMENT_HPP
