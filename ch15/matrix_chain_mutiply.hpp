/***************************************************************************
 *  @file       node.hpp
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

#ifndef MATRIX_CHAIN_MUTIPLY_HPP
#define MATRIX_CHAIN_MUTIPLY_HPP

#include <vector>
#include <memory>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "matrix_chain_order.hpp"


namespace ch15 {

/**
 *  @brief typedef for  matrix chain
 */
template<typename T>
using Chain = std::vector<ch15::Matrix<T>>;

/**
 * @brief build_chain
 * @param chain
 * @param dimensions
 *
 * build a matrix chain using dimemsions stored in a stl container
 */
template<typename Range>
void
build_chain(ch15::Chain<typename Range::value_type>& chain, const Range& dimensions)
{
    for(auto it = dimensions.begin(); it != dimensions.end() - 1; ++it)
    {
        auto mat = ch15::Matrix<typename Range::value_type>(*it, *(it + 1));
        chain.push_back(mat);
    }
}

/**
 * @brief print_matrix_chain
 * @param chain
 */
template<typename T>
void
print_matrix_chain(const ch15::Chain<T>& chain)
{
    for(const auto& mat : chain)
        std::cout << mat << std::endl << std::endl;
}

}//namepspace
#endif // MATRIX_CHAIN_MUTIPLY_HPP
