#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include "color.hpp"
#include "matrix.hpp"
#include "matrix_chain_mutiply.hpp"
#include "matrix_chain_order.hpp"

int main()
{
    std::vector<int> v = {30,35,15,5,10,20,25};

    ch15::Chain<int> chain;
    ch15::build_chain(chain, v);
    ch15::print_matrix_chain(chain);


    std::cout << color::red("\nend\n");
    return 0;
}
