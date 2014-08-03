#include <iostream>
#include "matrix.hpp"
#include "color.hpp"
#include "matrix_chain.hpp"

int main()
{
    std::vector<int> v = {30,35,15,5,10,20,25};
    ch15::MatrixChain<decltype(v)> chain(v);

    chain.build();
    chain.print();

    std::cout << color::red("\nend\n");
    return 0;
}

