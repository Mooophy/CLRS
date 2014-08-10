#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include "lcs_with_one_table.hpp"
#include "color.hpp"

int main()
{
    std::string lhs = "ABCBDAB";
    std::string rhs = "BDCABA";

    using LCS   =   ch15::LcsWithOneTable<std::string>;
    LCS lcs(lhs, rhs);
    lcs.print_maze();

    auto sequence = lcs.generate();
    std::cout << "The longest common sequence = ";
    std::cout << color::yellow(*sequence) << std::endl;

    std::cout << color::red("\nend\n");
    return 0;
}
