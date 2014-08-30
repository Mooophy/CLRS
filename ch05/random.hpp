/***************************************************************************
 *  @file       random.hpp
 *  @author     Yue Wang
 *  @date       30  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//! ex 5.1-2 *
//! Describe an implementation of the procedure RANDOM (a,b) that only makes calls
//! to RANDOM (0,1) What is the expected running time of your procedure, as a
//! function of a and b?
//!  pyseudocode:
/*  random(a, b)
 *  def ret = 0
 *  for i = a to b
 *      ret += random(0,1)
 *  return ret
 */
//  As can be seen in the pyseudocade, the running time is theata(b+1 - a).That is
//  theata(n)
//!
//! ex 5.1-3 *
//!
//! BEGIN:
//! if heads then tails, return heads
//! if tails then heads, return tails
//! otherwise, goto BEGIN
//! referred to http://algox0.wordpress.com/2011/01/31/clrs-5-1-3/
//!

#ifndef RANDOM_H
#define RANDOM_H

#include <random>

//! implementation for random(a=0, b=0)
namespace clrs{ namespace ch5 {

//! concepts: int types
template<typename T = std::size_t>
T random(T min = T(0), T max = T(1));

template<typename T = std::size_t>
T random_ex512(T min, T max)
{
    T ret = T(0);
    for(T i = min; i != max + 1; ++i)
        ret += ch5::random();
    return ret;
}

//! concepts: int types
template<typename T>
T random(T min , T max)
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<T> ud(min,max);
    return ud(e);
}

}}//namespace
#endif // RANDOM_H

//! @test
//!
//#include"random.hpp"
//#include <iostream>

//int main ()
//{
//    std::string s;
//    while(std::cin >>s)
//    {
//        if (s == "q")   break;
//        else std::cout << clrs::ch5::random_ex512(1,6) << std::endl;
//    }
//}
