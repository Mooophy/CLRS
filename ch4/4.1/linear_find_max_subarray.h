/***************************************************************************
 *  @file       linear_find_max_subarray.h
 *  @author     Alan.W
 *  @date       28  Apr 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 *              ex4.1-5
 ***************************************************************************/

//!
//! for ex4.1-5
//! @idea
//! part one :  build a tuple container which stores the max subarray that ends at each
//!             element of the array
//! part two :  find the tuple with largest sum from the container built in part one
//!             and return it.
//! running time  n + n = 2n .That is, theta(n).
//! Hence, it's linear.
//!
//! @psyeudocode
/*      linear_find_max_subarray(first, last)
 * 1    assert(last > first)
 * 2    def vector<tuple(low,high, sum)>
 * 3    vector.push_back(tuple(first, first, *first))
 * 4    if (last - first == 1)
 * 5        return vector->begin
 * 6    else
 *          def iter_t = v.begin + 1
 * 7        def iter_a = first + 1
 * 8        while iter_a != last
 * 10           if (iter_t - 1)->sum <= 0
 * 11               iter_t->low = iter_t->high = iter_a
 * 12               iter_t->sum = *iter_a
 * 13           else
 *                  iter->high  = iter_a
 * 14               iter->sum   = (iter_t -1)->sum + *iter_a
 * 15           ++iter_a, ++iter_t
 * 16   def max = tuple(low(iter()), high(iter()), sum(value()))
 * 17   for(t : vector)
 * 18       if(t.sum > max.sum)
 * 19           max = t
 * 20   return max
 */

#ifndef LINEAR_FIND_MAX_SUBARRAY_H
#define LINEAR_FIND_MAX_SUBARRAY_H

#include <iterator>
#include <tuple>
#include <assert.h>
#include <vector>

//! find the max subarray in linear run time
template<typename Iter>
std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
linear_find_max_subarray(Iter first, Iter last);

//! find the max subarray in linear run time
template<typename Iter>
std::tuple<Iter, Iter, typename std::iterator_traits<Iter>::value_type>
linear_find_max_subarray(Iter first, Iter last)
{
    assert(last > first);

    //! types
    using ValueType = typename std::iterator_traits<Iter>::value_type;
    using Tuple     = typename std::tuple<Iter, Iter, ValueType>;
    using Iter_tpl  = typename std::vector<Tuple>::iterator;

    //! initialization
    auto size = std::distance(first, last);
    std::vector<Tuple> container(size);
    *container.begin() = std::make_tuple(first, first, *first);

    //! build the tuple container
    if(last - first == 1)
        return *container.begin();
    else
    {
        auto iter_t = container.begin() + 1;    // for tupple container
        Iter iter_a = first + 1;                // for the array being processed
        while(iter_a != last)
        {
            if(std::get<2>(*(iter_t - 1)) <= 0)
            {
                std::get<0>(*iter_t) = std::get<1>(*iter_t) = iter_a;
                std::get<2>(*iter_t) = *iter_a;
            }
            else
            {
                std::get<1>(*iter_t) = iter_a;
                std::get<2>(*iter_t) = *iter_a + std::get<2>(*(iter_t - 1));
            }
            ++iter_a;
            ++iter_t;
        }
    }

    //! find the larest one
    Tuple max = *container.begin();
    for(const auto& t : container)
        if(std::get<2>(t) > std::get<2>(max))    max = t;

    return max;
}
#endif // LINEAR_FIND_MAX_SUBARRAY_H
