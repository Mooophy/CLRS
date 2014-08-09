#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include "longest_common_subsequence.hpp"
#include "color.hpp"

int main()
{
    //! the same strings as that on page 394, CLRS.
    std::vector<std::string> lhs = {"A", "B", "C", "B", "D", "A", "B"};
    std::vector<std::string> rhs = {"B", "D", "C", "A", "B", "A"};

    auto ret = ch15::build_lcs_table(lhs, rhs);
    ch15::print(ret);

    std::cout << color::red("\nend\n");
    return 0;
}
