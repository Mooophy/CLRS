/***************************************************************************
 *  @file       merge_with_insertion_sort.hpp
 *  @author     Alan.W
 *  @date       28  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/
//!
//! @problem    2-4 Inversions
//!

#ifndef INVERSIONS_HPP
#define INVERSIONS_HPP

#include "iterator.hpp"

namespace clrs { namespace ch2 {

/**
 * @brief count_n_merge
 * @param first
 * @param mid
 * @param last
 *
 * the merge part
 */
template<typename Iter>
std::size_t count_n_merge(Iter first, Iter mid, Iter last)
{
    using Vector = std::vector<clrs::IterValue<Iter>>;
    Vector left{first, mid};
    Vector right{mid, last};

    auto l = left.begin();
    auto r = right.begin();
    auto it = first;
    std::size_t count = 0;
    while(l != left.end()   &&  r != right.end()    &&  it != last)
    {
        if(*r < *l)
        {
            *it++   =   *r++;
            count   +=  left.end() - l;
            //! @note   ^^^^^^^^^^^^^^
            //! since left and right are sorted, left.end() - l are inversions
        }
        else
            *it++   =   *l++;
    }

    //! when left exausted
    if(l == left.end())
        while(it != last)
            *it++   =   *r++;

    //! when right exausted
    if(r == right.end())
        while(it != last)
            *it++   =   *l++;

    return count;
}

/**
 * @brief return the number of inversions
 * @param first
 * @param last
 *
 * @complx  O(n lg n)
 *
 * for problem 2-4
 */
template<typename Iter>
std::size_t inversions_count(Iter first, Iter last)
{
    std::size_t count = 0;
    if(first + 1    <   last)
    {
        auto mid = first + (last - first)/2;
        count += inversions_count(first, mid );
        count += inversions_count(mid  , last);

        count += count_n_merge(first, mid, last);
    }
    return count;
}

}}//namespace
#endif // INVERSIONS_HPP

//! @test inversions for problem 2-4
//!
//#include <iostream>
//#include <vector>
//#include "alan.hpp"
//#include "inversions.hpp"

//int main()
//{
//    std::vector<int> v{2,3,8,6,1};
//    auto count = clrs::ch2::inversions_count(v.begin(), v.end());
//    std::cout << count;

//    alan::end();
//    return 0;
//}

//! @output
//!
//5
//exit normally
