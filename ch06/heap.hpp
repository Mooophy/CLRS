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
#include "../misc/iterator.hpp"

namespace clrs { namespace ch6 {

/**
 * @brief parent
 */
template<typename Iter>
inline Iter parent(Iter first, Iter curr)
{
    return first + (curr - first - 1)/ 2;
}

/**
 * @brief left child
 */
template<typename Iter>
inline Iter left(Iter first, Iter curr)
{
    return first + 2 * (curr - first) + 1;
}

/**
 * @brief right child
 */
template<typename Iter>
inline Iter right(Iter first, Iter curr)
{
    return first + 2 * (curr - first) + 2;
}

/**
 * @brief heapify
 * @param first
 * @param last
 * @param curr
 * @param compare
 *
 * @recurrence T(n) <= T(2n/3) + theta(1)
 * @complx  O(lg n)
 */
template<typename Iter, typename Comp = std::greater<IterValue<Iter> > >
void heapify(Iter first, Iter last, Iter curr, Comp&& compare = Comp())
{
    //! left and right child
    Iter l = left(first, curr), r = right(first, curr);

    //! find the max or min depending on Comp object
    auto max_min = (l < last    &&  compare(*l, *curr))?    l   :   curr;
    if(r < last     &&  compare(*r, *max_min))
            max_min = r;

    //! recur
    if(max_min != curr)
    {
        std::swap(*max_min, *curr);
        heapify(first, last, max_min, compare);
    }
}

/**
 * @brief heapify iteration version
 * @param first
 * @param last
 * @param curr
 * @param compare
 *
 * @recurrence T(n) <= T(2n/3) + theta(1)
 * @complx  O(lg n)
 *
 * for ex6.2-5
 */
template<typename Iter, typename Comp = std::greater<IterValue<Iter> > >
void heapify_itera(Iter first, Iter last, Iter curr, Comp&& compare = Comp())
{
    for(;;)
    {
        Iter l = left(first, curr);
        Iter r = right(first, curr);

        //! find max(or min) amoung curr, left and right.
        auto max_min = (l < last    &&  compare(*l, *curr))?    l   :   curr;
        if(r < last     &&  compare(*r, *max_min))
                max_min = r;

        //! exchange
        if(max_min != curr)
        {
            std::swap(*max_min, *curr);
            curr = max_min;
        }
        else    break;
    }
}

/**
 * @brief build_heap
 * @param first
 * @param last
 * @param compare
 *
 * @pseudocode  BUILD-MAX-HEAP, Page 157.
 * @complx  O(n)
 * @proof   Page 159.
 */
template<typename Iter,typename Comp = std::greater<IterValue<Iter> > >
inline void
build_heap(Iter first, Iter last, Comp&& compare = Comp())
{
    auto size = last - first;
    for(auto curr = first + size/2 - 1; curr != first - 1; --curr)
        heapify(first, last, curr, compare);
}

}}//namespace
#endif // HEAP_HPP

//! @test   heapify, heapify_itera.
//!
//#include <vector>
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "heap.hpp"

//int main()
//{
//    std::vector<int> v {16,4,10,14,7,9,3,2,8,1};
//    auto v2 = v;

//    clrs::ch6::heapify(v.begin(), v.end(), v.begin() + 1);
//    alan::print_container(v);

//    std::cout << "\n";

//    clrs::ch6::heapify_itera(v2.begin(), v2.end(), v2.begin() + 1);
//    alan::print_container(v2);

//    alan::end();
//    return 0;
//}
//! @output
//!
//16 4 10 14 7 9 3 2 8 1
//16 4 10 14 7 9 3 2 8 1
//exit normally

//! @test
//!
//#include <vector>
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "heap.hpp"

//int main()
//{
//    std::vector<int> v {4,1,3,2,16,9,10,14,8,7};
//    clrs::ch6::build_heap(v.begin(), v.end());
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}
//! @output
//!
//16 14 10 8 7 9 3 2 4 1
//exit normally
