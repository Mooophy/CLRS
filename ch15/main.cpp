#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include "color.hpp"
#include "matrix.hpp"

int main()
{
    ch15::Matrix<int> mat(3,3,0);

    ch15::copy_row(mat, std::vector<int>({1,2,3}), 0);
    ch15::print(mat);

    std::cout << color::red("\nend\n");
    return 0;
}
