/***************************************************************************
 *  @file       deue.hpp
 *  @author     Alan.W
 *  @date       26  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <vector>

namespace ch10 {

template<typename T>
class deque
{
public:
    using Container = std::vector<T>;
    using Iter      = typename Container::iterator;
    using SizeType  = typename Container::size_type;

    /**
     * @brief deque
     * @param sz    size of the underlying container
     */
    explicit deque(SizeType sz) :
        c(sz), head(0), tail(0)
    {}


    /**
     * @brief size
     */
    SizeType size() const
    {
        return c.size;
    }

    /**
     * @brief empty
     */
    bool empty() const
    {
        return head == tail;
    }

    /**
     * @brief full
     */
    bool full()
    {
        return (decrement(head) == tail) || (head == increment(tail));
    }


private:
    Container c;
    Iter head;
    Iter tail;

    /**
     * @brief increment
     *
     * increment iterator or go back to begin when reached end.
     */
    Iter increment(Iter iter)
    {
        return ( iter == c.end() )?   c.begin()    :   iter + 1 ;
    }

    /**
     * @brief decrement
     *
     * decrement iterator or jump to end when reached begin.
     */
    Iter decrement(Iter iter)
    {
        return ( iter == c.begin() )?     c.end()     :   iter - 1;
    }
};
}//namespace

#endif // DEQUE_HPP
