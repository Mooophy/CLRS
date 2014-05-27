/***************************************************************************
 *  @file       queue.hpp
 *  @author     Alan.W
 *  @date       25  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H
#include <vector>
#include <assert.h>

namespace ch10
{
template<typename T, typename C = std::vector<T> >
class queue;

template<typename T>
bool operator ==(const ch10::queue<T>& lhs, const ch10::queue<T>& rhs);

/**
 * @brief The queue class
 *
 * a simple queue using std::vector as the underlying
 * container and iterators as head and tail.
 *
 * check page 235 for detail.
 */
template<typename T, typename C>
class queue
{
    friend bool operator ==<T>(const queue<T>&, const queue<T>&);
public:
    using Container = C;
    using Iter      = typename Container::iterator;
    using SizeType  = typename Container::size_type;

    /**
     * @brief ctor
     * @param size
     */
    explicit queue(std::size_t size):
        c(size)
    {
         head = tail = c.begin();
    }

    /**
     * @brief enqueue
     * @param val
     *
     * based on Page 235
     */
    void enqueue(const T& val)
    {
        assert(!full() && "overflow");

        if(tail == c.end())
            tail = increment(tail);

        *tail = val;
        tail = increment(tail);
    }

    /**
     * @brief dequeue
     *
     * based on Page 235
     */
    T dequeue()
    {
        assert(!empty() && "underflow");

        T ret = *head;
        head = increment(head);

        if(head == c.end())
            head = increment(head);

        return ret;
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
        return head == increment(tail) ;
    }

    /**
     * @brief return the max number of elements that can be held.
     */
    SizeType capacity() const
    {
        return c.size();
    }

    /**
     * @brief return how many elements are being held
     */
    SizeType size() const
    {
        return ( tail >= head )?    tail - head     :   capacity() - (head - tail);
    }

private:
    Container c;
    Iter head;
    Iter tail;

    /**
     * @brief increment
     * @param iter
     *
     * increment iterator or go back to begin when reached end.
     */
    Iter increment(Iter iter)
    {
        return (iter == c.end())?   c.begin()    :   iter + 1 ;
    }
};

/**
 * @brief operator ==
 *
 * compare two ch10::queue objects
 * to be used in ch10::stack_by_2queues.
 */
template<typename T>
inline bool
operator ==(const ch10::queue<T>& lhs, const ch10::queue<T>& rhs)
{
    return (lhs.c == rhs.c) && (lhs.head == rhs.head) && (lhs.tail == rhs.tail);
}
}//namespace


#endif // QUEUE_H
