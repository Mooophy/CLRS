/***************************************************************************
 *  @file       heap_build.h
 *  @author     Alan.W
 *  @date       7  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//! BUILD-MAX-HEAPIFY
//! based on Page 157
/*      build_max_heap(first, last)
 *1     assert(last >= first)
 *2     size = last - first
 *3     if(size > 1)
 *4         for iter = size/2 - 1 downto 0
 *5             max_heapify(first, last, iter)
 */

//! HEAPSORT    based on the pseudocode p 160
/*      heap_sort(first, last)
 * 1    assert(last > first)
 * 2    build_max_heap(first, last)
 * 3    def iter = last - 1
 * 4    while(iter != first)
 * 5        swap(*first, *iter)
 * 6        max_heapify(first, iter, first)
 * 7        --iter
 */

#ifndef HEAP_BUILD_H
#define HEAP_BUILD_H

#include "heap.h"
#include <assert.h>
#include <iterator>

namespace ch6 {

/**
 * Declarations
 */
template<typename Iter>
void build_max_heap(Iter first, Iter last);

template<typename Iter>
void heap_sort(Iter first, Iter last);



/**
 * Implementation
 */

//! @brief  build_max_heap
//! @note   iterator starts from 0.
template<typename Iter>
inline void build_max_heap(Iter first, Iter last)
{
    assert(last >= first);

    auto size = last - first;
    if(size > 1)
        for(Iter iter = first + size/2 - 1; iter != first -1 ; --iter)
            ch6::max_heapify(first, last, iter);
}

//! @brief  heap sort
//! @note   running time = O(n*lgn)
template<typename Iter>
inline void heap_sort(Iter first, Iter last)
{
    assert(last > first);

    ch6::build_max_heap(first, last);

    Iter iter = last - 1;
    while(iter != first){
        std::swap(*first, *iter);
        ch6::max_heapify(first, iter, first);
        --iter;
    }
}

}//namespace
#endif // HEAP_BUILD_H

