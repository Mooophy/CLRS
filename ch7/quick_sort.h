/***************************************************************************
 *  @file       quick_sort.h
 *  @author     Alan.W
 *  @date       21  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! pseudocode
//! based on PARTITION Page 171
//!
/*      partition(first, last)
 * 1    def pivot = last - 1
 * 2    def smaller = first - 1
 * 3    for iter = first to pivot -1
 * 4        if *iter <= *pivot
 *      //           ^^^    can be changed to >= for nonincreasing order
 *      //                  as requied in ex7.1 -4
 * 5            ++smaller
 * 6            swap(*smaller, *iter)
 * 7    swap(*++smaller, *pivot)
 * 8    pivot = smaller
 * 9    return pivot
 */

//!
//! pseudocode
//! based on QUICKSORT Page 171
//!
/*      quick_sort(first, last)
 * 1    if last - first > 1
 * 2        def pivot = partition(first, last)
 * 3        quikc_sort(first, pivot)
 * 4        quick_sort(pivot + 1, last)
 */


#ifndef QUCK_SORT_H
#define QUCK_SORT_H

#include<algorithm>

namespace ch7{

template<typename Iter>
void quick_sort(Iter first, Iter last);

template<typename Iter>
Iter partition(Iter first, Iter last);


/**
 * @brief quick_sort
 *
 * @complexity  O(lg n)
 *
 * check above for peudocode. refer to Page 171 for detail.
 */
template<typename Iter>
inline void quick_sort(Iter first, Iter last)
{
    if(last - first > 1)
    {
        Iter pivot = partition(first, last);
        quick_sort(first, pivot);
        quick_sort(pivot + 1, last);
    }
}

/**
 * @brief partition
 *
 * @complexity      worst-cast  :   theta(n^2)
 *                  average     :   theta(n lg n)
 *
 * check above for peudocode. refer to Page 171 for detail
 */
template<typename Iter>
inline Iter partition(Iter first, Iter last)
{
    Iter pivot = last - 1;
    Iter smaller = first - 1;
    for(Iter iter = first; iter != pivot; ++iter)
    {
        if(*iter <= *pivot)
        {
            ++smaller;
            std::swap(*smaller, *iter);
        }
    }
    std::swap(*++smaller, *pivot);
    pivot = smaller;

    return pivot;
}

}//namespace


#endif // QUCK_SORT_H
