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
#include <iostream>
#include <assert.h>



namespace ch6 {
/**
 *  @brief  priority_queue class template
 *
 *  @note   using the algorithms from CLRS.
 *          using std::vector as the underlying container.
 *
 *  @note   std::greater<T> for max priority_queue
 *          std::less<T>    for min priority_queue 
 */
template<typename T, typename Compare = std::greater<T> >
class priority_queue
{
public:
    using ValueType     = T;
    using SizeType      = typename std::vector<ValueType>::size_type;
    using Iter          = typename std::vector<ValueType>::iterator;
    using CompareType   = std::function<bool(ValueType,ValueType)>;


    /**
     * @brief default ctor
     */
    priority_queue() = default;

    /**
     * @brief priority_queue
     * @param v:    std::vector
     */
    explicit priority_queue(const std::vector<ValueType>& v):
        container(v)
    {
        build_heap(container.begin(), container.end(), Compare());
    }

    /**
     * @brief size
     * @return  the size of this priority_queue.
     */
    SizeType size() const
    {
        return container.size();
    }

    /**
     * @brief top
     * i.e. HEAP-MAXIMUM OR HEAP-MINIMUM in CLRS. (Page 163)
     */
    const ValueType& top() const
    {
        return *container.begin();
    }

    /**
     * @brief pop
     * @complexity  O(lg n)
     * i.e. HEAP-EXTRACT-MAX or HEAP-EXTRACT-MIN in CLRS. (Page 163)
     */
    void pop()
    {
        assert(this->size() >= 1);
        *container.begin() = *(container.end() - 1);
        container.resize(this->size() - 1);
        if(this->size() > 1){
            heapify(container.begin(), container.end(), container.begin(), Compare());
        }
    }

    /**
     * @brief push
     * @param first
     * @param new_value
     * @param comp  std::greater<T> for max priority_queue
     *              std::less<T>    for min priority_queue
     * @complexity O(lg n)
     * @note revised using the idea from ex6.5-6
     *
     * Since neither increase_key nor decrease_key interface is provided in boost nor stl,
     * the push function combines the HEAP-INCREASE-KEY and MAX-HEAP-INSERT (or
     * HEAP-DECREASE-KEY and MIN-HEAP-INSERT) together.
     *
     */
    void push(const ValueType& new_value)
    {
        container.push_back(new_value);

        Iter first  = container.begin();
        Iter iter   = container.end() - 1;
        CompareType comp = Compare();
        while(iter > first && comp(new_value, *parent(first, iter))){
            *iter = *parent(first, iter);
            iter = parent(first, iter);
        }
        *iter = new_value;
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
    Iter parent(Iter first, Iter target) const
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
    Iter left(Iter first, Iter target) const
    {
        assert(first <= target);
        return first + 2 * (target - first) + 1;
    }

    /**
     * @brief right
     * @complexity  constant
     */
    Iter right(Iter first, Iter target) const
    {
        assert(first <= target);
        return first + 2 * (target - first + 1);
    }

    /**
     * @brief heapify
     * @param first
     * @param last
     * @param target
     * @param comp  std::greater<T> for max priority_queue
     *              std::less<T>    for min priority_queue
     * @complexity  O(lg n)
     */
    void heapify(Iter first, Iter last, Iter target, CompareType comp)
    {
        assert((first <= target) && (target < last));

        Iter l = left(first, target);
        Iter r = right(first,target);
        Iter largest_or_smallest = (l < last  &&  comp(*l, *target))?     l   :   target;
        //!                                       ^^^^^^^^^^^^^^^^^
        //!         @attention  :   std::greater<T>  for max priority queue
        //!                         std::less<T>     for min priority queue

        if(r < last  &&  comp(*r, *largest_or_smallest))
            largest_or_smallest = r;

        if(largest_or_smallest != target){
            std::swap(*target, *largest_or_smallest);
            heapify(first, last, largest_or_smallest, comp);
        }
    }

    /**
     * @brief build_heap
     * @param first
     * @param last
     * @param comp  std::greater<T> for max priority_queue
     *              std::less<T>    for min priority_queue
     * @complexity  O(n)
     */
    void build_heap(Iter first, Iter last, CompareType comp)
    {
        assert(last >= first);
        SizeType size = last - first;
        if(size > 1)
            for(Iter iter = first + size/2 - 1; iter != first - 1; --iter)
                heapify(first, last, iter, comp);
    }
};
}//namespace

#endif // PRIORITY_QUEUE_H
