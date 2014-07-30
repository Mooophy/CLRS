/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       28  July 2014
 *  @remark     Implementation for CLRS, using C++ templates.
 ***************************************************************************/
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <boost/numeric/ublas/matrix.hpp>
#include <assert.h>

namespace ch15
{
template<typename T>
using Matrix = boost::numeric::ublas::matrix<T>;

template<typename T>
Matrix<T>
operator*(const Matrix<T>& lhs, const Matrix<T>& rhs);

template<typename T>
void print(const Matrix<T>& mat)
{
    for(unsigned r = 0; r != mat.size1(); ++r)
        for(unsigned c = 0; c != mat.size2(); ++c)
            std::cout << mat(r,c) << std::endl;
}

template<typename T>
inline Matrix<T>
operator*(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    assert(lhs.size2() == rhs.size1());

    Matrix<T> ret(lhs.size1(), rhs.size2());
    for(unsigned row = 0; row != lhs.size1(); ++row)
        for(unsigned col = 0; col != rhs.size2(); ++ col)
        {
            ret(row,col) = 0;
            for(unsigned count = 0 ; count != lhs.size2(); ++count)
                ret(row,col) += lhs(row,count) * rhs(count, col);
        }

    return ret;
}

}//namespace


#endif // MATRIX_HPP
