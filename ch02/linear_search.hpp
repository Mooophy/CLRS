/***************************************************************************
 *  @file       insertion_sort.hpp
 *  @author     Alan.W
 *  @date       22  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! ex2.1-3
//! Write pseudocode for linear search, which scans through the sequence, looking
//! for . Using a loop invariant, prove that your algorithm is correct. Make sure that
//! your loop invariant fulfills the three necessary properties.
//!

#ifndef LINEAR_SEARCH_HPP
#define LINEAR_SEARCH_HPP

#include <iterator.hpp>

namespace clrs { namespace ch2 {

/**
 * @brief linear_search
 * @param first
 * @param last
 * @param val
 *
 * @complexity  O(n)
 * for ex2.1-3
 */
template<typename Iter>
Iter linear_search(Iter first, Iter last, const IterValue<Iter>& val)
{
    for(auto curr = first; curr != last; ++curr)
        if(*curr == val)
            return curr;

    return  last;
}

}}//namespace
#endif // LINEAR_SEARCH_HPP

//! @test
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "linear_search.hpp"
//int main()
//{
//    std::vector<int> v = {3,2,1,6,99,0};
//    std::cout << *clrs::ch2::linear_search(v.begin(),v.end(),99);

//    alan::end();
//    return 0;
//}
//! @output:
//!
//99
//exit normally
