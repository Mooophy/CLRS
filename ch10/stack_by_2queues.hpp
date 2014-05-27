/***************************************************************************
 *  @file       stack_by_2queues.hpp
 *  @author     Alan.W
 *  @date       27  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! ex10.1-7
//! Show how to implement a stack using two queues. Analyze the running time of the
//! stack operations.
//!
//! class
/*      stack_by_2queues{
 * 1        push(val)
 * 2        pop()
 * 3        queue left
 * 4        queue right
 * 5        move(source, destination)
 * 6        push_which()
 * 7        pop_which()
 * 8    }
 */

//!     push_which()
/* 1    if left.empty()
 * 2        return left&
 * 3    else    return right&
 */

//!     pop_which()
/* 1    if  left.empty()
 * 2        return right&
 * 3    else    return left&
 */

//!     move(source, destination)
/* 1    while(! source.empty())
 * 2        destination.enqueque(source.dequeue())
 */

//!     push(val)
/* 1    def destination = push_which()
 * 2    destination.enqueue(val)
 * 3    def source = (destination == left)? right& : left&
 * 4    move(source, destination)
 */
//!     pop()
/* 1    def target = pop_which()
 * 2    def ret = target.top()
 * 3    target.pop()
 * 4    return ret
 */
#ifndef STACK_BY_2QUEUES_HPP
#define STACK_BY_2QUEUES_HPP

#include <queue.hpp>

namespace ch10 {

/**
 * @brief stack_by_2queues
 *
 * stack implemented by using two queues, as required in ex10.1-7
 */
template<typename T>
class stack_by_2queues
{
public:
    using ValueType = T;
    using Queue     = ch10::queue<ValueType>;
    using SizeType  = typename Queue::SizeType;

    /**
     * @brief ctor
     */
    explicit stack_by_2queues(SizeType sz):
        left(sz),right(sz)
    {}

    /**
     * @brief push
     *
     * @complexity  theta( size + 1)
     */
    void push(const ValueType& val)
    {
        Queue& destination = which_to_push();
        destination.enqueue(val);

        Queue& source = (destination == left)?  right   :   left;
        move(source, destination);
    }

    /**
     * @brief pop
     * @return  the top element by value
     *
     * @complexity  theta(1)
     */
    ValueType pop()
    {
        Queue& target = which_to_pop();
        return target.dequeue();
    }

private:
    Queue left;
    Queue right;

    /**
     * @brief return the empty queue to push.
     */
    Queue& which_to_push()
    {
        return left.empty()?    left    :   right;
    }

    /**
     * @brief return the not empty queue to pop.
     */
    Queue& which_to_pop()
    {
        return left.empty()?    right   :   left;
    }

    /**
     * @brief move
     *
     * @complexity  theta(size)
     *
     * move all elments from source queue to destination queue.
     */
    void move(Queue& source, Queue& destination)
    {
        while(!source.empty())
            destination.enqueue(source.dequeue());
    }
};

}//namespace

#endif // STACK_BY_2QUEUES_HPP
