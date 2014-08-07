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
build_chain(ch15::Chain<typename Range::value_type>& chain,
            const Range& dimensions,
            const typename Range::value_type& init_val = 0)
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
void
print_matrix_chain(const ch15::Chain<T>& chain)
{
    for(const auto& mat : chain)
        std::cout << mat << std::endl << std::endl;
}

}//namepspace
#endif // MATRIX_CHAIN_MUTIPLY_HPP

//! test build_chain
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
//    ch15::build_chain(chain, v, 1);
//    ch15::print_matrix_chain(chain);

//    std::cout << color::red("\nend\n");
//    return 0;
//}

