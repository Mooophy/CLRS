/***************************************************************************
 *  @file       bubble_sort.hpp
 *  @author     Alan.W
 *  @date       27  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! @problem    2-2 Correctness of bubblesort
//!


#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include "assert.h"
#include <algorithm>

namespace clrs { namespace ch2 {

/**
 * @brief bubble_sort
 * @param first
 * @param last
 *
 * @ex  problem 2-2 Correctness of bubblesort
 * @complx  O(n^2)
 */
template<typename Iter>
void bubble_sort(Iter first, Iter last)
{
    assert(last > first);

    for(auto ex = first; ex != last - 1; ++ex)
        for(auto in = last - 1; in != ex; --in)
            if(*in < *(in - 1))     std::swap(*in, *(in - 1));
}

}}//namespace
#endif // BUBBLE_SORT_HPP

//! @test bubble_sort
//!     for problem 2-2
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "bubble_sort.hpp"

//int main()
//{
//    std::vector<int> v{1,6,88,2,0,77};
//    clrs::ch2::bubble_sort(v.begin(), v.end());
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}
//! @output
//!
//0 1 2 6 77 88
//exit normally
