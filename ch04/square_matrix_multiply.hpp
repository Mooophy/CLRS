/***************************************************************************
 *  @file       square_matrix_multiply.hpp
 *  @author     Yue Wang
 *  @date       29  Aug 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

#ifndef SQUARE_MATRIX_MULTIPLY_H
#define SQUARE_MATRIX_MULTIPLY_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace clrs {namespace ch4 {

/**
 *  @brief  type aliasing
 */
template<typename T>
using Matrix = boost::numeric::ublas::matrix<T>;

/**
 * @brief square_matrix_multiply
 * @param lhs
 * @param rhs
 * @return product
 *
 * @pseudocode SQUARE-MATRIX-MULTIPLY,   Page 75
 * @complx  O(n^3)
 */
template<typename T>
Matrix<T> square_matrix_multiply(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    using namespace boost::numeric::ublas;
    using SizeType  = typename matrix<T>::size_type;

    SizeType size = lhs.size1();
    matrix<T> ret(size, size);
    for(SizeType i = 0; i != size; ++i)
        for(SizeType j = 0; j != size; ++j)
        {
            ret(i,j) = 0;
            for(SizeType k = 0; k != size; ++k)
                ret(i,j) += lhs(i,k) * rhs(k,j);
        }
    return  ret;
}

/**
 * @brief square_matrix_multiply
 * @param lhs
 * @param rhs
 * @return product
 *
 * @pseudocode SQUARE-MATRIX-MULTIPLY-RECURSIVE
 * @complx  O(n^3)
 */
template<typename T>
Matrix<T>
square_matrix_multiply_recursive(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    //! types def
    using ValueType = T;
    using Matrix    = boost::numeric::ublas::matrix<ValueType>;   
    using SizeType  = typename Matrix::size_type;
    using Range     = boost::numeric::ublas::range;
    using namespace boost::numeric::ublas;

    SizeType size = lhs.size1();
    Matrix ret(size,size);

    //! the recurssion bottom
    if(size == 1)
        ret(0,0) = lhs(0,0) * rhs(0,0);
    else
    {
        //! ranges used for matrix partition
        Range r0(0,size/2), r1(size/2, size);

        //! lhs's submatrices
        Matrix lhs00(project(lhs,r0,r0));
        Matrix lhs01(project(lhs,r0,r1));
        Matrix lhs10(project(lhs,r1,r0));
        Matrix lhs11(project(lhs,r1,r1));

        //! rhs's submatrices
        Matrix rhs00(project(rhs,r0,r0));
        Matrix rhs01(project(rhs,r0,r1));
        Matrix rhs10(project(rhs,r1,r0));
        Matrix rhs11(project(rhs,r1,r1));

        //! recurssion
        //! @note must use project() on ret to "reference" it.Otherwise not working.
        project(ret,r0,r0)  =   square_matrix_multiply_recursive(lhs00,rhs00)
                              + square_matrix_multiply_recursive(lhs01,rhs10);

        project(ret,r0,r1)  =   square_matrix_multiply_recursive(lhs00,rhs01)
                              + square_matrix_multiply_recursive(lhs01,rhs11);

        project(ret,r1,r0)  =   square_matrix_multiply_recursive(lhs10,rhs00)
                              + square_matrix_multiply_recursive(lhs11,rhs10);

        project(ret,r1,r1)  =   square_matrix_multiply_recursive(lhs10,rhs01)
                              + square_matrix_multiply_recursive(lhs11,rhs11);
    }
    return ret;
}

/**
 * @brief square_matrix_multiply_strassen
 * @param lhs
 * @param rhs
 * @return product
 *
 * @complx  O(n^2.81)
 */
template<typename T>
Matrix<T>
square_matrix_multiply_strassen(const Matrix<T>& lhs, const Matrix<T>& rhs)
{
    //! types def
    using ValueType = T;
    using Matrix    = boost::numeric::ublas::matrix<ValueType>;
    using SizeType  = typename Matrix::size_type;
    using Range     = boost::numeric::ublas::range;
    using namespace boost::numeric::ublas;

    SizeType size = lhs.size1();
    Matrix  ret(size,size);

    if(size == 1)
        ret(0,0) = lhs(0,0) * rhs(0,0);
    else
    {
        //! ranges used for matrix partition
        Range r0(0,size/2), r1(size/2, size);

        //! step 1 : submatrices
        Matrix lhs00(project(lhs,r0,r0));
        Matrix lhs01(project(lhs,r0,r1));
        Matrix lhs10(project(lhs,r1,r0));
        Matrix lhs11(project(lhs,r1,r1));
        Matrix rhs00(project(rhs,r0,r0));
        Matrix rhs01(project(rhs,r0,r1));
        Matrix rhs10(project(rhs,r1,r0));
        Matrix rhs11(project(rhs,r1,r1));

        //! step 2
        Matrix s0 = rhs01 - rhs11;
        Matrix s1 = lhs00 + lhs01;
        Matrix s2 = lhs10 + lhs11;
        Matrix s3 = rhs10 - rhs00;
        Matrix s4 = lhs00 + lhs11;
        Matrix s5 = rhs00 + rhs11;
        Matrix s6 = lhs01 - lhs11;
        Matrix s7 = rhs10 + rhs11;
        Matrix s8 = lhs00 - lhs10;
        Matrix s9 = rhs00 + rhs01;

        //! step 3
        Matrix p0 = square_matrix_multiply_strassen(lhs00,  s0);
        Matrix p1 = square_matrix_multiply_strassen(s1, rhs11);
        Matrix p2 = square_matrix_multiply_strassen(s2, rhs00);
        Matrix p3 = square_matrix_multiply_strassen(lhs11,  s3);
        Matrix p4 = square_matrix_multiply_strassen(s4, s5);
        Matrix p5 = square_matrix_multiply_strassen(s6, s7);
        Matrix p6 = square_matrix_multiply_strassen(s8, s9);

        //! step 4 recurssion
        project(ret,r0,r0) = p4 + p3 - p1 + p5;
        project(ret,r0,r1) = p0 + p1;
        project(ret,r1,r0) = p2 + p3;
        project(ret,r1,r1) = p4 + p0 - p2 - p6;
    }
    return ret;
}

}}//namespace
#endif // SQUARE_MATRIX_MULTIPLY_H

//! @test  all three functions above
//!
//#include <iostream>
//#include <boost/numeric/ublas/io.hpp>
//#include "square_matrix_multiply.hpp"

//int main ()
//{
//    using namespace boost::numeric::ublas;
//    matrix<int> lhs(2,2), rhs(2,2);

//    lhs(0,0) = 1;
//    lhs(0,1) = 3;
//    lhs(1,0) = 7;
//    lhs(1,1) = 5;

//    rhs(0,0) = 6;
//    rhs(0,1) = 8;
//    rhs(1,0) = 4;
//    rhs(1,1) = 2;

//    std::cout << clrs::ch4::square_matrix_multiply_recursive(lhs,rhs)  << std::endl;
//    std::cout << clrs::ch4::square_matrix_multiply(lhs,rhs)            << std::endl;
//    std::cout << clrs::ch4::square_matrix_multiply_strassen(lhs,rhs)   << std::endl;
//}
//! @output
//!
//[2,2]((18,14),(62,66))
//[2,2]((18,14),(62,66))
//[2,2]((18,14),(62,66))
