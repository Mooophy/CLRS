/***************************************************************************
 *  @file       selection_sort.hpp
 *  @author     Alan.W
 *  @date       24  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

//!
//! ex 2.2-2 Selection-Sort
//!


#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <functional>

namespace clrs {namespace ch2 {

template<typename Iter>
void selection_sort(Iter first, Iter last)
{
    using Lamda =   std::function<Iter(Iter,Iter)>;
    Lamda min   =   [](Iter first, Iter last)->Iter
    {
        auto ret = first;
        for(auto it = first; it != last; ++it)
            if(*ret > *it)  ret = it;
        return ret;
    };

    for(auto it = first; it != last - 1; ++it)
        std::swap(*it, *min(it, last));
}


}}//namespace
#endif // SELECTION_SORT_HPP
