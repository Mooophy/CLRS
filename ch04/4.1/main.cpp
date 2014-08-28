/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       26  Apr 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! ex4.1-1
//! What does FIND-MAXIMUM-SUBARRAY return when all elements of A are negative?
//  In such case, the result returned from find_max_crossing_subarray must be smallest
//  one among the left, right and cross tuple. Hence the element returned must be
//  the largest single element from the container.
//!
//! ex4.1-2
//! Write pseudocode for the brute-force method of solving the maximum-subarray problem.
//! Your procedure should run in n^2 time.
//  check brute_force_find_max_subarray.h
//!
//! ex4.1-3
//! Implement both the brute-force and recursive algorithms for the maximum-
//! subarray problem on your own computer. What problem size n0 gives the crossover
//! point at which the recursive algorithm beats the brute-force algorithm? Then,
//! change the base case of the recursive algorithm to use the brute-force algorithm
//! whenever the problem size is less than. Does that change the crossover point?
//  check headers.
//  Since run time is n^2 for brute force algorithm, nlgn for the recursion one.
//      Hence:  thita(n^2) = thita(nlgn)
//  which yields the crossover point.
//
//  It doesn't change the crossover point.
//!
//! ex4.1-4
//! Suppose we change the definition of the maximum-subarray problem to allow the
//! result to be an empty subarray, where the sum of the values of an empty subar-
//! ray is 0. How would you change any of the algorithms that do not allow empty
//! subarrays to permit an empty subarray to be the result?
//  replace -infinity with 0 in the clrs version.
//  remove the first_time flag.
//  in such way, the anything less than 0 would be discarded and an empty array would
//  be returned.
//!
//! ex4.1-5
//! Use the following ideas to develop a nonrecursive, linear-time algorithm for the
//! maximum-subarray problem. Start at the left end of the array, and progress toward
//! the right, keeping track of the maximum subarray seen so far. Knowing a maximum
//! subarray of A[1..j], extend the answer to find a maximum subarray ending at in-
//! dex j + 1 by using the following observation: a maximum subarray of A[1..j + 1]
//! is either a maximum subarray of A[1..j]or a subarray A[i..j + 1], for some
//! 1 <= i <= j + 1. Determine a maximum subarray of the form A[i .. j + 1] in
//! constant time based on knowing a maximum subarray ending at index j.
//!
//  check linear_find_max_subarray.h for detail.
//!

#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
#include <assert.h>
#include "find_max_subarray.h"
#include "brute_force_find_max_subarray.h"
#include "linear_find_max_subarray.h"


int main()
{
    //! test:
    auto v = {-9,9,1,-2,5,3,-1,10};
    std::cout << std::get<2>(find_max_subarray(v.begin(), v.end()))             << std::endl;
    std::cout << std::get<2>(brute_force_find_max_subarray(v.begin(), v.end())) << std::endl;
    std::cout << std::get<2>(linear_find_max_subarray(v.begin(), v.end()))      << std::endl;
    //std::cout << calculate_sum(v.begin(), v.end())                              << std::endl;
}














