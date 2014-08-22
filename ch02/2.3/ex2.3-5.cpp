/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       18  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! ex2.3-5 binary search
//! pseudocode:     range: [first, last)
//!

//! @part 1     Interface part
//!     Iter binary_search(first, last, value)
/*      Iter binary_search(first, last, value)
 *1     Nil = last
 *2     return recur_binary_seach(first, last, value, Nil)
 */

//! @part 2     Actual recurrsion
//!     Iter recur_binary_search(first, last, value, Nil)
/*      Iter recur_binary_search(first, last, value, Nil)
 *1     mid = first + (last - first)/2
 *2     if (*mid == value)
 *3         return mid
 *4     else
 *5         if(mid == first)
 *6             return Nil      //  note : once mid == first, it must be not found.
 *7         if(*mid < value)
 *8             return  recur_binary_seach(mid , last, value, Nil)
 *9         else
 *10            return  recur_binary_seach(first, mid, value, Nil)
 */

#include <iostream>
#include <vector>

//! @part 1
template<typename Iter, typename ValueType>
Iter binary_search(Iter first, Iter last, ValueType value);

//! @part 2
template<typename Iter, typename ValueType>
Iter recur_binary_search(Iter first, Iter last, ValueType value, Iter Nil);

int main()
{
    //! test:
    std::vector<int> v = {1,3,4,5,6,7,8,9};
    std::vector<std::string> vs = {"111","222","aaa","bbb"};
    std::cout << ((vs.end() == binary_search(vs.begin(), vs.end(), "aaa")) ?
                     "not found" :  "found")
              << "\nIt's " + *binary_search(vs.begin(), vs.end(), "aaa")
              << std::endl;
    return 0;
}

//! @part 1     interface
//! check pseudocode for detailed algorithm
template<typename Iter, typename ValueType>
inline Iter binary_search(Iter first, Iter last, ValueType value)
{
    Iter Nil = last;
    return recur_binary_search(first, last, value, Nil);
}


//! @part 2     actual recursion part
//! check pseudocode for detailed algorithm
template<typename Iter, typename ValueType>
inline Iter recur_binary_search(Iter first, Iter last, ValueType value, Iter Nil)
{
    Iter mid = first + (last - first)/2;
    if (*mid == value)  return mid;
    else
    {
        if(mid == first) return Nil;
        if(*mid < value)
            return recur_binary_search(mid  , last, value, Nil);
        else
            return recur_binary_search(first, mid , value, Nil);
    }
}














