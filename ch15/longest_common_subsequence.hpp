/***************************************************************************
 *  @file       longest_common_subsequence.hpp
 *  @author     Alan.W
 *  @date       03  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 ***************************************************************************/

#ifndef LONGEST_COMMON_SUBSEQUENCE_HPP
#define LONGEST_COMMON_SUBSEQUENCE_HPP

#include "matrix.hpp"
#include "color.hpp"

namespace ch15 {

enum class Arrow
{
    NA, LEFT, UP, DIAGONAL
};

template<typename T, typename A>
struct Entry
{
    //! Ctors
    Entry() = default;
    Entry(const T& len, const A& arw = Arrow::NA):
        length(len), arrow(arw)
    {}

    //! update this entry
    Entry operator ()(const T& len, const A& arw = Arrow::NA)
    {
        length  =   len;
        arrow   =   arw;

        return *this;
    }

    T length = 0;
    A arrow = Arrow::NA;
};

template<typename T, typename A>
inline std::ostream&
operator <<(std::ostream& os , const Entry<T,A>& etr)
{
    os << color::green("[") << etr.length << ",";

    switch (etr.arrow)
    {
    case Arrow::NA      :   os << "N";  break;
    case Arrow::LEFT    :   os << "L";  break;
    case Arrow::DIAGONAL:   os << "D";  break;
    case Arrow::UP      :   os << "U";  break;
    }

    os << color::green("]");

    return os;
}

template<typename T, typename A>
inline bool
operator >=(const Entry<T,A>& lhs, const Entry<T,A>& rhs)
{
    return lhs.length >= rhs.length;
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
    //! types def
    using SizeType  =   typename Range::size_type;
    using TableType =   Table<SizeType, A>;
    using EntryType =   Entry<SizeType, A>;

    //! init
    SizeType rows = lhs.size() + 1;
    SizeType cols = rhs.size() + 1;
    TableType lcs(rows, cols, ch15::Entry<SizeType,A>());

    //! build the lcs table
    for(SizeType r = 1; r != rows + 1; ++r)
        for(SizeType c = 1; c != cols + 1; ++c)
        {
            if(lhs[r - 1]   ==  rhs[c - 1])
                lcs(r,c) = EntryType(lcs(r - 1, c - 1).length + 1,  Arrow::DIAGONAL);
            else if(lcs(r - 1, c) >= lcs(r, c - 1))
                lcs(r,c) = EntryType(lcs(r - 1, c).length,  Arrow::UP);
            else
                lcs(r,c) = EntryType(lcs(r, c - 1).length,  Arrow::LEFT);
        }

    return lcs;
}

}//namespace
#endif // LONGEST_COMMON_SUBSEQUENCE_HPP

//! @test   print ch15::table
//#include <iostream>
//#include <boost/numeric/ublas/io.hpp>
//#include "longest_common_subsequence.hpp"
//#include "color.hpp"

//int main()
//{
//    using TableType = ch15::Table<int, ch15::Arrow>;

//    TableType tbl(3,3, ch15::Entry<int, ch15::Arrow>());
//    std::cout << tbl << std::endl;

//    std::cout << color::red("\nend\n");
//    return 0;
//}









