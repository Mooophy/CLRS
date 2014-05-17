/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       15  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note
 ***************************************************************************/
//!
//! ex 2.2-2 Selection-Sort
//!

//! Pseudocode:
/*  Selection_Sort(A)
 *  1   for i = 1 to n-1
 *  2       key = i
 *  3       for j = i to n
 *  4           if (A[key] > A[j])  key = j
 *  5       swap A[i] and A[key]
 */

//! loop invariant:
/*  At the start of each iteration of line 1 - 5
 *  A[i-1] is no greater than any value from subarray A[i...n]
 */

#include <iostream>
#include <vector>

/**
 *  selection_sort
 */
template<typename T>
void selection_sort(std::vector<T>& v);
int main()
{
    //! test:
    std::vector<int> vi = {8,6,3,9,11,77,2};
    std::vector<std::string> vs = {"zzaaa","zzz888","1a","444","44","zzzzzzzzzzz"};
    std::vector<char> vc = {'a','s','1','2','0'};
    std::vector<int> test ={999};

    selection_sort(test);

    //! print
    for(const auto i : test)
        std::cout << i << std::endl;

    return 0;
}

//! Pseudocode:
/*  Selection_Sort(A)
 *  1   for i = 1 to n-1
 *  2       key = i
 *  3       for j = i to n
 *  4           if (A[key] > A[j])  key = j
 *  5       swap A[i] and A[key]
 */
template<typename T>
void selection_sort(std::vector<T>& v)
{
    //! Boundary condition handling
    if(v.size() < 2)    return;

    for(auto i = v.begin(); i != v.end() - 1; ++i)
    {
        auto key = i;
        for(auto j = i; j != v.end(); ++j)
            if(*key > *j)   key=j;
        std::swap(*i,*key);
    }
}
