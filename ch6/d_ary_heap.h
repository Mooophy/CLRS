/***************************************************************************
 *  @file       d_ary_heap.h
 *  @author     Alan.W
 *  @date       19  May 2014
 *  @remark     This code is for Introduction to Algorithms 3rd
 *  @note       code style : STL
 ***************************************************************************/

//! this code was implemented for the Problem 6-2

#ifndef D_ARY_HEAP_H
#define D_ARY_HEAP_H

#include "assert.h"
#include <utility>

namespace ch6 {

template<typename Iter>
struct children;

template<typename Iter>
Iter parent_d(Iter first, Iter target, std::size_t d);

template<typename Iter>
children children_d(Iter first, Iter target, std::size_t d);

/**
 *  @brief children type
 */
template<typename Iter>
struct children
{
    children(Iter b, Iter e):
        begin(b),end(e)
    {}

    Iter begin;
    Iter end;
};

/**
 * @brief parent_d
 */
template<typename Iter>
inline Iter parent_d(Iter first, Iter target, std::size_t d)
{
    assert(target >= first);

    if(target == first)
        return target;
    else
        return first + (target - first - 1)/d;
}

/**
 * @brief children_d
 */
template<typename Iter>
inline children children_d(Iter first, Iter target, std::size_t d)
{
    assert(target >= first);

    auto distance = target - first;
    return children(first + d * distance + 1    ,
                    first + d * distance + 1 + d);
}


}

#endif // D_ARY_HEAP_H
