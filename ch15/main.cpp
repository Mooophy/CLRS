#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include "longest_common_subsequence.hpp"
#include "color.hpp"

int main()
{
    std::vector<int> lhs = {1,5,6,7,9};
    std::vector<int> rhs = {6,7,9};

    auto ret = ch15::build_lcs_table(lhs, rhs);
    std::cout << ret << std::endl;

    std::cout << color::red("\nend\n");
    return 0;
}
