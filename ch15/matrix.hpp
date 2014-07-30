/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       28  July 2014
 *  @remark     Implementation for CLRS, using C++ templates.
 ***************************************************************************/
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <boost/numeric/ublas/matrix.hpp>

namespace ch15
{
template<typename T>
using Matrix = boost::numeric::ublas::matrix<T>;

template<typename T>
Matrix<T>
operator*(const Matrix<T>& lhs, const Matrix<T>& rhs);


template<typename T>
inline Matrix<T>
operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
{

}

}


#endif // MATRIX_HPP
