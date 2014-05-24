/***************************************************************************
 *  @file       quick_sort.h
 *  @author     Alan.W
 *  @date       21  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! pseudocode
//! based on RANDOMIZED-PARTITION Page 179
//!
/*      randomized_partition(first, last)
 *1     def random_engine e
 *2     def uniform_distrabution ud(0, last - first - 1)
 *3     def piovt = ud(e)
 *4     swap(*pivot, *(last - 1))
 *5     return partition(first, last)
 */

//!
//! pseudocode
//! based on RANDOMIZED-QUICKSORT Page 179
//!
/*      randomized_quicksort(first, last)
 * 1    if last - first > 1
 * 2        pivot = randomized_partion(first, last)
 * 3        randomized_quicksort(first, pivot)
 * 4        randomized_quicksort(pivot + 1, last )
 */


#ifndef RANDOMIZED_QUICK_SORT_H
#define RANDOMIZED_QUICK_SORT_H

#include "quick_sort.h"
#include <random>
#include <assert.h>
#include <iterator>

namespace ch7
{
template<typename Iter>
Iter randomized_partition(Iter first, Iter last);

template<typename Iter>
void randomized_quicksort(Iter first, Iter last);

/**
 * @brief randmized_partition
 *
 * @complexity  O(lg n)
 */
template<typename Iter>
inline Iter randomized_partition(Iter first, Iter last)
{
    assert(last > first);
    static std::default_random_engine e;
    static std::uniform_real_distribution<float> ud(0, 100);

    auto range = last - first;
    Iter pivot = first + ud(e) * range/100;
    std::swap(*pivot, *(last - 1));
    return ch7::partition(first, last);
}

/**
 * @brief randomized_quicksort
 *
 * @complexity      worst-cast  :   theta(n^2)
 *                  average     :   theta(n lg n)
 */
template<typename Iter>
inline void randomized_quicksort(Iter first, Iter last)
{
    if(last - first > 1)
    {
        Iter pivot = randomized_partition(first, last);
        randomized_quicksort(first, pivot);
        randomized_quicksort(pivot + 1, last);
    }
}

}//namespace


#endif // RANDOMIZED_QUICK_SORT_H
