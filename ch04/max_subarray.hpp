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
