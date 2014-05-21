/***************************************************************************
 *  @file       quick_sort.h
 *  @author     Alan.W
 *  @date       21  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

//! pseudocode
//! based on PARTITION Page 171
/*      partition(first, last)
 * 1    def pivot = last - 1
 * 2    def smaller = first - 1
 * 3    for iter = first to pivot -1
 * 4        if *iter <= *pivot
 * 5            ++smaller
 * 6            swap(*smaller, *iter)
 * 7    swap(*++smaller, *pivot)
 * 8    pivot = smaller
 * 9    return pivot
 */

#ifndef QUCK_SORT_H
#define QUCK_SORT_H

#include<algorithm>

namespace ch7{

template<typename Iter>
Iter partition(Iter first, Iter last);


template<typename Iter>
/**
 * @brief partition
 *
 * check above for peudocode. refer to Page 171 for detail
 */
inline Iter partition(Iter first, Iter last)
{
    Iter pivot = last - 1;
    Iter smaller =first - 1;
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

}


#endif // QUCK_SORT_H
