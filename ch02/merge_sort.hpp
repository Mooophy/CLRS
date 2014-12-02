/***************************************************************************
 *  @file       merge_sort.hpp
 *  @author     Yue.Wang
 *  @date       23  Aug 2014
 *  @update     02  Dec 2014
 *  @version    3
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include "iterator.hpp"
#include <iostream>


namespace clrs {namespace ch2 {


/**
 * @brief merge
 * @param first
 * @param mid
 * @param last
 *
 * @pseudocode  MERGE, page 31, clrs.
 * @complx  O(n)
 */
template<typename Iter>
void merge(Iter first, Iter mid, Iter last )
{
    //! init
    using Vector = std::vector<clrs::IterValue<Iter>>;
    Vector left(first, mid), right(mid, last);
    auto l = left.cbegin(), r = right.cbegin();
    auto it = first;

    //! copy until either one reaches its end
    for(; l != left.end() and r != right.end();  *it++ = *(*r < *l ? r : l)++);

    //! copy the rest.
    for(auto rest = (l == left.cend() ? r : l);  it != last;  *it++ = *rest++);
}


/**
 * @brief merge_sort
 * @param first
 * @param last
 *
 * @pseudocode  MERGE-SORT, page 34, clrs.
 * @complx  O(n lg n)
 */
template<typename Iter>
void merge_sort(Iter first, Iter last)
{
    if(first + 1 < last )
    {
        auto mid = first + (last - first)/2;
        merge_sort(first, mid );
        merge_sort(mid  , last);
        merge(first, mid, last);
    }
}


}}//namespace
#endif // MERGE_SORT_HPP


//! @test   merge sort
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "merge_sort.hpp"

//int main()
//{
//    std::vector<std::string> v{"99","22","z55","s11","b33"};

//    clrs::ch2::merge_sort(v.begin(), v.end());
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}

//! @output
//!
//22 99 b33 s11 z55
//exit normally
