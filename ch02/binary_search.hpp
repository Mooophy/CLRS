/***************************************************************************
 *  @file       binary_search.hpp
 *  @author     Alan.W
 *  @date       24  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! ex2.3-5
//! Referring back to the searching problem (see Exercise 2.1-3), observe that if the
//! sequence A is sorted, we can check the midpoint of the sequence against and
//! eliminate half of the sequence from further consideration. The binary search al-
//! gorithm repeats this procedure, halving the size of the remaining portion of the
//! sequence each time. Write pseudocode, either iterative or recursive, for binary
//! search. Argue that the worst-case running time of binary search is O(lg n).
//!
//! ex2.3-7 ★
//! Given a set S of n intergers and another integer x.
//! Describe a O(nlog2(n))- time algorithm to determine whether or not there exist
//! two elements in S whose sum is exactly x.
//!
//  step 1: merge sort                          --  O(n lg n)
//  step 2: iterate the sorted sequence         --  O(n)
//      step 2.1    binary_search(sum - *iter)  --  O(lg n)
//  running time = O(n lg n) + O(n) * O(lg n) = 2 * O(n lg n) = O(n lg n)
//  check the codes below for implementation.
//!

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <functional>
#include "iterator.hpp"
#include "merge_sort.hpp"

namespace clrs{namespace ch2{

/**
 * @brief binary_search
 * @param first
 * @param last
 * @param val
 * @return      the iterator pointing to the element looked for
 *              or last iterator when nothing found
 * @ex2.3-5
 * @complx  O(lg n)
 */
template<typename Iter>
Iter binary_search(Iter first, Iter last, const IterValue<Iter>& val)
{
    //! define a lambda for real work
    Iter nil;
    using Lambda    =   std::function<Iter(Iter,Iter)>;
    Lambda  recur   =   [&](Iter first, Iter last)
    {
        auto mid    =   first + (last - first)/2;

        if(*mid ==  val)        return mid;
        else if(mid ==  first)  return nil;
        else if(*mid > val)     return recur(first,mid);
        else                    return recur(mid,last);
    };

    //! call the lamda and return result
    auto ret = recur(first, last);
    return ret == nil?  last    :   ret;
}

template<typename Iter>
Iter find_sum(Iter first, Iter last, const IterValue<Iter>& sum)
{
    clrs::ch2::merge_sort(first, last);
    auto ret = last;
    for(auto it = first; it != last     &&  found == last; ++it)
        ret = binary_search(first, last, sum - *it);

    return found;
}

}}//namespace
#endif // BINARY_SEARCH_HPP


//! @test   binary_search
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "binary_search.hpp"
//int main()
//{
//    std::vector<int> v{1,2,3,4,5,6,32,99};

//    auto ret = clrs::ch2::binary_search(v.begin(),v.end(),32);
//    std::cout << *ret;

//    alan::end();
//    return 0;
//}

//! @output
//!
//32
//exit normally
