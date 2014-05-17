/***************************************************************************
 *  @file       random.h
 *  @author     Alan.W
 *  @date       4  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//! ex5.1-2
/*  random(a, b)
 *  def ret = 0
 *  for i = a to b
 *      ret += random(0,1)
 *  return ret
 */

#ifndef RANDOM_H
#define RANDOM_H

#include <random>

//! implementation for random(a=0, b=0)
namespace ch5 {

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

}//namespace


#endif // RANDOM_H
