/***************************************************************************
 *  @file       heap.hpp
 *  @author     Yue Wang
 *  @date       30  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
#ifndef HEAP_HPP
#define HEAP_HPP

namespace clrs { namespace ch6 {

/**
 * @brief parent
 */
template<typename SizeType>
inline SizeType parent(SizeType target)
{
    return (target - 1)/2;
}

/**
 * @brief left
 */
template<typename SizeType>
inline SizeType left(SizeType target)
{
    return 2 * target + 1;
}

/**
 * @brief right
 */
template<typename SizeType>
inline SizeType right(SizeType target)
{
    return 2 * target + 2;
}

/**
 * @brief max_heapify
 * @param rng
 * @param curr
 *
 * @pseudocode MAX-HEAPIFY, Page 154
 * @recurrence T(n) <= T(2n/3) + theta(1)
 * @complx  O(lg n)
 */
template<typename Range>
void max_heapify(Range& rng, typename Range::size_type curr)
{
    //! compare with left child
    auto l = left(curr);
    auto largest = (l < rng.size()  &&  rng[l] > rng[curr])?  l   :   curr;

    //! compare with right child
    auto r = right(curr);
    if(r < rng.size()   &&  rng[r] > rng[largest])  largest = r;

    //! recur when necessary
    if(largest != curr)
    {
        std::swap(rng[largest], rng[curr]);
        max_heapify(rng, largest);
    }
}

}}//namespace
#endif // HEAP_HPP

//! @test
//!
//#include <vector>
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "heap.hpp"

//int main()
//{
//    std::vector<int> v {16,4,10,14,7,9,3,2,8,1};
//    clrs::ch6::max_heapify(v,1);
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}
//! @output
//!
//16 14 10 8 7 9 3 2 4 1
//exit normally
