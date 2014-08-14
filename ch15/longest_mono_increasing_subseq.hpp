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
#include <vector>
#include <algorithm>
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
 * @brief find the longest mono increasing subsequence
 * @param rng
 * @param threshold
 *
 * @complx  O(2^n)
 * @pyseudocode      a python code on SO:
 * http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
 *
 * for ex15.4-5, this one takes O(2^n).
 */
template<typename Range>
inline Range
find_lmis(const Range& rng,
          const typename Range::value_type* threshold = nullptr)
{
    //! trivial case
    if(rng.empty())    return rng;

    auto first  =   rng.begin();
    auto last   =   rng.end();

    Range case_1    =   find_lmis(Range(first + 1, last), threshold);

    Range case_2(0);
    if(!threshold || *first > *threshold)
        case_2  =   *first + find_lmis(Range(first + 1, last), &*first);

    return case_2.size() >= case_1.size()?     case_2   :   case_1;
}

/**
 * @brief find the longest mono increasing subsequence, the O(n^2) version
 * @param sequence
 *
 * @complx          O(n^2)
 * @extra space     O(n)
 * @note    shared pointer for implementing None in python.
 *
 * based on a python code found on SO, check the folder in_python for copy.
 * for ex15.4-5
 */
template<typename Range>
inline Range
find_lmis_On2(const Range& sequence)
{
    //! types def
    using SizeType  =   typename Range::size_type;
    using sPointer  =   std::shared_ptr<SizeType>;
    using Vector    =   std::vector<sPointer>;

    //! init vectors of pointers
    Vector  ends, back_ref;
    SizeType best_end = 0;

    //! nested loops causes to O(n^2)
    for(SizeType curr = 0; curr != sequence.size(); ++curr)
    {
        ends.push_back(std::make_shared<SizeType>(1));
        back_ref.push_back(nullptr);

        for(SizeType prev = 0; prev != curr; ++ prev)
        {
            auto through_prev   =   *ends[prev] + 1;
            if(sequence[prev] < sequence[curr]  &&  through_prev > *ends[curr])
            {
                *ends[curr]     =   through_prev;
                back_ref[curr]  =   std::make_shared<SizeType>(prev);
            }
        }

        //! update
        if(ends[curr]   >   ends[best_end])
            best_end    =   curr;
    }

    //! build ret
    Range ret;
    sPointer curr_back_ref = std::make_shared<SizeType>(best_end);
    while(curr_back_ref)
    {
        ret.push_back(sequence[*curr_back_ref]);
        curr_back_ref   =   back_ref[*curr_back_ref];
    }

    std::reverse(ret.begin(), ret.end());
    return ret;
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

//! @test   the O(n^2) version
//! for ex15.4-5
//#include <iostream>
//#include <vector>
//#include "color.hpp"
//#include "alan.hpp"
//#include "longest_mono_increasing_subseq.hpp"

//int main()
//{
//    std::vector<int> v = {1,2,5,3,4};
//    auto lmis = ch15::find_lmis_On2(v);
//    alan::print_container(lmis);

//    std::cout << color::red("\nend\n");
//    return 0;
//}
//! @output:
//!
//1 2 3 4
//end

