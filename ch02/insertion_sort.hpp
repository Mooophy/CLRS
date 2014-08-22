/***************************************************************************
 *  @file       insertion_sort.hpp
 *  @author     Alan.W
 *  @date       22  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! ex2.1-2
//! Rewrite the I NSERTION -S ORT procedure to sort into nonincreasing instead of non-
//! decreasing order.
//!

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <iterator>
#include <assert.h>
#include <functional>

namespace clrs { namespace ch2 {

/**
 *  @brief  aliasing for value type an iterator points to
 */
template<typename Iter>
using IterValue = typename std::iterator_traits<Iter>::value_type;

/**
 * @brief insertion_sort
 * @param first
 * @param last
 *
 * @typename        Iter    iterator
 * @typename        Comp    callable
 *
 * @pseudocode      INSERTION-SORT, Page 18, CLRS
 * @exercise        ex2.1-2, Page 22, CLRS
 * @complx          O(n^2)
 */
template<typename Iter, typename Comp = std::greater<IterValue<Iter> > >
void insertion_sort(Iter first, Iter last, Comp compare = Comp())
{
    //! trivial case
    if(last - first < 2)    return;

    //! when more than two elements
    for(auto curr = first + 1; curr != last; ++curr)
    {
        auto key = *curr;

        //! insert into the sorted sequence
        auto prev = curr - 1;
        while(prev != first - 1  &&  compare(*prev, key))
        {
            *(prev + 1) =   *prev;
            --prev;
        }

        //! place the element curr points to
        *(prev + 1) =   key;
    }
}

}}//namespace
#endif // INSERTION_SORT_HPP


//! @test   insertion_sort
//!         insertion_sort with predicate   as required in ex2.1-2
//!
//! @output
//!
//! the sorted sequence:
//! 0 1 2 3 6 99
//! exit normally
//!
//#include <iostream>
//#include <vector>
//#include "insertion_sort.hpp"
//#include "alan.hpp"

//int main()
//{
//    std::vector<int> v = {3,2,1,6,99,0};
//    clrs::ch2::insertion_sort(v.begin(), v.end(), std::greater<int>());

//    alan::prompt("the sorted sequence:");
//    alan::print_container(v);
//    alan::end();
//    return 0;
//}


