/***************************************************************************
 *  @file       queue.hpp
 *  @author     Yue Wang
 *  @date       30  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

#ifndef QUEQUE_HPP
#define QUEQUE_HPP

#include <element.hpp>
#include <priority_queue.hpp>

namespace clrs {namespace ch6 {

/**
 * @brief The Queue class
 *
 * for ex6.5-7 first part
 */
template<typename T>
class Queue
{
public:
    using PriorityType      =   typename Element<T>::PriorityType;
    using PriorityQueueType =   PriorityQueue<Element<T>>;
    using SizeType          =   typename PriorityQueue<T>::SizeType;

    /**
     * @brief Ctor
     */
    Queue():
        pq{std::less<Element<T> >{}},
        curr{0}
    {}

    /**
     * @brief push
     */
    void push(const T& added)
    {
        pq.push({added, curr++});
    }

    /**
     * @brief pop
     */
    T pop()
    {
        auto ret = pq.top().data;
        pq.pop();

        return ret;
    }

    /**
     * @brief size
     */
    SizeType size() const
    {
        return pq.size();
    }

    /**
     * @brief empty
     */
    bool empty() const
    {
        return pq.empty();
    }

private:
    PriorityQueueType pq;
    PriorityType curr;
};

}}//namespace
#endif // QUEQUE_HPP

//! @test   Queue   pop and push
//!
//#include <vector>
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "queue.hpp"

//int main()
//{
//    using namespace clrs::ch6;
//    Queue<std::string> queue;

//    for(auto&& elem : {"alan01","alan02","alan03"})
//        queue.push(elem);

//    while(!queue.empty())
//        std::cout << queue.pop() << std::endl;

//    alan::end();
//    return 0;
//}
//! @output
//!
//alan01
//alan02
//alan03

//exit normally
