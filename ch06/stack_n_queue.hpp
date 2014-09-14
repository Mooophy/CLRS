/***************************************************************************
 *  @file       stack_n_queue.hpp
 *  @author     Yue Wang
 *  @date       14  Sep 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! ex6.5-7 stack and queue by priority queue.
//!

#ifndef STACK_N_QUEUE_HPP
#define STACK_N_QUEUE_HPP

#include "element.hpp"
#include "priority_queue.hpp"
#include <functional>

namespace clrs {namespace ch6 {

/**
 * @brief   The StaQue class
 * @note    use std::greater for stack
 *          use std::less    for queue
 *          check test codes below for detail
 */
template<typename T, typename Comp>
class StaQue
{
public:
    using PriorityType      =   typename Element<T>::PriorityType;
    using PriorityQueueType =   PriorityQueue<Element<T>>;
    using SizeType          =   typename PriorityQueue<T>::SizeType;

    StaQue():
        pq{Comp{}},
        priority{0}
    {}

    void push(const T& val)
    {
        pq.push({val, priority++});
    }

    const T& top()const
    {
        return pq.top().data;
    }

    void pop()
    {
        pq.pop();
    }

    bool empty()const
    {
        return pq.empty();
    }

private:
    PriorityQueueType pq;
    PriorityType priority;
};

}}//namepsace
#endif // STACK_N_QUEUE_HPP

//! @test   for ex6.5-7 stack part.
//!
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "stack_n_queue.hpp"

//int main()
//{
//    using namespace clrs::ch6;
//    StaQue<int,decltype(std::greater<Element<int> >{})> stack;

//    stack.push(42);
//    stack.push(41);
//    stack.push(40);

//    while(! stack.empty())
//    {
//        std::cout << stack.top() << " ";
//        stack.pop();
//    }

//    alan::end();
//    return 0;
//}
//! @output
//!
//40 41 42
//exit normally

//! @test   for ex6.5-7 queue part.
//!
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "stack_n_queue.hpp"

//int main()
//{
//    using namespace clrs::ch6;
//    StaQue<int,decltype(std::less<Element<int> >{})> queue;

//    queue.push(42);
//    queue.push(41);
//    queue.push(40);

//    while(! queue.empty())
//    {
//        std::cout << queue.top() << " ";
//        queue.pop();
//    }

//    alan::end();
//    return 0;
//}
//! @output
//!
//42 41 40
//exit normally
