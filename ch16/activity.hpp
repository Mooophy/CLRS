/***************************************************************************
 *  @file       activity.hpp
 *  @author     Alan.W
 *  @date       15  Aug 2014
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <assert.h>

namespace ch16 {

/**
 * @brief activity_select
 * @param starts    range
 * @param finishes  range
 * @param pos       index
 * @param output    range
 *
 * @pseudocode  RECURSIVE-ACTIVITY-SELECTOR
 * @page    419, CLRS
 * @note the first activity would not be pushed into output container
 */
template<typename Range>
inline void
activity_select_recur(const Range& starts,
                      const Range& finishes,
                      typename Range::size_type pos,
                      Range& output)
{
    assert(starts.size() == finishes.size());

    //! search for next activity
    auto curr = pos + 1;
    while(curr < starts.size()  &&  starts[curr] < finishes[pos])   ++curr;

    //! if within the boundary, push back and recur
    if( curr < starts.size())
    {
        output.push_back(curr);
        activity_select_recur(starts, finishes, curr, output);
    }
}

template<typename Range>
inline void
activity_select_itera(const Range& starts, const Range& finishes, Range& output)
{
    output.push_back(0);

    using SizeType  =   typename Range::size_type;
    SizeType pos    =   0;
    for(SizeType curr = 1; curr != starts.size(); ++curr)
    {
        if(starts[curr] >=  finishes[pos])
        {
            output.push_back(curr);
            pos = curr;
        }
    }
}

}//namespace
#endif // ACTIVITY_HPP

//! @test   RECURSIVE-ACTIVITY-SELECTOR
//!
//#include <iostream>
//#include <vector>
//#include "activity.hpp"
//#include "alan.hpp"

//int main()
//{
//    std::vector<int> starts     =   {1,3,0,5,3,5,6,8,8,2,12};
//    std::vector<int> finishes   =   {4,5,6,7,9,9,10,11,12,14,16};
//    std::vector<int> activites;

//    ch16::activity_select_recur(starts, finishes, 0, activites);
//    alan::print_container(activites);

//    std::cout << alan::green("\nexit normally.\n");
//    return 0;
//}
//! output:
//!
//3 7 10
//exit normally.

