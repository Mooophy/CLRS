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
