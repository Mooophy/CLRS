/***************************************************************************
 *  @file       Square_Matrix_multiply.h
 *  @author     Alan.W
 *  @date       26  Apr 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

//!     Page 75
/*      square_matrix_multiply(A,B) -> matirx
 * 1    n = A.rows
 * 2    def C = matrix(n,n)
 * 3    for i = 1 to n
 * 4        for j = 1 to n
 * 5            c(i,j) = 0
 * 6            for k = 1 to n
 * 7                c(i,j) += a(i,k) * b(k,j)
 * 8    return C
 */
//!     Page 77  concepts : size must be a power of 2
/*      square_matrix_multiply_recursive(lhs,rhs) -> matirx
 * 1    size = lhs.rows
 * 2    def ret = matirx(size,size)
 * 3    if size == 1
 * 4        ret(0,0) = lhs(0,0) * rhs(0,0)
 * 5    else
 *          range r0(0, size/2), r1(size/2, size)
 * 7        project(ret, r0, r0) =
 *              recur(project(lhs,r0,r0), project(rhs,r0,r0)) + recur(project(lhs,r0,r1), project(rhs,r1,r0))
 * 8        project(ret, r0, r1) =
 *              recur(project(lhs,r0,r0), project(rhs,r0,r1)) + recur(project(lhs,r0,r1), project(rhs,r1,r1))
 * 9        project(ret, r1, r0) =
 *              recur(project(lhs,r1,r0), project(rhs,r0,r0)) + recur(project(lhs,r1,r1), project(rhs,r1,r0))
 * 10       project(ret, r1, r1) =
 *              recur(peoject(lhs,r1,r0), project(rhs,r0,r1)) + recur(project(lhs,r1,r1), project(rhs,r1,r1))
 */

//! ex4.2-2
//! Write pseudocode for Strassen’s algorithm.
//!
/*      square_matrix_multiply_strassen(lhs,rhs) -> matrix
 *      matirx(size,size) ret
 * 0    if lhs.size == 1
 * 1        ret(0,0) = lhs(0,0) * rhs(0,0)
 *      else
 * 1        def range r0(0, size/2), r1(size/2, size)
 * 2        def matrix(size/2,size/2) lhs00, lhs01, lhs10, lhs11
 * 3        def matrix(size/2,size/2) rhs00, rhs01, rhs10, rhs11
 * 4        def matrix(size/2,size/2) s0 = rhs01 - rhs11
 * 5        def matrix(size/2,size/2) s1 = lhs00 + lhs01
 * 6        def matrix(size/2,size/2) s2 = lhs10 + lhs11
 * 7        def matrix(size/2,size/2) s3 = rhs10 - rhs00
 * 8        def matrix(size/2,size/2) s4 = lhs00 + lhs11
 * 9        def matrix(size/2,size/2) s5 = rhs00 + rhs11
 * 10       def matrix(size/2,size/2) s6 = lhs01 - lhs11
 * 11       def matrix(size/2,size/2) s7 = rhs10 + rhs11
 * 12       def matrix(size/2,size/2) s8 = lhs00 - lhs10
 * 13       def matrix(size/2,size/2) s9 = rhs00 + rhs01
 * 14       def matrix(size/2,size/2) p0 = recur(lhs00, s0)
 * 15       def matrix(size/2,size/2) p1 = recur(s1, rhs11)
 * 16       def matrix(size/2,size/2) p2 = recur(s2, rhs00)
 * 17       def matrix(size/2,size/2) p3 = recur(lhs11, s3)
 * 18       def matrix(size/2,size/2) p4 = recur(s4, s5)
 * 19       def matrix(size/2,size/2) p5 = recur(s6, s7)
 * 20       def matrix(size/2,size/2) p6 = recur(s8, s9)
 * 21       project(ret,r0,r0) = p4 + p3 - p1 + p5
 * 22       project(ret,r0,r1) = p0 + p1
 * 23       project(ret,r1,r0) = p2 + p3
 * 24       project(ret,r1,r1) = p4 + p0 - p2 - p6
 * 25   return ret
 */

#ifndef SQUARE_MATRIX_MULTIPLY_H
#define SQUARE_MATRIX_MULTIPLY_H
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/operation.hpp>
#include <boost/numeric/ublas/storage.hpp>
#include <boost/numeric/ublas/io.hpp>

//! matrix multiplication using two nested loops
template<typename T>
boost::numeric::ublas::matrix<T>
square_matrix_multiply(const boost::numeric::ublas::matrix<T>& lhs,
                       const boost::numeric::ublas::matrix<T>& rhs);

//! matrix multiplication using recurssion
template<typename T>
boost::numeric::ublas::matrix<T>
inline square_matrix_multiply_recursive(const boost::numeric::ublas::matrix<T>& lhs,
                                        const boost::numeric::ublas::matrix<T>& rhs);

//! strassen method
template<typename T>
boost::numeric::ublas::matrix<T>
inline square_matrix_multiply_strassen(const boost::numeric::ublas::matrix<T>& lhs,
                                       const boost::numeric::ublas::matrix<T>& rhs);



//! matirx multiplication with the most straightforward way.
template<typename T>
inline boost::numeric::ublas::matrix<T>
square_matrix_multiply(const boost::numeric::ublas::matrix<T>& lhs,
           const boost::numeric::ublas::matrix<T>& rhs)
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

//! matrix multiplication using recurssion
template<typename T>
boost::numeric::ublas::matrix<T>
inline square_matrix_multiply_recursive(const boost::numeric::ublas::matrix<T>& lhs,
                                        const boost::numeric::ublas::matrix<T>& rhs)
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

//! strassen method
template<typename T>
boost::numeric::ublas::matrix<T>
inline square_matrix_multiply_strassen(const boost::numeric::ublas::matrix<T>& lhs,
                                       const boost::numeric::ublas::matrix<T>& rhs)
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

#endif // SQUARE_MATRIX_MULTIPLY_H











