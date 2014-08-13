/***************************************************************************
 *  @file       longest_mono_increasing_subseq.hpp
 *  @author     alan.w
 *  @date       13  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 ***************************************************************************/

#ifndef LONGEST_MONO_INCREASING_SUBSEQ_HPP
#define LONGEST_MONO_INCREASING_SUBSEQ_HPP

#include <memory>
#include <limits>
#include "matrix.hpp"

namespace std {

/**
 * @brief operator +
 * @param lhs
 * @param rhs
 *
 * concatenate two std containers, like two std::vector.
 * implemented for longest_mono_increasing_subseq
 *
 * @attention   this function copy all values from the two containers, so not efficient.
 *              only used for algorithms presentations.
 *
 *              extending std namespace.
 */
template<typename Range>
inline Range
operator +(const Range& lhs, const Range& rhs)
{
    Range ret;
    ret.insert(ret.end(), lhs.begin(), lhs.end());
    ret.insert(ret.end(), rhs.begin(), rhs.end());

    return ret;
}

/**
 * @brief operator +
 * @param lhs   range
 * @param rhs   val
 */
template<typename Range>
inline Range
operator + (const Range& lhs, const typename Range::value_type& rhs)
{
    Range ret = lhs;
    ret.push_back(rhs);

    return ret;
}

/**
 * @brief operator +
 * @param lhs   val
 * @param rhs   range
 */
template<typename Range>
inline Range
operator +(const typename Range::value_type& lhs, const Range& rhs)
{
    Range ret;
    ret.push_back(lhs);

    return ret + rhs;
}
}//namespace std

namespace ch15 {




}//namespace ch15
#endif // LONGEST_MONO_INCREASING_SUBSEQ_HPP

//! @test the three operator+
//!
//#include <iostream>
//#include "color.hpp"
//#include "longest_mono_increasing_subseq.hpp"
//#include <vector>

//int main()
//{
//    std::vector<int> lhs = {1,2,3};
//    std::vector<int> rhs = {4,5,6};

//    for(auto elem : (lhs + rhs))
//        std::cout << elem << " ";
//    std::cout << std::endl;

//    for(auto elem : (lhs + 99))
//        std::cout << elem << " ";
//    std::cout << std::endl;

//    for(auto elem : (99 + rhs))
//        std::cout << elem << " ";
//    std::cout << std::endl;

//    std::cout << color::red("\nend\n");
//    return 0;
//}
//! @output:
//!
//1 2 3 4 5 6
//1 2 3 99
//99 4 5 6

//end

