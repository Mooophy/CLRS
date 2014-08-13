/***************************************************************************
 *  @file       matrix.hpp
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

//! alias for cha15
template<typename T>
using Matrix = boost::numeric::ublas::matrix<T>;

/**
 * @brief print a matrix like a matrix
 */
template<typename T>
void print(const ch15::Matrix<T>& mat)
{
    using SizeType  =   typename ch15::Matrix<T>::size_type;

    for(SizeType row = 0; row != mat.size1(); ++row)
    {
        for(SizeType col = 0; col != mat.size2(); ++col)
            std::cout << mat(row, col) << " ";
        std::cout << "\n\n";
    }
}

/**
 * @brief copy_row
 * @param mat
 * @param rng
 * @param row
 *
 * @date  13 aug 2014
 *
 * copy a row from a std container into a boost matrix.
 * implemented for longest_mono_increasing.hpp
 */
template<typename Range>
void inline
copy_row(ch15::Matrix<typename Range::value_type>& mat,
                const Range& rng,
                typename ch15::Matrix<typename Range::value_type>::size_type
                        row)
{
    assert(rng.size()   ==  mat.size2());
    using SizeType  =   typename Range::size_type;

    for(SizeType count = 0; count != rng.size(); ++count)
        mat(row, count) =   rng[count];
}

}//namespace ch15



//! @brief  extending boost matrix
namespace boost { namespace numeric { namespace ublas {

/**
 * @brief forwarding declarations
 */
template<typename Range>
void
operator <<= (matrix<typename Range::value_type>& mat, const Range& rng);
template<typename Range>
void
operator >>= ( const Range& rng, matrix<typename Range::value_type>& mat);
template<typename T>
matrix<T>
operator*(const matrix<T>& lhs, const matrix<T>& rhs);

/**
 * @brief operator <<=
 * @param lhs   matrix
 * @param rhs   a stl container that stores data
 *
 * copy data from rhs to matrix, leaving data in matrix untouched when data from
 * the stl container is not enough.
 */
template<typename Range>
inline void
operator <<= (matrix<typename Range::value_type>& mat, const Range& rng)
{
    using SizeType  =   typename matrix<typename Range::value_type>::size_type;

    //! check if equal
    SizeType mat_size   =   mat.size1() *   mat.size2();
    assert(mat_size == rng.size());

    //! copy
    for(SizeType index = 0; index != mat_size; ++index)
        mat.data()[index]   =   rng[index];
}

/**
 * @brief operator >>=
 * @param lhs   a stl container that stores data
 * @param rhs   matrix
 */
template<typename Range>
inline void
operator >>= ( const Range& rng, matrix<typename Range::value_type>& mat)
{
    mat <<= rng;
}

/**
 * @brief operator *
 * @param lhs
 * @param rhs
 *
 * @page 371
 * @pseudocode MATRIX-MULTIPLY
 */
template<typename T>
inline matrix<T>
operator*(const matrix<T>& lhs, const matrix<T>& rhs)
{
    assert(lhs.size2() == rhs.size1());

    matrix<T> ret(lhs.size1(), rhs.size2());
    for(unsigned row = 0; row != lhs.size1(); ++row)
        for(unsigned col = 0; col != rhs.size2(); ++ col)
        {
            ret(row,col) = 0;
            for(unsigned count = 0 ; count != lhs.size2(); ++count)
                ret(row,col) += lhs(row,count) * rhs(count, col);
        }

    return ret;
}

}}}//namespace boost::numeric::ublas

#endif // MATRIX_HPP

//! test for matrix assignment overloading
//! i.e.    <<=
//#include <iostream>
//#include <boost/numeric/ublas/matrix.hpp>
//#include <boost/numeric/ublas/io.hpp>
//#include "color.hpp"
//#include "matrix.hpp"
//#include "matrix_chain_order.hpp"
//#include "matrix_chain_mutiply.hpp"

//int main()
//{
//    using namespace boost::numeric::ublas;

//    std::vector<int> v = {1,2,3,4,5,6,7,8,9};
//    matrix<int> mat(3,3);

//    mat <<= v;
//    std::cout << mat << std::endl;

//    std::cout << color::red("\nend\n");
//    return 0;
//}

//! @test   ch15::copy_row
//!
//#include <iostream>
//#include <boost/numeric/ublas/io.hpp>
//#include "color.hpp"
//#include "matrix.hpp"

//int main()
//{
//    ch15::Matrix<int> mat(3,3,0);

//    ch15::copy_row(mat, std::vector<int>({1,2,3}), 0);
//    ch15::print(mat);

//    std::cout << color::red("\nend\n");
//    return 0;
//}
//! @output:
//!

//1 2 3

//0 0 0

//0 0 0


//end



