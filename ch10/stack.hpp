/***************************************************************************
 *  @file       stack.hpp
 *  @author     Alan.W
 *  @date       25  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <vector>
#include <assert.h>

namespace ch10
{

/**
 * @brief The stack class
 *
 * any container that supports empty(), push_back()
 * back() and pop_back can be used as the underlying
 * container,such as vector deque and list, or ones
 * users defined.
 */
template<typename T, typename C = std::vector<T> >
class stack
{
public:
    using ValueType = T;
    using Container = C;
    using SizeType  = typename Container::size_type;

    /**
     * @brief default ctor
     *
     * using the specified underlying container.
     */
    stack() :
        c()
    {}

    /**
     * @brief check if empty
     *
     * @complexity O(1)
     */
    bool empty()
    {
        return c.empty();
    }

    /**
     * @brief size
     */
    SizeType size() const
    {
        return c.size();
    }

    /**
     * @brief push
     *
     * @complexity O(1)
     */
    void push(const ValueType& val)
    {
        c.push_back(val);
    }

    /**
     * @brief pop
     *
     * @complexity O(1)
     */
    void pop()
    {
        assert(!c.empty());
        c.pop_back();
    }

    /**
     * @brief top
     *
     * @complexity O(1)
     */
    ValueType& top()
    {
        assert(!c.empty());
        return c.back();
    }
private:
    Container c;
};

}//namespace


#endif // STACK_H
