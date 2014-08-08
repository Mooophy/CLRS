/***************************************************************************
 *  @file       longest_common_subsequence.hpp
 *  @author     Alan.W
 *  @date       03  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 ***************************************************************************/

#ifndef LONGEST_COMMON_SUBSEQUENCE_HPP
#define LONGEST_COMMON_SUBSEQUENCE_HPP

#include "matrix.hpp"

namespace ch15 {

enum class Arrow
{
    NA, LEFT, UP, DIAGONAL
};

template<typename T, typename A>
struct Entry
{
    //! default Ctor
    Entry() = default;

    //! Ctor
    Entry(const T& len, const A& arw):
        lengh(len), arrow(arw)
    {}

    T lengh = 0;
    A arrow = Arrow::NA;
};

template<typename T, typename A>
inline bool
operator >=(const Entry<T,A>& lhs, const Entry<T,A>& rhs)
{
    return lhs.lengh >= rhs.lengh;
}

//! @alias for Table
template<typename T, typename A>
using Table = ch15::Matrix<Entry<T,A>>;

/**
 * @brief build lcs table
 * @param lhs
 * @param rhs
 */
template<typename Range, typename A = Arrow>
Table<typename Range::size_type, A>
build_lcs_table(const Range& lhs, const Range& rhs)
{
    using SizeType  =   typename Range::size_type;
    using TableType =   Table<SizeType, A>;
    using EntryType =   Entry<SizeType, A>;

    SizeType rows = lhs.size() + 1;
    SizeType cols = rhs.size() + 1;
    TableType lcs(rows, cols, ch15::Entry<SizeType,A>());

    //! build the lcs table
    for(SizeType r = 1; r != rows + 1; ++r)
        for(SizeType c = 1; c != cols + 1; ++c)
        {
            if(lhs[r - 1]   ==  rhs[c - 1])
                lcs(r,c) = EntryType(ret(r - 1, c - 1).length + 1,  Arrow::DIAGONAL);
            else if(ret(r - 1, c) >= ret(r, c - 1))
                lcs(r,c) = EntryType(ret(r - 1, c).length,  Arrow::UP);
            else
                lcs(r,c) = EntryType(ret(r, c - 1).length,  Arrow::LEFT);
        }

    return lcs;
}

}//namespace
#endif // LONGEST_COMMON_SUBSEQUENCE_HPP










