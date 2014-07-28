/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       28  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
//!
//! 15.1-5
//! The Fibonacci numbers are defined by recurrence (3.22). Give an O(n)-time
//! dynamic-programming algorithm to compute the nth Fibonacci number. Draw the
//! subproblem graph. How many vertices and edges are in the graph?
//!
#ifndef FIBONACCI_HPP
#define FIBONACCI_HPP

#include <vector>

namespace ch15{

/**
 * @brief The Fibonacci class
 */
template<typename ValueType>
class Fibonacci
{
public:
    Fibonacci():
        buffer({0,1})
    {}

    /**
     * @brief operator ()
     * @param nth
     * @return the nth of Fibonacci numbers
     *
     * @complx  O(n)
     */
    ValueType operator()(std::size_t nth)
    {
        if(nth < 2)
            return buffer[nth];

        for(std::size_t count = 2; count != nth + 1; ++count)
            buffer.push_back( buffer[count - 1]   +   buffer[count - 2]);

        return buffer.back();
    }

    /**
     * @brief print all numbers generated so far
     *
     * @complx  O(n)
     */
    void print()const
    {
        for(const auto& num : buffer)
            std::cout << num << " ";

        std::cout << std::endl;
    }

private:
    std::vector<ValueType> buffer;
};

}//namespace
#endif // FIBONACCI_HPP

//#include <iostream>
//#include <memory>
//#include "color.hpp"
//#include "fibonacci.hpp"

//int main()
//{
//    ch15::Fibonacci<long long> fibo;

//    std::cout << fibo(50) << std::endl;
//    fibo.print();

//    std::cout << color::red("\nend\n");
//    return 0;
//}
