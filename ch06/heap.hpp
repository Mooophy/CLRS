/***************************************************************************
 *  @file       heap.hpp
 *  @author     Yue Wang
 *  @date       30  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
#ifndef HEAP_HPP
#define HEAP_HPP

namespace clrs { namespace ch6 {

/**
 * @brief parent
 */
template<typename SizeType>
inline SizeType parent (SizeType index)
{
    return (index - 1)/2;
}

/**
 * @brief left
 */
template<typename SizeType>
inline SizeType left (SizeType index)
{
    return 2 * index + 1;
}

/**
 * @brief right
 */
template<typename SizeType>
inline SizeType right (SizeType index)
{
    return 2 * index + 2;
}


}}

#endif // HEAP_HPP
