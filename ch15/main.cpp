#include <iostream>
#include "matrix.hpp"
#include "color.hpp"
#include "matrix_chain.hpp"

int main()
{
    std::vector<int> v = {1,2,3,4};
    ch15::MatrixChain<decltype(v)> chain(v);

    chain.build_solutions();


    chain.print_s();
    std::cout << "\n";
    chain.print_m();

    std::cout << color::red("\nend\n");
    return 0;
}

