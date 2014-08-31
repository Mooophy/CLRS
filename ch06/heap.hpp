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
void heapify(Iter first, Iter last, Iter curr, Comp compare = Comp())
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
void heapify_itera(Iter first, Iter last, Iter curr, Comp compare = Comp())
{
    while(true)
    {
        //! left and right child
        Iter l = left(first, curr), r = right(first, curr);

        //! find the max or min depending on Comp object
        auto max_min = (l < last    &&  compare(*l, *curr))?    l   :   curr;
        if(r < last     &&  compare(*r, *max_min))
                max_min = r;

        //! iteration or break
        if(max_min != curr)
        {
            std::swap(*max_min, *curr);
            curr = max_min;
        }
        else    break;
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
//    clrs::ch6::heapify(v.begin(), v.end(), v.begin());
//    alan::print_container(v);

//    std::cout << "\n";

//    auto v2 = v;
//    clrs::ch6::heapify(v.begin(), v.end(), v.begin());
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}
//! @output
//!
//16 4 10 14 7 9 3 2 8 1
//16 4 10 14 7 9 3 2 8 1
//exit normally

