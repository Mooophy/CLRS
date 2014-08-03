#include <iostream>
#include "matrix.hpp"
#include "color.hpp"
#include "matrix_chain.hpp"

int main()
{
    std::vector<int> v = {1,2,3,4,5,6};
    ch15::MatrixChain<decltype(v)> chain(v);


    std::cout << color::red("\nend\n");
    return 0;
}

