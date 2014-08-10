/***************************************************************************
 *  @file       lcs_with_one_table.hpp
 *  @author     alan.w
 *  @date       09  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 ***************************************************************************/

#ifndef LCS_WITH_ONE_TABLE_HPP
#define LCS_WITH_ONE_TABLE_HPP
//!
//! ex15.4-2
//! Give pseudocode to reconstruct an LCS from the completed c table and the original
//! sequences X and Y in O(m + n) time, without using the b table.
//!
#include <functional>
#include <memory>
#include "matrix.hpp"
#include "color.hpp"

namespace ch15 {

/**
 * @brief The LcsWithOneTable class
 *
 * for ex15.4-2
 */
template<typename Range>
class LcsWithOneTable
{
public:
    using SizeType  =   typename Range::size_type;
    using Pointer   =   const Range*;
    using sPointer  =   std::shared_ptr<Range>;
    using MatrixType=   ch15::Matrix<SizeType>;

    //! Ctor
    LcsWithOneTable(const Range& l, const Range& r):
        lhs(&l),
        rhs(&r),
        maze(l.size() + 1, r.size() + 1, 0)
    {
        build_maze();
    }

    /**
     * @brief print_maze
     */
    void print_maze()const
    {
        ch15::print(maze);
    }

    /**
     * @brief generate
     */
    sPointer generate() const
    {
        assert(lhs && rhs);
        sPointer lcs = std::make_shared<Range>();

        //! lambda to do the real work
        using Lambda = std::function<void(SizeType, SizeType)>;
        Lambda build_lcs = [&lcs, &build_lcs, this](SizeType l, SizeType r)
        {
            //! stop condition
            if(l == 0 || r == 0)    return;

            //! recur
            if((*lhs)[l - 1]    ==  (*rhs)[r - 1])
            {
                build_lcs(l - 1, r - 1);
                lcs->push_back((*lhs)[l - 1]);
            }
            else if (maze(l - 1, r) >= maze(l, r - 1))
                build_lcs(l - 1, r);
            else
                build_lcs(l, r - 1);
        };

        //! call the lambda
        build_lcs(lhs->size(),rhs->size());
        return lcs;
    }

private:
    Pointer lhs;
    Pointer rhs;
    MatrixType maze;

    /**
     * @brief build_maze
     *
     * @complx  O(m + n)
     * for ex15.4-2
     */
    void build_maze()
    {
        for(SizeType l = 1; l != maze.size1(); ++l)
            for(SizeType r = 1; r != maze.size2(); ++r)
            {
                if((*lhs)[l - 1]    ==  (*rhs)[r - 1])
                    maze(l,r)   =   maze(l - 1, r - 1) + 1;
                else if(maze(l - 1, r) >= maze(l, r - 1))
                    maze(l,r)   =   maze(l - 1, r);
                else
                    maze(l,r)   =   maze(l, r - 1);
            }
    }
};

}//namespace
#endif // LCS_WITH_ONE_TABLE_HPP

//! @test   for ex15.4-2
//!
//#include <iostream>
//#include <boost/numeric/ublas/io.hpp>
//#include "lcs_with_one_table.hpp"
//#include "color.hpp"

//int main()
//{
//    std::string lhs = "ABCBDAB";
//    std::string rhs = "BDCABA";

//    using LCS   =   ch15::LcsWithOneTable<std::string>;
//    LCS lcs(lhs, rhs);
//    lcs.print_maze();

//    auto sequence = lcs.generate();
//    std::cout << "The longest common sequence = ";
//    std::cout << color::yellow(*sequence) << std::endl;

//    std::cout << color::red("\nend\n");
//    return 0;
//}

//! @output:
//!
//0 0 0 0 0 0 0

//0 0 0 0 1 1 1

//0 1 1 1 1 2 2

//0 1 1 2 2 2 2

//0 1 1 2 2 3 3

//0 1 2 2 2 3 3

//0 1 2 2 3 3 4

//0 1 2 2 3 4 4

//The longest common sequence = BCBA

