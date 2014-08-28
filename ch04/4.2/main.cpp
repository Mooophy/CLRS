/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       26  Apr 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#include<Square_Matrix_multiply.h>
#include<iostream>
#include<boost/numeric/ublas/io.hpp>

int main ()
{
    using namespace boost::numeric::ublas;

    matrix<int> lhs(2,2), rhs(2,2);

    lhs(0,0) = 1;
    lhs(0,1) = 3;
    lhs(1,0) = 7;
    lhs(1,1) = 5;


    rhs(0,0) = 6;
    rhs(0,1) = 8;
    rhs(1,0) = 4;
    rhs(1,1) = 2;

    std::cout << square_matrix_multiply_recursive(lhs,rhs)  << std::endl;
    std::cout << square_matrix_multiply(lhs,rhs)            << std::endl;
    std::cout << square_matrix_multiply_strassen(lhs,rhs)   << std::endl;

}










