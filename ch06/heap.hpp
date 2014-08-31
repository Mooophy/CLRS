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

template<typename Iter>
inline Iter parent(Iter first, Iter curr)
{
    return first + (curr - first - 1)/ 2;
}

template<typename Iter>
inline Iter left(Iter first, Iter curr)
{
    return first + 2 * (curr - first) + 1;
}


template<typename Iter>
inline Iter right(Iter first, Iter curr)
{
    return first + 2 * (curr - first) + 2;
}

template<typename Iter, typename Comp = std::greater<IterValue<Iter> > >
void heapify(Iter first, Iter last, Iter curr, Comp compare = Comp())
{
    Iter l = left(first, curr), r = right(first, curr);

    auto max_min = (l < last    &&  compare(*l, *curr))?    l   :   curr;
    if(r < last     &&  compare(*r, *max_min))
            max_min = r;

    if(max_min != curr)
    {
        std::swap(*max_min, *curr);
        heapify(first, last, max_min, Comp());
    }

}

}}//namespace
#endif // HEAP_HPP


