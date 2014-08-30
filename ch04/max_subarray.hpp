/***************************************************************************
 *  @file       max_subarray.hpp
 *  @author     Alan.W
 *  @date       29  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! @ex4.1-2
//! Write pseudocode for the brute-force method of solving the maximum-subarray problem.
//! Your procedure should run in n^2 time.
//!
//  check implementation below
//!
//! @ex4.1-5
//! idea
//! step one :  build a container that stores the max subarray ending at each element
//! step two :  find the largest one from the container and return it.
//!
//  check find_max_subarray_linear function below for implementation
//!

#ifndef MAX_SUBARRAY_HPP
#define MAX_SUBARRAY_HPP

#include <algorithm>
#include <vector>
#include <assert.h>
#include "iterator.hpp"

namespace clrs { namespace ch4 {

/**
 * @brief The Record struct
 */
template<typename Iter>
struct Record
{
    Iter first;
    Iter last;
    clrs::IterValue<Iter> sum;
};

template<typename Iter>
inline bool
operator >=(const Record<Iter>& lhs, const Record<Iter>& rhs)
{
    return lhs.sum  >= rhs.sum;
}

template<typename Iter>
inline bool
operator <(const Record<Iter>& lhs, const Record<Iter>& rhs)
{
    return lhs.sum  < rhs.sum;
}
/**
 * @brief brute_force_find_max_subarray
 * @param first
 * @param last
 * @return  a struct containing first and last for the max subarray and its sum.
 *
 * @complx  O(n^2)
 * for ex4.1-2
 */
template<typename Iter>
Record<Iter>
brute_force_find_max_subarray(Iter first, Iter last)
{
    Record<Iter> max{first, first + 1, *first};
    for(auto head = first; head != last; ++head)
        for(auto tail = last; tail != head ; --tail)
        {
            auto sum = std::accumulate(head, tail, 0);
            if(sum > max.sum)
                max = { head, tail, sum };
        }
    return max;
}

/**
 * @brief find_max_crossing_subarray
 * @param first
 * @param mid
 * @param last
 * @return the Struct for max crossing subarray
 *
 * @pyseudocode FIND-MAX-CROSSING-SUBARRAY, page 71.
 * @complx  theta(n)
 */
template<typename Iter>
Record<Iter>
find_max_crossing_subarray(Iter first, Iter mid, Iter last)
{
    //! left subarray   <--
    auto left_sum = *(mid - 1);
    IterValue<Iter> sum = 0;
    auto max_left = mid - 1;
    for(auto l = mid - 1; l != first - 1; --l)
    {
        sum += *l;
        if(sum > left_sum)
        {
            left_sum = sum;
            max_left = l;
        }
    }

    //! right subarray  -->
    auto right_sum = *mid;
    sum = 0;
    auto max_right = mid;
    for(auto r = mid; r != last; ++r)
    {
        sum += *r;
        if(sum > right_sum)
        {
            right_sum = sum;
            max_right = r;
        }
    }

    return {max_left, max_right, left_sum + right_sum};
}

/**
 * @brief find_max_subarray
 * @param first
 * @param last
 *
 * @recurrence      T(n) = theta(1)             if n = 1
 *                  T(n) = 2T(n/2) + theta(n)   if n > 1
 *
 * @complx          theta(n lg n)
 *
 * @pseudocode      FIND-MAXIMUM-SUBARRAY   Page 72
 */
template<typename Iter>
Record<Iter> find_max_subarray(Iter first, Iter last)
{
    //! base case
    if(first == last - 1)
        return {first, last, *first};

    //! recur
    Iter mid = first + (last - first)/2;
    Record<Iter> left   =   find_max_subarray(first, mid);                  //T(n)
    Record<Iter> right  =   find_max_subarray(mid, last);                   //T(n)
    Record<Iter> cross  =   find_max_crossing_subarray(first, mid, last);   //theta(n)

    //! return the largest one
    if(left >= right    &&  left >= cross)          return left;
    else if(right >= left   &&  right >= cross)     return right;
    else                                            return cross;
}

/**
 * @brief find max subarray in linear time
 * @param first
 * @param last
 * @return the max subarray
 *
 * @complx  2 * theta(n) = theta(n)
 *
 * for ex4.1-5:
 * First part build a container that stores each max subarray ending at
 * each element.Then return the max element from this container.
 */
template<typename Iter>
Record<Iter> find_max_subarray_linear(Iter first, Iter last)
{
    using Vec = std::vector<Record<Iter>>;
    Vec v(last - first);
    v[0] = {first, first + 1, *first};
    for(typename Vec::size_type curr = 1; curr != v.size(); ++curr)
    {
        if(v[curr - 1].sum   <=  0)
            v[curr] =
            {
                first + curr,
                first + curr + 1,
                *(first + curr)
            };
        else
            v[curr] =
            {
                v[curr - 1].first,
                first + curr + 1,
                v[curr - 1].sum + *(first + curr)
            };
    }
    return *std::max_element(v.begin(),v.end());
}

}}//namespace
#endif // MAX_SUBARRAY_HPP

//! @test   brute_force_find_max_subarray
//!         for ex4.1-2
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "max_subarray.hpp"

//int main()
//{
//    std::vector<int> v{2,-1, 3,};
//    auto ret = clrs::ch4::brute_force_find_max_subarray(v.begin(), v.end());
//    std::cout << ret.sum;

//    alan::end();
//    return 0;
//}
//! @output
//!
//4
//exit normally

//! @test   find_max_crossing_subarray
//!         for FIND-MAX-CROSSING-SUBARRAY
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "max_subarray.hpp"

//int main()
//{
//    std::vector<int> v{2,-1, 3,};
//    auto ret = clrs::ch4::find_max_crossing_subarray(v.begin(),v.begin() + 1, v.end());
//    std::cout << ret.sum;

//    alan::end();
//    return 0;
//}
//! @output
//!
//4
//exit normally


//! @test   find_max_subarray
//!         for FIND-MAXIMUM-SUBARRAY
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "max_subarray.hpp"

//int main()
//{
//    std::vector<int> v{2,-1, 3,5};
//    auto ret = clrs::ch4::find_max_subarray(v.begin(), v.end());
//    std::cout << ret.sum;

//    alan::end();
//    return 0;
//}
//! @output
//!
//9
//exit normally

//! @test   find max subarray in linear time
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "max_subarray.hpp"

//int main()
//{
//    std::vector<int> v{2,-1, 3,5};
//    auto ret = clrs::ch4::find_max_subarray_linear(v.begin(), v.end());
//    std::cout << ret.sum;

//    alan::end();
//    return 0;
//}
//! @output
//9
//exit normally
