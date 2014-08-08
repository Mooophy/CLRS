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
    ch15::build_chain(chain, v, 2);
    ch15::print_matrix_chain(chain);

    std::vector<int> dimens;
    ch15::build_dimensions(chain, dimens);
    for(auto d : dimens)
        std::cout << d << " ";

    ch15::MatrixChainOrder<std::vector<int>> order(dimens);
    order.build();

    std::cout << color::red("\nend\n");
    return 0;
}
