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

}//namespace std

namespace ch15 {




}//namespace ch15
#endif // LONGEST_MONO_INCREASING_SUBSEQ_HPP

//! @test operator + for two std container
//!
//#include <iostream>
//#include "color.hpp"
//#include "longest_mono_increasing_subseq.hpp"
//#include <vector>

//int main()
//{
//    std::vector<int> lhs = {1,2,3};
//    std::vector<int> rhs = {4,5,6};
//    auto ret = lhs + rhs;

//    for(auto elem : ret)
//        std::cout << elem << " ";

//    std::cout << color::red("\nend\n");
//    return 0;
//}
//! @output:
//!
//1 2 3 4 5 6
//end
