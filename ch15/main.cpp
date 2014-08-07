#include <iostream>
#include "matrix.hpp"
#include "color.hpp"
#include "matrix_chain_order.hpp"

int main()
{
    std::vector<int> v = {30,35,15,5,10,20,25};
    ch15::MatrixChainOrder<decltype(v)> chain_order(v);

    chain_order.build();
    chain_order.print();

    chain_order.print_optimal(1,6);

    std::cout << color::red("\nend\n");
    return 0;
}
