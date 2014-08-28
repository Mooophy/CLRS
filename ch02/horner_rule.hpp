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

/**
 * @brief power
 * @param order
 * @param x
 *
 * @ex  problem 2-3 part c
 * @complx  O(n)
 */
template<typename ValueType>
inline ValueType
power(int order, const ValueType& x)
{
    return  order > 0?    x * power(order - 1, x) :   1;
}

/**
 * @brief naive polynomial evaluate
 * @param first
 * @param last
 * @param x
 *
 * @complx  O(n^2)
 */
template<typename Iter>
clrs::IterValue<Iter>
polynomial_evaluate(Iter first, Iter last, const clrs::IterValue<Iter>& x)
{
    IterValue<Iter> ret = 0;
    int order = 0;
    for(auto it = first; it != last; ++it)
        ret     +=      *it  *   power(order++, x);

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

//    auto by_horner  =   clrs::ch2::horner_rule(v.begin(), v.end(),3);
//    auto by_naive   =   clrs::ch2::polynomial_evaluate(v.begin(), v.end(), 3);
//    std::cout << "by horner : " << by_horner << std::endl;
//    std::cout << "by naive  : " << by_naive  << std::endl;

//    alan::end();
//    return 0;
//}

//! @output
//!
//by horner : 19819
//by naive  : 19819

//exit normally

