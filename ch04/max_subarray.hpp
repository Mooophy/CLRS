/***************************************************************************
 *  @file       max_subarray.hpp
 *  @author     Alan.W
 *  @date       29  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//! ex4.1-2
//! Write pseudocode for the brute-force method of solving the maximum-subarray problem.
//! Your procedure should run in n^2 time.
//!
#ifndef MAX_SUBARRAY_HPP
#define MAX_SUBARRAY_HPP

#include <algorithm>
#include "iterator.hpp"

namespace clrs { namespace ch4 {

template<typename Iter>
struct Record
{
    Iter first;
    Iter last;
    clrs::IterValue<Iter> sum;
};

/**
 * @brief brute_force_find_max_subarray
 * @param first
 * @param last
 * @return
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

}}//namespace
#endif // MAX_SUBARRAY_HPP
