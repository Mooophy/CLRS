#include <iostream>
#include "matrix.hpp"
#include "color.hpp"
#include "matrix_chain_order.hpp"
#include "matrix_chain_mutiply.hpp"

int main()
{
    std::vector<int> v = {30,35,15,5,10,20,25};
    ch15::MatrixChainOrder<decltype(v)> chain(v);

    chain.build();
    chain.print();

    chain.print_optimal(1,6);

    std::cout << color::red("\nend\n");
    return 0;
}

