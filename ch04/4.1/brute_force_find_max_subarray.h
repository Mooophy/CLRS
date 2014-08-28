/***************************************************************************
 *  @file       brute_force_find_max_subarray.h
 *  @author     Alan.W
 *  @date       26  Apr 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//! ex4.1-1
//! What does FIND-MAXIMUM-SUBARRAY return when all elements of A are negative?
//  In such case, the result returned from find_max_crossing_subarray must be smallest
//  one among the left, right and cross tuple. Hence the element returned must be
//  the largest single element from the container.
//!
//! ex4.1-2
//! Write pseudocode for the brute-force method of solving the maximum-subarray problem.
//! Your procedure should run in n^2 time.
//!
//! part 1 calculate the sum
/*      sum(first, last) -> valuetype
 * 1    front = first
 * 2    sum = valuetype()
 * 3    while(front != last)
 * 4        sum += *front++
 * 5    return sum
 */
//! part 2
/*      brute_force_find_max_subarray(first, last) -> tuple
 * 1    front = first
 * 2    first_time = true
 * 3    max_sum = valuetype()
 * 4    max_left = max_right = Iter()
 * 5    while( front != last)
 * 6        def back = last
 * 7        while(back != front)
 * 8            def sum = sum(front, back)
 * 9            if(first_time)
 * 10               max_sum     = sum
 * 11               max_left    = front
 * 12               max_right   = back
 * 13               first_time  = false
 * 14           elseif  (sum > max_sum)
 * 15               max_sum     = sum
 * 16               max_left    = left
 * 17               max_right   = right
 * 18           --back
 * 19       ++front
 * 20   return tuple(max_left, max_right, max_sum)
 */
#ifndef BRUTE_FORCE_FIND_MAX_SUBARRAY_H
#define BRUTE_FORCE_FIND_MAX_SUBARRAY_H

#include <iterator>
#include <tuple>
#include <assert.h>
//! sum from [first, last)
template<typename Iter>
typename std::iterator_traits<Iter>::value_type
calculate_sum(Iter first, Iter last);

//! find max subarray using brute force
template<typename Iter>
std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
brute_force_find_max_subarray(Iter first, Iter last);


//! sum from [first, last)
template<typename Iter>
inline typename std::iterator_traits<Iter>::value_type
calculate_sum(Iter first,Iter last)
{
    assert(first < last);
    using ValueType =
        typename std::iterator_traits<Iter>::value_type;
    Iter front = first;
    ValueType sum = ValueType();

    while(front != last)    sum += *front++;
    return sum;
}

//! find max subarray using brute force
template<typename Iter>
inline std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
brute_force_find_max_subarray(Iter first, Iter last)
{
    //! types
    using ValueType = typename std::iterator_traits<Iter>::value_type;
    using Tuple     = typename std::tuple<Iter, Iter, ValueType>;

    //! initialization
    Iter front          = first;
    bool first_time     = true;
    ValueType max_sum   = ValueType();
    Iter max_left       = Iter();
    Iter max_right      = Iter();

    //! two nested loops
    while(front != last)            //-->
    {
        Iter back = last;
        while(back != front)        //<--
        {
            ValueType sum = calculate_sum(front, back);
            if(first_time)
            {
                max_sum     =   sum;
                max_left    =   front;
                max_right   =   back;
                first_time  =   false;
            }
            else if( sum > max_sum )
            {
                max_sum     =   sum;
                max_left    =   front;
                max_right   =   back;
            }
            --back;
        }
        ++front;
    }
    return Tuple(max_left, max_right, max_sum);
}


#endif // BRUTE_FORCE_FIND_MAX_SUBARRAY_H
