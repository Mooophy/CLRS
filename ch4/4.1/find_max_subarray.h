/***************************************************************************
 *  @file       find_max_crossing_subarray.h
 *  @author     Alan.W
 *  @date       26  Apr 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! Find Max Crossing Subarray  from textbook
//!     note :  the implementation is different from this psyeudocode
//!
/*      find_max_crossing_subarray(A, low, mid, high)
 *1     left_sum = -inifinty
 *2     sum = 0
 *3     for i = mid downto low
 *4         sum = sum + A[i]
 *5         if sum > left_sum
 *6             left_sum = sum
 *7             max_left = i
 *8     right_sum = -infiniy
 *9     sum = 0
 *10    for j = mid+1 to high
 *11        sum = sum + A[j]
 *12        if sum > right_sum
 *13            right_sum = sum
 *14            max_right = j
 *15    return (max_left, max_right, left_sum + right_sum )
 */

//!
//! Find Max max Subarray  revised to match stl style.
//!
/*      find_max_subarray(first, last)
 * 1    if (last - first) == 1
 * 2        return tuple(first, last, *first)
 * 3    else mid = first + (last - first)/2
 * 4        tuple left  = find_max_subarray(first, mid)
 * 5        tuple right = find_max_subarray(mid, last )
 * 6        tuple cross = find_max_crossing_subarray(first, mid, last)
 * 7    if  (left >= right) and (left >= cross)
 * 8            return left
 * 9    elseif
 * 10       (right >= left) and (right = cross)
 * 11           return right
 * 12   else    return cross
 */
#ifndef FIND_MAX_SUBARRAY_H
#define FIND_MAX_SUBARRAY_H

#include <iterator>
#include <tuple>
#include <assert.h>

template<typename Iter>
std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
find_max_crossing_subarray(Iter first, Iter mid, Iter last);

template<typename Iter>
std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
find_max_subarray(Iter first, Iter last);


/**
 * @brief find_max_crossing_subarray
 * @param first
 * @param mid   first +(last - first)/2
 * @param last
 * @range   [first, last)
 * @note    type pointed to must be signed.
 * @attention   left:[first, mid)   right:[mid,last)
 *                              ^         ^^^^
 *              for STL style.
 */
template<typename Iter>
inline std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
find_max_crossing_subarray(Iter first, Iter mid, Iter last)
{
    assert(first < last);
    /**
     *  @brief   types
     */
    using ValueType = typename std::iterator_traits<Iter>::value_type;
    using Tuple     = typename std::tuple<Iter, Iter, ValueType>;

    /**
     * @brief   rang : [first, mid)
     * 1. Using firstTime flag instead of infinity for generic programming.
     * 2. use Value-initialization, otherwise the values are undefined.
     */
    bool firstTime          = true;
    ValueType sum           = ValueType();
    ValueType left_sum      = ValueType();
    Iter it                 = mid - 1;
    Iter max_left           = Iter();
    while(it != first - 1)
    {
        sum += *it;
        if(firstTime)
        {
            left_sum    = sum;
            max_left    = it;
            firstTime   = false;
        }
        if(sum > left_sum)
        {
            left_sum    = sum;
            max_left    = it;
        }
        --it;
    }

    /**
     * @brief   rang : [mid, last)
     * 1. Using firstTime flag instead of infinity due to generic programming.
     * 2. Value-initialization, otherwise the values are undefined.
     */
    firstTime            = true;
    sum                  = ValueType();
    ValueType right_sum  = ValueType();
    it                   = mid;
    Iter max_right       = Iter();
    while(it != last)
    {
        sum += *it;
        if(firstTime)
        {
            right_sum   = sum;
            max_right   = it;
            firstTime   = false;
        }
        if(sum > right_sum)
        {
            right_sum   = sum;
            max_right   = it;
        }
        ++it;
    }
    return Tuple(max_left, max_right, left_sum + right_sum);
}


/**
 * @brief find_max_subarray
 * @param first
 * @param last
 * @range   [first, last)
 */
template<typename Iter>
std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
find_max_subarray(Iter first, Iter last)
{
    /**
     *  @brief  types
     */
    using ValueType = typename std::iterator_traits<Iter>::value_type;
    using Tuple     = typename std::tuple<Iter, Iter, ValueType>;

    /**
     *  @brief  implementation
     */
    if(last - first == 1)
        return Tuple(first, last, *first);
    else
    {
        Iter mid    =   first + (last - first)/2;
        Tuple left  =   find_max_subarray(first, mid);
        Tuple right =   find_max_subarray(mid,  last);
        Tuple cross =   find_max_crossing_subarray(first, mid, last);
        if((std::get<2>(left) >= std::get<2>(right)) && (std::get<2>(left) >= std::get<2>(cross)))
            return  left;
        else if((std::get<2>(right) >= std::get<2>(left)) && (std::get<2>(right) >= std::get<2>(cross)))
            return  right;
        else
            return  cross;
    }
}
#endif // FIND_MAX_SUBARRAY_H
