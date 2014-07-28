#include <iostream>
#include <memory>
#include "color.hpp"
#include "fibonacci.hpp"

int main()
{
    ch15::Fibonacci<long long> fibo;

    std::cout << fibo(50) << std::endl;
    fibo.print();

    std::cout << color::red("\nend\n");
    return 0;
}

