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
#include <assert.h>

namespace ch10 {

/**
 * @brief The deque class template
 *
 * check ex10.1-5 page 236 for detail
 */
template<typename T>
class deque
{
public:
    using Container = std::vector<T>;
    using Iter      = typename Container::iterator;
    using SizeType  = typename Container::size_type;

    /**
     * @brief ctor
     * @param sz    size of the underlying container
     */
    explicit deque(SizeType sz) :
        c(sz)
    {
        head = tail = c.begin();
    }


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

    /**
     * @brief return top
     */
    const T& front () const
    {
        assert(!empty());

        return *head;
    }

    /**
     * @brief return back
     */
    const T& back() const
    {
        assert(!empty());
        return *tail;
    }

    /**
     * @brief push_front
     */
    void push_front(const T& val)
    {
        assert(!full());

        if(head == c.end())
            head = decrement(head);

        *head = val;
        head = decrement(head);
    }

    /**
     * @brief push_back
     */
    void push_back(const T& val)
    {
        assert(!full());

        if(tail == c.end())
            tail = increment(tail);

        *tail = val;
        tail = increment(tail);
    }

    /**
     * @brief pop_front
     */
    void pop_front()
    {
        assert(!empty());
        head = increment(head);
    }

    /**
     * @brief pop_back
     */
    void pop_back()
    {
        assert(!empty());
        tail = decrement(tail);
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
