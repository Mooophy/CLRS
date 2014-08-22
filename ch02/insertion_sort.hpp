/***************************************************************************
 *  @file       activity.hpp
 *  @author     Alan.W
 *  @date       22  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <iterator>
#include <assert.h>

namespace clrs { namespace ch2 {

/**
 * @brief insertion_sort
 * @param first
 * @param last
 *
 * @type param      container, such as std::vector
 *
 * @pseudocode      INSERTION-SORT, Page 18, CLRS
 * @complx          O(n^2)
 */
template<typename Iter>
void insertion_sort(Iter first, Iter last)
{

    //! trivial case
    if(last - first < 2)    return;

    //! when more than two elements
    for(auto curr = first + 1; curr != last; ++curr)
    {
        auto key = *curr;

        //! insert into the sorted sequence
        auto prev = curr - 1;
        while(prev != first - 1  &&  *prev > key)
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


//! test    insertion_sort
//!
//#include <iostream>
//#include <vector>
//#include "insertion_sort.hpp"
//#include "alan.hpp"

//int main()
//{
//    std::vector<int> v = {3,2,1,6,99,0};
//    clrs::ch2::insertion_sort(v.begin(), v.end());

//    alan::prompt("the sorted sequence:");
//    alan::print_container(v);
//    alan::end();
//    return 0;
//}
