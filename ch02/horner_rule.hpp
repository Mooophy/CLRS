/***************************************************************************
 *  @file       horner_rule.hpp
 *  @author     Alan.W
 *  @date       27  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! @problem 2-3 Correctness of Horner’s rule
//!

#ifndef HORNER_RULE_HPP
#define HORNER_RULE_HPP

#include "iterator.hpp"

namespace clrs {namespace ch2 {

/**
 * @brief horner_rule
 * @param first
 * @param last
 * @param x
 *
 * @ex  problem 2-3
 * @complx  O(n)
 */
template<typename Iter>
inline clrs::IterValue<Iter>
horner_rule(Iter first, Iter last, const clrs::IterValue<Iter>& x)
{
    clrs::IterValue<Iter> ret = 0;
    for(auto it = last - 1; it != first - 1; --it)
        ret = *it + x * ret;

    return ret;
}

}}//namespace

#endif // HORNER_RULE_HPP

//! @test   horner_rule for problem 2-3
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "horner_rule.hpp"

//int main()
//{
//    std::vector<int> v{1,6,88,2,3,77};
//    auto ret = clrs::ch2::horner_rule(v.begin(), v.end(),3);
//    std::cout << ret;

//    alan::end();
//    return 0;
//}
//! @output
//!
//19819
//exit normally
