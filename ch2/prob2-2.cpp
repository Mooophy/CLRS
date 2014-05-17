/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       23  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! Prob 2-2
//!
//! @pseudocode bubble_sort   [first, last)
/*      buble_sort(first, last)
 *1     if(last - first > 1)
 *2         for ex = first to last - 1
 *3             for in = last - 1 downto first + 1
 *4                 if(*in < *(in-1))
 *5                     swap *in and *(in-1)
 */
#include "sorts.h"
#include <string>
#include <vector>
#include <stdexcept>


int main()
{
    std::vector<int> v = {9,8,7,6,5,5,3,2,1};
    std::vector<std::string> vs = {"aa","900","55","ss","0"};
    bubble_sort(vs.begin(), vs.end());
    for(auto i : vs)     std::cout << i << std::endl;
}

