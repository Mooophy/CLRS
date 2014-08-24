/***************************************************************************
 *  @file       selection_sort.hpp
 *  @author     Alan.W
 *  @date       24  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

//!
//! ex2.2-2 Selection-Sort
//!

#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <functional>

namespace clrs {namespace ch2 {

/**
 * @brief selection_sort
 * @param first
 * @param last
 *
 * @ex2.2-2
 * @complx  O(n^2)
 */
template<typename Iter>
void selection_sort(Iter first, Iter last)
{
    //! define a lambda to find the minimum element
    using Lamda =   std::function<Iter(Iter,Iter)>;
    Lamda min   =   [](Iter first, Iter last)->Iter
    {
        auto ret = first;
        for(auto it = first; it != last; ++it)
            if(*ret > *it)  ret = it;
        return ret;
    };

    //! sort with lambda min()
    for(auto it = first; it != last - 1; ++it)
        std::swap(*it, *min(it, last));
}

}}//namespace
#endif // SELECTION_SORT_HPP

//! @test   selection_sort for ex2.2-2
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "selection_sort.hpp"

//int main()
//{
//    std::vector<int> v{1,6,88,2,0,77};
//    clrs::ch2::selection_sort(v.begin(), v.end());
//    alan::print_container(v);

//    alan::end();
//    return 0;
//}
//! @output
//!
//0 1 2 6 77 88
//exit normally
