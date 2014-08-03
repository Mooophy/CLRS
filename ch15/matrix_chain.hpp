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

/**
 * @brief The MatrixChain class
 */
template<typename Range>
class MatrixChain
{
public:
    using ValueType =   typename    Range::value_type;
    using SizeType  =   typename    Range::size_type;
    using Matrix    =               ch15::Matrix<ValueType>;

    /**
     * @brief Ctor
     */
    MatrixChain(const Range& d):
        data(d),
        m(d.size() - 1, d.size() - 1),
        s(d.size() - 1, d.size() - 1),
        size(d.size() - 1)
    {
        assert(size > 1);
    }

    /**
     * @brief build_solutions
     */
    void build_solutions()
    {
        //! (head == tail) == true
        for(SizeType head = 0; head != size; ++head)
            m(head,head)  =   0;

        for(SizeType len = 2; len != size + 1; ++len)
        {
            for(SizeType head = 0; head != size - len + 1; ++head)
            {
                SizeType tail = head + len - 1;
                m(head,tail)  =   std::numeric_limits<ValueType>::max();

                for(SizeType split = head; split != tail; ++split)
                {
                    ValueType result  =
                                m(head,split)
                            +   m(split + 1, tail)
                            +   data[head] * data[split + 1] * data[tail + 1];

                    if(result < m(head,tail))
                    {
                        m(head,tail)  =   result;
                        s(head,tail)  =   split;
                    }
                }
            }
        }
    }

    /**
     * @brief print_m
     */
    void print_m()const
    {
        std::cout << color::green("table m :\n");
        ch15::print(m);
    }

    /**
     * @brief print_s
     */
    void print_s()const
    {
        std::cout << color::yellow("table s :\n");
        ch15::print(s);
    }

    /**
     * @brief print
     */
    void print()const
    {
        print_m();
        std::cout << std::endl;
        print_s();
    }

private:
    const Range& data;
    Matrix m;
    Matrix s;
    SizeType size;

};

} //namespace
#endif // MATRIX_CHAIN_H
