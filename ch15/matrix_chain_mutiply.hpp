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
#include "matrix_chain_order.hpp"


namespace ch15 {

/**
 *  @brief  matrix chain
 */
template<typename T>
using Chain = std::vector<ch15::Matrix<T>>;


template<typename T>
class MatrixChianMultiply
{
public:

private:

};

}//namepspace
#endif // MATRIX_CHAIN_MUTIPLY_HPP
