/***************************************************************************
 *  @file       d_ary_heap.h
 *  @author     Alan.W
 *  @date       19  May 2014
 *  @remark     This code is for Introduction to Algorithms 3rd
 *  @note       code style : STL
 ***************************************************************************/

//! this code was implemented for the Problem 6-2 part c
//! pseudocode for MAX-HEAP-D
//!
//! based on MAX-HEAPIFY (Page 154)
//!
//! assuming that the d-ary trees rooted at left(target) and right(target) are
//! max-heap
//!
/*      max_heap_d(first, last, target, d)
 * 1    def children = children_d(first, target, d)
 * 2    if  children.begin < last
 * 3        def max_child   = children.begin
 * 4        def iter        = children.begin
 * 5        while   iter != children.end    AND    iter != last
 * 6            if  *iter > *max_child
 * 7                max_child = iter
 * 8            ++iter
 * 9        if  *max_child > *target
 * 10           swap(*max_child, *target)
 * 11           max_heap_d(first, last, max_child, d)
 */

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
children<Iter> Children_d(Iter first, Iter target, std::size_t d);

template<typename Iter>
void max_heap_d(Iter first, Iter last, Iter target, std::size_t d);

/**
 *  @brief children type
 */
template<typename Iter>
struct Children
{
    Children(Iter b, Iter e):
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

    if(target == first) return target;
    else                return first + (target - first - 1)/d;
}

/**
 * @brief children_d
 */
template<typename Iter>
inline Children<Iter> children_d(Iter first, Iter target, std::size_t d)
{
    assert(target >= first);

    auto distance = target - first;
    return Children<Iter>(  first + d * distance + 1     ,
                            first + d * distance + 1 + d);
}

/**
 * @brief max_heap_d
 *
 * @complexity  O(lg n)
 *              O(d * h) = O(d * log_d n) = O(d * (lg n / lg d))
 *
 * i.e. d'ary max_heap
 */
template<typename Iter>
inline void max_heap_d(Iter first, Iter last, Iter target, std::size_t d)
{
    assert(first <= target && target < last);

    Children<Iter> children = children_d(first, target, d);
    if(children.begin < last)
    {
        Iter max_child  = children.begin;
        Iter iter       = children.begin;

        //! complexity : O(d)
        while(iter != children.end  && iter != last)
        {
            if(*iter > *max_child)
                max_child = iter;
            ++iter;
        }

        //! complexity : O(log_d (n))
        if (*max_child > *target)
        {
            std::swap(*max_child, *target);
            max_heap_d(first, last, max_child, d);
        }
    }
}


}//namespace

#endif // D_ARY_HEAP_H





