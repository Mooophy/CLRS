/***************************************************************************
 *  @file       queue.h
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

/**
 * @brief The queue class
 *
 * a simple queue using std::vector as the underlying
 * container and iterators as head and tail.
 *
 * check page 235 for detail.
 */
template<typename T>
class queue
{
public:
    using Container = std::vector<T>;
    using Iter      = typename Container::iterator;

    /**
     * @brief default ctor
     * @param size
     */
    explicit queue(std::size_t size):
        c(size + 1), head(c.begin()), tail(c.begin())
    {}

    /**
     * @brief enqueue
     * @param val
     *
     * based on Page 235
     */
    void enqueue(const T& val)
    {
        assert(!full());

        *tail++ = val;
        if (tail == c.end())
            tail = c.begin();
    }

    /**
     * @brief dequeue
     *
     * based on Page 235
     */
    T dequeue()
    {
        assert(!empty());

        T ret = *head++;
        if(head == c.end())
            head = c.begin();

        return ret;
    }

    bool empty() const
    {
        return head == tail;
    }

    bool full () const
    {
        return (head == tail + 1) || (head == c.begin() && tail == c.end() -1) ;
    }


private:
    Container c;
    Iter head;
    Iter tail;
};
}


#endif // QUEUE_H
