/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       17  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
#ifndef CUT_ROD_HPP
#define CUT_ROD_HPP

#include <algorithm>
#include <iterator>
#include <limits>

namespace ch15 {

template<typename Iter>
typename std::iterator_traits<Iter>::value_type
cut_rod(Iter first, typename std::iterator_traits<Iter>::difference_type len);

/**
 * @brief cut_rod
 *          return the optimal solution without using dynamic programming
 * @param first
 * @param len
 *
 * @complx  O(2^n)
 * @page    363, CLRS
 */
template<typename Iter>
inline typename std::iterator_traits<Iter>::value_type
cut_rod(Iter first, typename std::iterator_traits<Iter>::difference_type len)
{
    using ValueType =   typename std::iterator_traits<Iter>::value_type;
    using SizeType  =   typename std::iterator_traits<Iter>::difference_type;

    //! stop condition
    if(len == 0)
        return 0;

    //! initialize it as -infinity
    ValueType ret = std::numeric_limits<ValueType>::min();

    //! iteration with recursion
    for(SizeType count = 0 ; count != len ; ++count)
        ret =   std::max(ret, *(first + count) + cut_rod(first, len - count - 1));

    return ret;
}

}

#endif // CUT_ROD_HPP
