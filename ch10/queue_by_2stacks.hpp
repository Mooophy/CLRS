/***************************************************************************
 *  @file       queue_by_2stacks.hpp
 *  @author     Alan.W
 *  @date       27  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 *  @attention  bug found, check issue #2 for detail.
 ***************************************************************************/
//!
//! ex10.1-6
//! Show how to implement a queue using two stacks. Analyze the running time of the
//! queue operations.
//!
//! class
/*      class queue_by_2stacks{
 * 1        enqueue()
 * 2        dequeue()
 * 3        stack in
 * 4        stack out
 * 5        move(source, destination)
 * 6    }
 */

//! move
//! complexity  :   theta(size)
/*      move(source, destination)
 * 1    while !souce.empty()
 * 2        destination.push(source.pop)
 */

//! enqueue
//! complexity   :   theta(size + 1) for worst case
//!                  theta(1)        for best case
/*      enqueue(val)
 * 1    move(out, in)
 * 2    in.push(val)
 */

//! dequeue
//! complexity   :   theta(size + 1) for worst case
//!                  theta(1)        for best case
/*      dequeue()
 * 1    move(in, out)
 * 2    return out.pop()
 */


#ifndef QUEUE_BY_2STACKS_HPP
#define QUEUE_BY_2STACKS_HPP

#include "stack.hpp"

namespace ch10 {

/**
 * @brief queue_by_2stacks
 *
 * Implementing a queue using two stacks, as required by ex10.1-6.
 */
template<typename T>
class queue_by_2stacks
{
public:
    using ValueType = T;
    using SizeType  = typename ch10::stack<ValueType>::SizeType;

    /**
     * @brief enqueue
     *
     * @complexity  theta(size + 1) for worst case
     *              theta(1)        for best case
     */
    void enqueue(const ValueType& val)
    {
        move(out, in);
        in.push(val);
    }

    /**
     * @brief dequeue
     *
     * @complexity  theta(size + 1) for worst case
     *              theta(1)        for best case
     */
    ValueType dequeue()
    {
        move(in, out);
        ValueType ret = out.top();
        out.pop();

        return ret;
    }

    /**
     * @brief size
     */
    SizeType size() const
    {
        return in.size() + out.size();
    }


private:
    ch10::stack<ValueType> in;
    ch10::stack<ValueType> out;

    /**
     * @brief move
     * @param source
     * @param destination
     *
     * move elements from source stack to destination stack.
     */
    void move(ch10::stack<ValueType>& source, ch10::stack<ValueType>& destination)
    {
        while(!source.empty())
        {
            destination.push(source.top());
            source.pop();
        }
    }
};

}//namespace

#endif // QUEUE_BY_2STACKS_HPP
