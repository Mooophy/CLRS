/***************************************************************************
 *  @file       activity.hpp
 *  @author     Alan.W
 *  @date       15  Aug 2014
 *  @remark     Implementation for CLRS, using C++ templates.
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
 */
template<typename Range>
inline void
activity_select_recur(const Range& starts,
                      const Range& finishes,
                      typename Range::size_type pos,
                      Range& output)
{
    assert(starts.size() == finishes.size());

    using SizeType  =   typename Range::size_type;
    SizeType curr = pos + 1;

    while(curr < starts.size()  &&  starts[curr] < finishes[pos])   ++curr;
    if( curr < starts.size()){
        output.push_back(curr);
        activity_select_recur(starts, finishes, curr, output);
    }
}

}//namespace
#endif // ACTIVITY_HPP
