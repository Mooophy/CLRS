/***************************************************************************
 *  @file       heap.hpp
 *  @author     Yue Wang
 *  @date       30  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
#ifndef HEAP_HPP
#define HEAP_HPP

#include <functional>

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

    //! recur
    if(largest != curr)
    {
        std::swap(rng[largest], rng[curr]);
        max_heapify(rng, largest);
    }
}

/**
 * @brief min_heapify
 * @param rng
 * @param curr
 *
 * @recurrence T(n) <= T(2n/3) + theta(1)
 * @complx  O(lg n)
 *
 * for ex6.2-2
 */
template<typename Range>
void min_heapify(Range& rng, typename Range::size_type curr)
{
    //! compare with left child
    auto l = left(curr);
    auto smallest = (l < rng.size()  &&  rng[l] < rng[curr])?  l   :   curr;

    //! compare with right child
    auto r = right(curr);
    if(r < rng.size()   &&  rng[r] < rng[smallest])  smallest = r;

    //! recur
    if(smallest != curr)
    {
        std::swap(rng[smallest], rng[curr]);
        max_heapify(rng, smallest);
    }
}

/**
 * @brief heapify
 * @param rng
 * @param curr
 * @param compare
 *
 * @recurrence T(n) <= T(2n/3) + theta(1)
 * @complx  O(lg n)
 */
template<typename Range, typename Comp = std::greater<typename Range::value_type> >
void heapify(Range& rng, typename Range::size_type curr, Comp compare = Comp())
{
    //! compare with left child
    auto l = left(curr);
    auto extreme = (l < rng.size()  &&  compare(rng[l], rng[curr]))?  l   :   curr;

    //! compare with right child
    auto r = right(curr);
    if(r < rng.size()   &&  compare(rng[r], rng[extreme]))  extreme = r;

    //! recur
    if(extreme != curr)
    {
        std::swap(rng[extreme], rng[curr]);
        heapify(rng, extreme);
    }
}

/**
 * @brief heapify_itera
 * @param rng
 * @param curr
 * @param compare
 *
 * @recurrence T(n) <= T(2n/3) + theta(1)
 * @complx  O(lg n)
 *
 * for ex6.2-5
 */
template<typename Range, typename Comp = std::greater<typename Range::value_type> >
void heapify_itera(Range& rng, typename Range::size_type curr, Comp compare = Comp())
{
    while(true)
    {
        //! find max or min, depending on Comp.
        auto l = left(curr);
        auto extreme =
                (l < rng.size()  &&  compare(rng[l], rng[curr]))?  l   :   curr;
        auto r = right(curr);
        if(r < rng.size()   &&  compare(rng[r], rng[extreme]))
            extreme = r;

        //! iteration check
        if(extreme != curr)
        {
            std::swap(rng[extreme], rng[curr]);
            curr = extreme;
        }
        else    break;
    }
}

}}//namespace
#endif // HEAP_HPP

//! @test   max_heapify, min_heapify, heapify, heapify_itera
//!
//#include <vector>
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "heap.hpp"

//int main()
//{
//    std::vector<int> v {16,4,10,14,7,9,3,2,8,1};
//    std::vector<int> v1,v2,v3,v4,v5,v6;
//    v1 = v2 = v3 = v4 = v5 = v6 = v;

//    //! max heapify
//    clrs::ch6::max_heapify(v1,1);
//    alan::print_container(v1);
//    std::cout << "\n";
//    clrs::ch6::heapify(v2,1,std::greater<int>());
//    alan::print_container(v2);

//    std::cout << "\n\n";

//    //! min heapify
//    clrs::ch6::min_heapify(v3,1);
//    alan::print_container(v3);
//    std::cout << "\n";
//    clrs::ch6::heapify(v4,1,std::less<int>());
//    alan::print_container(v4);

//    //! iteration version
//    std::cout << "\n";
//    clrs::ch6::heapify_itera(v5,1,std::less<int>());
//    alan::print_container(v5);

//    alan::end();
//    return 0;
//}



//! @output
//!
//16 14 10 8 7 9 3 2 4 1
//16 14 10 8 7 9 3 2 4 1

//16 4 10 14 7 9 3 2 8 1
//16 4 10 14 7 9 3 2 8 1
//16 4 10 14 7 9 3 2 8 1
//exit normally

