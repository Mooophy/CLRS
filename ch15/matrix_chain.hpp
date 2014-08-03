/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       03  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 ***************************************************************************/

#ifndef MATRIX_CHAIN_H
#define MATRIX_CHAIN_H

#include <iterator>
#include "color.hpp"
#include "matrix.hpp"

namespace ch15 {

template<typename Range>
class MatrixChain
{
public:
    using ValueType =   typename    Range::value_type;
    using SizeType  =   typename    Range::size_type;
    using Matrix    =               ch15::Matrix<ValueType>;

    MatrixChain(const Range& d):
        data(d),
        m(d.size(), d.size()),
        s(d.size() - 1, d.size() - 1),
        size(d.size() - 1)
    {
        assert(size > 1);
    }

    void build_solutions()
    {
        for(SizeType i = 0; i != size; ++i)
            m(i,i)  =   0;

        for(SizeType len = 2; len != size + 1; ++len)
        {
            for(SizeType i = 0; i != size - len; ++i)
            {
                SizeType j = i + len - 1;
                m(i,j)  =   std::numeric_limits<ValueType>::max();

                for(SizeType split = i; split != j; ++split)
                {
                    ValueType result  =
                            m(i,split)  +   m(split + 1, j)
                                        +   data[i] * data[split] * data[j];

                    if(result < m(i,j))
                    {
                        m(i,j)  =   result;
                        s(i,j)  =   split;
                    }
                }
            }
        }
    }

    void print_m()const
    {
        std::cout << color::green("table m :\n");
        ch15::print(m);
    }

    void print_s()const
    {
        std::cout << color::yellow("table s :\n");
        ch15::print(s);
    }

    const Range& data;
    Matrix m;
    Matrix s;
    SizeType size;

};

} //namespace
#endif // MATRIX_CHAIN_H
