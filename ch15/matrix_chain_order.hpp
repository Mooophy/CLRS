/***************************************************************************
 *  @file       matrix_chain_order.hpp
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

template<typename T>
using Chain = std::vector<ch15::Matrix<T>>;

//! forwad declarations
template<typename Range>
class MatrixChainOrder;

template<typename T>
ch15::Matrix<T> matrix_chain_multiply(const ch15::Chain<T>& chain);

/**
 * @brief The MatrixChain class
 */
template<typename Range>
class MatrixChainOrder
{
    friend ch15::Matrix<typename Range::value_type>
        matrix_chain_multiply<typename Range::value_type>
            (const ch15::Chain<typename Range::value_type>& chain);
public:
    using ValueType =   typename    Range::value_type;
    using SizeType  =   typename    Range::size_type;
    using Matrix    =               ch15::Matrix<ValueType>;

    /**
     * @brief Ctor
     */
    MatrixChainOrder(const Range& d):
        data(d),
        m(d.size() - 1, d.size() - 1),
        s(d.size() - 2, d.size() - 2),
        size(d.size() - 1)
    {
        assert(size > 0);
    }

    /**
     * @brief build
     *
     * @pseudocode  MATRIX-CHAIN-ORDER
     * @page 375, CLRS
     * @time complx  theta(n^3)
     * @space required  theta(n^2)
     */
    void build()
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
                        m(head,tail)        =   result;
                        s(head,tail - 1)    =   split + 1;
                    }
                }
            }
        }
    }

    /**
     * @brief print_optimal
     * @param head  :   i
     * @param tail  :   j
     *
     * @pseudocode PRINT-OPTIMAL-PARENTS
     * @page    377, CLRS
     */
    void print_optimal(SizeType head, SizeType tail)const
    {
        if(head  == tail)
            std ::cout << "A" << head;
        else
        {
            std::cout << color::yellow("(");
            print_optimal(head, s(head - 1,tail - 2));
            print_optimal(s(head - 1,tail - 2) + 1, tail);
            std::cout << color::yellow(")");
        }
    }

private:
    const Range& data;
    Matrix m;
    Matrix s;
    SizeType size;
};

} //namespace
#endif // MATRIX_CHAIN_H

//! test for MATRIX-CHAIN-ORDER and PRINT-OPTIMAL-PARENTS
//#include <iostream>
//#include "matrix.hpp"
//#include "color.hpp"
//#include "matrix_chain_order.hpp"

//int main()
//{
//    std::vector<int> v = {30,35,15,5,10,20,25};
//    ch15::MatrixChainOrder<decltype(v)> chain_order(v);

//    chain_order.build();
//    chain_order.print_optimal(1,6);

//    std::cout << color::red("\nend\n");
//    return 0;
//}
