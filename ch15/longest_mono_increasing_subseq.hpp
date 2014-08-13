/***************************************************************************
 *  @file       longest_mono_increasing_subseq.hpp
 *  @author     alan.w
 *  @date       13  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 ***************************************************************************/

//! ex15.4-5
//!     Give an O(n^2)-time algorithm to find the longest monotonically increasing subse-
//!     quence of a sequence of n numbers.

#ifndef LONGEST_MONO_INCREASING_SUBSEQ_HPP
#define LONGEST_MONO_INCREASING_SUBSEQ_HPP

#include <memory>
#include <limits>
#include <iterator>
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

/**
 * @brief find_lmis
 * @param rest
 * @param bigger_than
 *
 * @complx  O(2^n)
 * based on a python code on SO:
 * http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
 * tested
 *
 * for ex15.4-5, but this one is just a recursion version taking O(2^n).
 */
template<typename Range>
inline Range
find_lmis(const Range& rest, const typename Range::value_type* bigger_than = nullptr)
{
    //! trivial case
    if(rest.empty())    return rest;

    Range best_sequence = find_lmis(Range(rest.begin() + 1, rest.end()), bigger_than);

    auto first = rest.front();
    if(bigger_than == nullptr || first > *bigger_than)
    {
        Range sequence_with =
                first + find_lmis(Range(rest.begin() + 1, rest.end()), &first);
        if(sequence_with.size() >= best_sequence.size())
            best_sequence   =   sequence_with;
    }

    return best_sequence;
}

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

//! @test   the O(2^n) version:
//!
//#include <iostream>
//#include <vector>
//#include "color.hpp"
//#include "longest_mono_increasing_subseq.hpp"

//int main()
//{
//    std::vector<int> v = {1,5,2,3,6,7,0,4,99};
//    auto lmis = ch15::find_lmis(v);
//    for(auto elem : lmis)
//        std::cout << elem << " ";

//    std::cout << color::red("\nend\n");
//    return 0;
//}
//! @output:
//!
//1 2 3 6 7 99
//end
