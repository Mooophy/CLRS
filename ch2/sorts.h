
/***************************************************************************
 *  @file       sorts.h
 *  @author     Alan.W
 *  @date       17  Mar 2014
 *  @remark     This header contains sorts template functions from CLRS
 *              check the files implemented when doing exercises for pseudocode
 *
 *  @note       1   insertion sort (which is different from the ex version.
 *                  the insertion sort here applies STL style)
 *              2   insertion_sort_lengthK
 *              3   merge
 *              4   merge_sort
 *              5   bubble_sort
 ***************************************************************************/

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include <iostream>
#include <stdexcept>

/**
 * @brief bubble_sort
 * @param first
 * @param last
 */
template<typename Iter>
void bubble_sort(Iter first, Iter last);

/**
 * @brief merge_withInsertion_sort
 * @param [first, last) and k is an int greater than 0
 */
template<typename Iter>
void merge_withInsertion_sort(Iter first, Iter last, int k);

/**
 * @brief insertion_sort
 * @param first, last : [first, last)
 */
template<typename Iter>
void insertion_sort(Iter first, Iter last);

/**
 * @brief insertion_sort_lengthK
 */
template<typename Iter>
void insertion_sort_lengthK(Iter first,Iter last, int k);

/**
 *  merge_sort
 *  @param [first, last)
 */
template<typename Iter>
void merge_sort(Iter first, Iter last);

/**
 * @brief merge     divide the original array
 * into two parts:  [first, mid) and [mid, last)
 * @param  [first..mid..last)
 */
template<typename Iter>
void merge(Iter first, Iter mid, Iter last);


///////////////////////////////////////////////////////////////////////////////
/**
 * @brief bubble_sort
 * @param first
 * @param last
 */
template<typename Iter>
void bubble_sort(Iter first, Iter last)
{
    if(last - first > 1)
    {
        for(Iter ex = first; ex != last - 1; ++ex)
            for(Iter in = last - 1; in != first; --in)
                if(*in < *(in - 1)) std::swap(*in, *(in - 1));
    }
}

/**
 * @brief merge_withInsertion_sort
 * @param [first, last) and k is an int greater than 0
 */
template<typename Iter>
void merge_withInsertion_sort(Iter first, Iter last, int k)
{
    //! recurssion
    if((last - first >1) && (last - first > k))
    {
        Iter mid = first + ( last - first)/2;
        merge_withInsertion_sort(first, mid , k);
        merge_withInsertion_sort(mid,   last , k);
        merge(first, mid, last);
    }
    else    insertion_sort(first, last);
}

//! insertion_sort
template<typename Iter>
void insertion_sort(Iter first, Iter last)
{
    if(last - first >= 2)
    {
        //!   iteration direction:   -->
        for (auto ex = first + 1; ex != last; ++ex)
        {
            auto key = *ex ;
            auto in  =  ex - 1;
            //!iteration direction:   <--
            while((in != first - 1) && (*in > key))
            {
                *(in+1) = *in ;
                --in;
            }
           *(in+1) = key;
        }
    }
}
/**
 * @brief insertion_sort_lengthK
 */
template<typename Iter>
void insertion_sort_lengthK(Iter first, Iter last, int k)
{
    if((last < first) || (k < 1))
        throw std::runtime_error
            ("\n@alan:\nlast iterator is greater than the first. \nor k is wrong.");

    auto it = first;
    while(last - it >= k)
    {  //!^^^^^^^^^^^^^^
       //!    -- prevent dereferencing outside the scope
        insertion_sort(it, it + k);
        it += k;
    }
    insertion_sort(it, last);
}

/**
 *  merge_sort
 *  @param [first, last)
 */
template<typename Iter>
void merge_sort(Iter first, Iter last)
{
    if(first < last - 1)
    {           //! ^^^ -- due to STL style, last must be minus 1
                //! so that it terminates recursions when only 1 element
                //! left in vector,otherwise it causes deadlock
        Iter mid = first + (last - first)/2;
        merge_sort(first, mid );
        merge_sort(mid  , last);
        merge(first, mid, last);
    }
}

/**
 * @brief merge     divide the original array
 * into two parts:  [first, mid) and [mid, last)
 * @param  [first..mid..last)
 */
template<typename Iter>
void merge(Iter first, Iter mid, Iter last)
{
    //! create two local vector to store the two parts
    typedef typename std::iterator_traits<Iter>::
            value_type      ValueType;
    std::vector<ValueType> lhs(first, mid);
    std::vector<ValueType> rhs(mid  , last);

    //! compare each element from lhs and rhs, then copy the
    //! smaller one to the original vector.
    auto l  = lhs.begin();
    auto r  = rhs.begin();
    auto it = first;
    while((it != last) && (r != rhs.end()) && l != lhs.end())
    {
        if(*r < *l)     *it++ = *r++;
        else            *it++ = *l++;
    }

    //! if either one is empty, copy all left in the other.
    if(l == lhs.end())
        while(it != last)   *it++ = *r++;
    if(r == rhs.end())
        while(it != last)   *it++ = *l++;
}
#endif // SORTS_H
