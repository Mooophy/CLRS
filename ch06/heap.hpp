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
inline SizeType parent(SizeType target)
{
    return (target - 1)/2;
}

/**
 * @brief left
 */
template<typename SizeType>
inline SizeType left(SizeType index)
{
    return 2 * target + 1;
}

/**
 * @brief right
 */
template<typename SizeType>
inline SizeType right(SizeType index)
{
    return 2 * target + 2;
}

/**
 * @brief max_heapify
 * @param rng
 * @param curr
 */
template<typename Range>
void max_heapify(Range& rng, typename Range::size_type curr)
{
    auto l = left(curr);
    auto largest = (l < rng.size()  &&  rng[l] > rng[curr])?  l   :   curr;

    auto r = right(curr);
    if(r < rng.size()   &&  rng[r] > rng[largest])  largest = r;

    if(largest != curr)
    {
        std::swap(rng[largest], rng[curr]);
        max_heapify(rng, largest);
    }
}

}}//namespace

#endif // HEAP_HPP
