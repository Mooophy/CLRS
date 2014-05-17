/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       23  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! Prob 2-1
//!
//! check sorts.h for the implementations for the pseudocode.
//!
//! a.  show that insertion sort can sort the n/k sublists, each of length k, in
//!     O(nk) worst-cast time.
//! pseudocode:     insertion_sort_lengthK
/*      insertion_sort_lenthK(first, last, k)
 *1     it = first
 *2     while (last - it) > = k
 *3         insertion_sort(it, it + k)      //O(k^2)
 *4         it += k
 *5     insertion_sort(it, last)
 */
//!
//! It can be found in line 3 that it takes k^2 time to execute each call for function
//! insertion_sirt(). The wholle times of calling is n/k.Hence
//! O(insertion_sort) = O(k^2 * n/k) = O(nk)
//!
//! b. Show how to merge the sublists in O(nlg(n/k)) worst-case time.
//! pseudocode:		merge_withInsertion_sort
/*      merge_withInsertion_sort(first, last, k)
 *1     if (last - first > 1) && (last - first > k)
 *2         mid = first - (last - first)/2
 *3         merge_withInsertion_sort(first, mid , k)
 *4         merge_withInsertion_sort(mid  , last, k)
 *5         merge(first, mid, last)
 *6     else
 *7         insertion_sort(first, last)
 */


#include "sorts.h"
#include <string>
#include <vector>
#include <stdexcept>

int main()
{
    std::vector<int> v = {2,4,1,5,4,5,0,3,1};
    std::vector<std::string>
            vs = {"aaassss"};
    std::vector<float> vf ={2.4,42.3,3,56,7,8,-2,9,0.9};



    //merge_sort(v.begin(), v.end());
    //insertion_sort_lengthK(v.begin(), v.end(), 3);

    merge_withInsertion_sort(vf.begin(), vf.end(), 4);

    for(auto i : vf)
    {
        std::cout << i << std::endl;
    }

}

