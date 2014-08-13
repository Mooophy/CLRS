#include <iostream>
#include "color.hpp"
#include "longest_mono_increasing_subseq.hpp"
#include <vector>


int main()
{
    std::vector<int> lhs = {1,2,3};
    std::vector<int> rhs = {4,5,6};

    for(auto elem : (lhs + rhs))
        std::cout << elem << " ";
    std::cout << std::endl;

    for(auto elem : (lhs + 99))
        std::cout << elem << " ";
    std::cout << std::endl;

    for(auto elem : (99 + rhs))
        std::cout << elem << " ";
    std::cout << std::endl;

    std::cout << color::red("\nend\n");
    return 0;
}
