/***************************************************************************
 *  @file       insertion_sort.hpp
 *  @author     Alan.W
 *  @date       27  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! @problem 2-1 Insertion sort on small arrays in merge sort
//!
#ifndef MERGE_WITH_INSERTION_SORT_HPP
#define MERGE_WITH_INSERTION_SORT_HPP

#include "insertion_sort.hpp"
#include "merge_sort.hpp"

namespace clrs {namespace ch2 {

/**
 * @brief merge_with_insertion_sort
 * @param first
 * @param last
 * @param thresh    i.e. k
 *
 * @problem 2-1
 * @complx  theta(n*k + n lg(n/k))
 */
template<typename Iter, typename SizeType>
void merge_with_insertion_sort(Iter first, Iter last, SizeType thresh)
{
    assert(last - first >= thresh);

    if(last - first > thresh)
        clrs::ch2::merge_sort(first, last);
    else
        clrs::ch2::insertion_sort(first, last);
}

}}//namespace
#endif // MERGE_WITH_INSERTION_SORT_HPP

//! @test   merge_with_insertion_sort
//!         problem 2-1
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "merge_with_insertion_sort.hpp"

//int main()
//{
//    std::vector<int> v{1,6,88,2,0,77};
//    clrs::ch2::merge_with_insertion_sort(v.begin(), v.end(), 2);
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}
//! @output
//!
//0 1 2 6 77 88
//exit normally
