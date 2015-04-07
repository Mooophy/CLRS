/***************************************************************************
 *  @file       quick_sort.h
 *  @author     Alan.W
 *  @date       21  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//! pseudocode
//! check page 185 problem 7-1 for detail
/*      hoare_partition(first, last)
 *1     def pivot   = *first
 *2     def forward = first - 1
 *3     def backford= last
 *4     while true
 *5         while(*--backward > pivot)
 *6         while(*++forward < pivot)
 *7         if forward < backward
 *8             swap(*forward, *backward)
 *9         else    return backward
 */

/*      hoare_quicksort(first, last)
 *1     if last - first > 1
 *2         def mid = hoare_partition(first, last)
 *3         hoare_quicksort(first, middle + 1)
 *4         hoare_quicksort(middle + 1, last)
 */

#ifndef HOARE_QUICKSORT_H
#define HOARE_QUICKSORT_H

#include <algorithm>

namespace ch7
{
template<typename Iter>
Iter hoare_partition(Iter first, Iter last);
template<typename Iter>
void hoare_quicksort(Iter first, Iter last);


/**
 * @brief hoare_partition
 *
 * @complexity  O(lg n)
 */
template<typename Iter>
inline Iter hoare_partition(Iter first, Iter last)
{
    auto pivot      = *first;
    Iter forward    = first - 1;
    Iter backward   = last;
    while(true)
    {
        while(*--backward > pivot);
        while(*++forward  < pivot);

        if(forward < backward)
            std::swap(*forward, *backward);
        else
            return backward;
    }
}

/**
 * @brief hoare_quicksort
 *
 * @complexity      worst-cast  :   theta(n^2)
 *                  average     :   theta(n lg n)
 */
template<typename Iter>
inline void hoare_quicksort(Iter first, Iter last)
{
    if(last - first > 1)
    {
        Iter middle = hoare_partition(first, last);
        hoare_quicksort(first, middle + 1);
        hoare_quicksort(middle + 1, last);
    }
}

}//namespace


#endif // HOARE_QUICKSORT_H
