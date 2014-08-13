#include <iostream>
#include "color.hpp"
#include "longest_mono_increasing_subseq.hpp"
#include <vector>


int main()
{
    std::vector<int> lhs = {1,2,3};
    std::vector<int> rhs = {4,5,6};
    auto ret = lhs + rhs;

    for(auto elem : ret)
        std::cout << elem << " ";

    std::cout << color::red("\nend\n");
    return 0;
}
