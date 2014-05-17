/***************************************************************************
 *  @file       priority_queue.h
 *  @author     Alan.W
 *  @date       17  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <functional>
#include <vector>
#include <iterator>
#include <iostream>
#include <assert.h>

namespace ch6 {

template<typename T>
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
     * @brief ctor
     */
    explicit priority_queue(const std::vector<ValueType>& v,
                            CompareType c = std::greater<ValueType>()):
        container(v), compare(c)
    {
        build_heap();
    }

    /**
     * @brief size
     */
    SizeType size() const
    {
        return container.size();
    }

    /**
     * @brief top
     *
     * i.e. HEAP-MAXIMUM OR HEAP-MINIMUM in CLRS. (Page 163)
     */
    const ValueType& top() const
    {
        assert(!empty());
        return *container.begin();
    }

    /**
     * @brief return if empty
     */
    bool empty() const
    {
        return container.empty();
    }


    /**
     * @brief pop
     *
     * @complexity  O(lg n)
     *
     * i.e. HEAP-EXTRACT-MAX or HEAP-EXTRACT-MIN in CLRS. (Page 163)
     */
    void pop()
    {
        assert(size() >= 1);
        *begin() = *(end() - 1);
        container.resize(size() - 1);

        if(size() > 1)
            heapify(begin());
    }

    /**
     * @brief push
     *
     * @complexity O(lg n)
     *
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
        Iter iter   = end() - 1;
        while(iter > begin() && compare(new_value, *parent(iter)))
        {
            *iter = *parent(iter);
            iter = parent(iter);
        }
        *iter = new_value;
    }

    /**
     * @brief dtor
     */
    ~priority_queue() = default;


private:
    std::vector<ValueType> container;
    CompareType compare = std::greater<ValueType>();

    /**
     * @brief begin
     */
    Iter begin()
    {
        return container.begin();
    }

    /**
     * @brief end
     */
    Iter end()
    {
        return container.end();
    }

    /**
     * @brief parent
     *
     * @complexity  constant
     */
    Iter parent(Iter target)
    {
        assert(target >= begin());
        if(target == begin())
            return target;
        else
            return begin() + (target - begin() - 1)/2;
    }

    /**
     * @brief left
     *
     * @complexity  constant
     */
    Iter left(Iter target)
    {
        assert(target >= begin());
        return begin() + 2 * (target - begin()) + 1;
    }

    /**
     * @brief right
     *
     * @complexity  constant
     */
    Iter right(Iter target)
    {
        assert(target >= begin());
        return begin() + 2 * (target - begin() + 1);
    }

    /**
     * @brief heapify
     *
     * @complexity  O(lg n)
     */
    void heapify(Iter target)
    {
        assert((target >= begin()) && (target < end()));

        Iter l = left(target);
        Iter r = right(target);

        //! extreme stands for largest or smallest depending on max or min priority queue
        Iter extreme = (l < end()  &&  compare(*l, *target))?     l   :   target;

        if(r < end()  &&  compare(*r, *extreme))
            largest_or_smallest = r;

        if(extreme != target){
            std::swap(*target, *extreme);
            heapify(extreme);
        }
    }

    /**
     * @brief build_heap
     *
     * @complexity  O(n)
     */
    void build_heap()
    {
        if(size() > 1)
            for(Iter iter = begin() + size()/2 - 1; iter != begin() - 1; --iter)
                heapify(iter);
    }
};
}//namespace

#endif // PRIORITY_QUEUE_H
