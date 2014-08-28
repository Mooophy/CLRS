/***************************************************************************
 *  @file       iterator.hpp
 *  @author     Alan.W
 *  @date       22  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

namespace clrs {

/**
 *  @brief  aliasing for value type an iterator points to
 */
template<typename Iter>
using IterValue = typename std::iterator_traits<Iter>::value_type;

}

#endif // ITERATOR_HPP
