#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include "lcs_with_one_table.hpp"
#include "color.hpp"

int main()
{
    std::string lhs = "ABCBDAB";
    std::string rhs = "BDCABA";

    ch15::LcsWithOneTable<std::string> lcs(lhs, rhs);

    lcs.print_maze();

    std::cout << color::red("\nend\n");
    return 0;
}
