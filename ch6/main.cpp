/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       19  May 2014
 *  @remark     This code is for Introduction to Algorithms 3rd
 *  @note       code style : STL,BOOSTs
 ***************************************************************************/

#include <vector>
#include <iterator>
#include <iostream>
#include "Young_tableau.h"

//!
//! Problem 6 - 3, d
//! Using no other sorting method as a subroutine, show how to use an n * n Young
//! tableau to sort n^2 numbers in O(n^3) time.
//!

template<typename Iter>
inline void sort_YT(Iter first, Iter last)
{
    using ValueType = typename std::iterator_traits<Iter>::value_type;

    ch6::Young_tableau<ValueType> yt(3,3);
    for(Iter iter = first; iter != last; ++iter)
    {

    }
}


int main()
{




    return 0;
}

