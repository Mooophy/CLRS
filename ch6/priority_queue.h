/***************************************************************************
 *  @file       priority_queue.h
 *  @author     Alan.W
 *  @date       15  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//! this file implements a stl like priority queue using the algorithms from CLRS and

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <functional>
#include <vector>
#include <iterator>
#include <assert.h>


namespace ch6 {

/**
 *  @brief  priority_queue class template
 *
 *  @note   using the algorithms from CLRS
 *          std::vector is the underlying container.
 *
 *  @note   std::greater<T> for max priority_queue
 *          std::less<T>    for min priority_queue
 *
 */
template<typename T, typename Compare = std::greater<T> >
class priority_queue
{
public:
    using ValueType = T;
    using SizeType  = typename std::vector<ValueType>::size_type;
    using Iter      = typename std::vector<ValueType>::iterator;

    /**
     * @brief default ctor
     */
    priority_queue()= default;

    /**
     * @brief priority_queue
     * @param v:    std::vector
     */
    explicit priority_queue(const std::vector<ValueType>& v):
        container(v)
    {}

    /**
     * @brief size
     * @return  the size of this priority_queue.
     */
    SizeType size()
    {
        return container.size();
    }

    /**
     * @brief dtor
     */
    ~priority_queue(){}

private:
    std::vector<ValueType> container;

    /**
     * @brief parent
     * @complexity  constant
     */
    Iter parent(Iter first, Iter target)
    {
        assert(first <= target);
        if(first == target)
            return target;
        else
            return first + (target - first - 1)/2;
    }

    /**
     * @brief left
     * @complexity  constant
     */
    Iter left(Iter first, Iter target)
    {
        assert(first <= target);
        return first + 2 * (target - first) + 1;
    }

    /**
     * @brief right
     * @complexity  constant
     */
    Iter right(Iter first, Iter target)
    {
        assert(first <= target);
        return first + 2 * (target - first + 1);
    }

    void heapify();
};





}//namespace

#endif // PRIORITY_QUEUE_H
