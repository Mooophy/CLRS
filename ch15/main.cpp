#include <iostream>
#include <boost/numeric/ublas/io.hpp>
#include "longest_common_subsequence.hpp"
#include "color.hpp"

int main()
{
    //! strings used on page 394, CLRS.
    std::string lhs = "ABCBDAB";
    std::string rhs = "BDCABA";

    using LCS   =   ch15::LongestCommonSubsequence<std::string>;
    LCS lcs(lhs, rhs);
    lcs.print_maze();

    auto sequence = lcs.generate();
    std::cout << "The longest common sequence = ";
    std::cout << color::yellow(sequence) << std::endl;

    std::cout << color::red("\nend\n");
    return 0;
}
