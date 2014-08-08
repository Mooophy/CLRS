/***************************************************************************
 *  @file       matrix_chain_mutiply.hpp
 *  @author     Alan.W
 *  @date       03  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 ***************************************************************************/

//!
//! ex15.2-2
//! Give a recursive algorithm MATRIX-CHAIN-MULTIPLY(A, s, i, j) that actually
//! performs the optimal matrix-chain multiplication, given the sequence of matrices
//! {A1,A2,...An}, the s table computed by MATRIX-CHAIN-ORDER , and the indices i and j .
//! (The initial call would be MATRIX-CHAIN-MULTIPLY (A, s, 1, n))
//!
//  check the lambda in function matrix_chain_multiply.
//!

#ifndef MATRIX_CHAIN_MUTIPLY_HPP
#define MATRIX_CHAIN_MUTIPLY_HPP

#include <vector>
#include <functional>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "matrix_chain_order.hpp"


namespace ch15 {

//! foward declarations
template<typename Range>
void
build_chain(ch15::Chain<typename Range::value_type>& chain,
            const Range& dimensions,
            const typename Range::value_type& init_val = 0);

template<typename Range>
void
build_dimensions(const ch15::Chain<typename Range::value_type>& chain,
                 Range& dimensions);

template<typename T>
void print_matrix_chain(const ch15::Chain<T>& chain);

template<typename T>
ch15::Matrix<T>
matrix_chain_multiply(const ch15::Chain<T>& chain);




/**
 * @brief build_chain
 * @param chain
 * @param dimensions
 *
 * build a matrix chain using dimemsions stored in a stl container
 */
template<typename Range>
inline void
build_chain(ch15::Chain<typename Range::value_type>& chain,
            const Range& dimensions,
            const typename Range::value_type& init_val)
{
    using ValueType =   typename Range::value_type;

    for(auto it = dimensions.begin(); it != dimensions.end() - 1; ++it)
    {
        auto mat = ch15::Matrix<ValueType>(*it, *(it + 1), init_val);
        chain.push_back(mat);
    }
}

/**
 * @brief print_matrix_chain
 * @param chain
 */
template<typename T>
inline void
print_matrix_chain(const ch15::Chain<T>& chain)
{
    for(const auto& mat : chain)
        std::cout << mat << std::endl << std::endl;
}

/**
 * @brief build_dimensions
 * @param chain
 * @param dimensions
 *
 * build dimensions from matrix chain
 */
template<typename Range>
inline void
build_dimensions(const ch15::Chain<typename Range::value_type>& chain,
                 Range& dimensions)
{
    dimensions.push_back( chain.begin()->size1() );
    for(const auto& mat : chain)
        dimensions.push_back( mat.size2());
}

/**
 * @brief matrix_chain_multiply
 * @param chain
 *
 * @complx  O(n^3)
 * for ex15.2-2
 */
template<typename T>
ch15::Matrix<T>
matrix_chain_multiply(const ch15::Chain<T>& chain)
{
    //! type def for MatrixChainOrder's parameter
    using RangeType =   std::vector<T>;
    using SizeType  =   typename ch15::Matrix<T>::size_type;

    //! build dimensions
    RangeType dimens;
    ch15::build_dimensions(chain, dimens);

    //! build optimal order
    ch15::MatrixChainOrder<RangeType> order(dimens);
    order.build();
    order.print_optimal(1,chain.size());
    std::cout << std::endl;

    //! lambda to do the real job recursively
    //! @note   ex15.2-2
    std::function<ch15::Matrix<T>(SizeType,SizeType)> multiply
            = [&](SizeType head, SizeType tail)
    {
        //! @attention below is the pseudocode for ex15.2-2
        if(head == tail)
            return chain[head - 1];
        else
            return multiply(head, order.s(head - 1,tail - 2))
                   *
                   multiply(order.s(head - 1,tail - 2) + 1, tail);
    };

    //! return the product
    return multiply(1, chain.size());
}

}//namepspace
#endif // MATRIX_CHAIN_MUTIPLY_HPP

//! test: build_chain
//!     : build_dimensions
//#include <iostream>
//#include <boost/numeric/ublas/io.hpp>
//#include "color.hpp"
//#include "matrix.hpp"
//#include "matrix_chain_mutiply.hpp"
//#include "matrix_chain_order.hpp"

//int main()
//{
//    std::vector<int> v = {30,35,15,5,10,20,25};

//    ch15::Chain<int> chain;
//    ch15::build_chain(chain, v, 2);
//    ch15::print_matrix_chain(chain);

//    std::vector<int> dimens;
//    ch15::build_dimensions(chain, dimens);
//    for(auto d : dimens)
//        std::cout << d << " ";

//    std::cout << color::red("\nend\n");
//    return 0;
//}

//! @test   matrix_chain_multiply
//!         ex15.2-2
//#include <iostream>
//#include <boost/numeric/ublas/io.hpp>
//#include "color.hpp"
//#include "matrix.hpp"
//#include "matrix_chain_mutiply.hpp"
//#include "matrix_chain_order.hpp"

//int main()
//{
//    std::vector<int> v = {30,35,15,5,10,20,25};

//    ch15::Chain<int> chain;
//    ch15::build_chain(chain, v, 2);
//    std::cout << ch15::matrix_chain_multiply(chain) << std::endl;

//    std::cout << color::red("\nend\n");
//    return 0;
//}


