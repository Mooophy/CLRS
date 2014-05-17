/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       17  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : CLRS
 *              That is, use the last one rather than one pass last one
 ***************************************************************************/
//!
//! ex2.3-4
//!

#include <iostream>
#include <vector>
#include <algorithm>

//! @pseudocode recur_insertionSort     range[first,last)
/*      recursive_insertionSort(first, last)
 *1     if (last - first > 2)           //at least 3 items left.
 *2         --last
 *3         recursive_insertionSort(first, last)
 *4         while(last != first)
 *5             if(*last < *(last-1))
 *6                 swap *last and *(last - 1)
 *7                 --last
 *8             else
 *9                 break
 */
/**
 *  recursive_insertionSort
 *  @param a range of [first, last)
 */
template<typename Iter>
void recursive_insertionSort(Iter first,Iter last);
int main()
{
    std::vector<int> v = {3,2,1};
    recursive_insertionSort(v.begin(), v.end());

    for(auto i : v)
        std::cout << i << std::endl;

    return 0;
}

/**
 *  recursive_insertionSort
 *  @param a range of [first, last)
 */
template<typename Iter>
void recursive_insertionSort(Iter first,Iter last)
{
    if(last - first > 1)
    {
        --last;
        recursive_insertionSort(first, last);
        while(last != first)
        {
            if(*last < *(last - 1))  std::swap(*last,*last--);
            else break;
        }
    }
}
