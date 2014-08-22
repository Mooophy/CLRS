/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       23  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! Prob 2-3
//!
//! given pseudocode :
/*      horner()
 *1     y = 0               --O(1)
 *2     for i = n downto 0  --O(n+2)
 *3         y = ai + x*y    --O(n+1)
 */
//! a.
//! as shown, the running time == O(n)
//! b.
//! naive polynomial-evaluation algorithm and running time.
//! P(x) = a[0]*x^0 + a[1]*x^1 + a[2]*x^2 + ...+ a[n]*x^n
/*      poly_evaluate(first, last,x)
 *1     sum = 0
 *2     p   = 0
 *3     for(it = first; it != last; ++it)   //O(n)
 *4         sum += *it * power(p, x)        //O(n^2)
 *5         ++p
 *6     return sum
 */

/*      power(unsigned p, x)
 *1     if(p >= 0)
 *2         return x * power(--p, x)
 */



#include "sorts.h"
#include <string>
#include <vector>
#include <stdexcept>

/**
 * @brief power function
 * @param p     power index
 * @param x     type to be deduced by compiler
 * @return  the answer
 */
template<typename ValueType>
ValueType power(int p, const ValueType& x);

/**
 * @brief poly_evaluate function
 * @param first
 * @param last
 * @param x type to be deduced by compiler
 * @return the answer
 */
template<typename Iter, typename ValueType>
ValueType poly_evaluate(Iter first, Iter last, const ValueType& x);

template<typename Iter, typename ValueType>
ValueType poly_evaluate(Iter first, Iter last, const ValueType& x)
{
    ValueType sum = 0;
    int p = 0;
    for(Iter it = first; it != last; ++it)
    {
        sum += (*it) * power(p, x);
        ++p;
    }
    return sum;
}

template<typename ValueType>
inline ValueType power(int p, const ValueType& x)
{
    if(p >0)    return  x * power(p-1, x);
    else        return  1;
}

int main()
{
    std::vector<int> v = {1,2,3,4,5};
    std::cout << poly_evaluate(v.begin(), v.end(), 2) << std::endl;
}

