#include <iostream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "color.hpp"
#include "matrix.hpp"
#include "matrix_chain_order.hpp"
#include "matrix_chain_mutiply.hpp"

int main()
{
    using namespace boost::numeric::ublas;

    std::vector<int> v = {1,3,3,4,5,6,7,8,9};
    matrix<int> mat(3,3);

    v >>= mat;
    std::cout << mat << std::endl;

    std::cout << color::red("\nend\n");
    return 0;
}

