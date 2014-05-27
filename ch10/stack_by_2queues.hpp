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

#endif // STACK_BY_2QUEUES_HPP
