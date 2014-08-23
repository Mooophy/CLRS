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

#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

template<typename Iter>
Iter binary_search(Iter first, Iter last, const IterValue<Iter>& val)
{
    auto mid_point = first + (last - first)/2;
    if(*mid_point   ==  val)
        return mid_point;
    else if(*mid_point > val)
        return binary_search(first, mid_point);
    else
        return binary_search(mid_point, last);

}


#endif // BINARY_SEARCH_HPP
