#include <iostream>
#include <vector>
#include "color.hpp"
#include "alan.hpp"
#include "longest_mono_increasing_subseq.hpp"

int main()
{
    std::vector<int> v = {1,5,2,3,-1,4};
    auto lmis = ch15::find_lmis(v);

    alan::print_container(lmis);

    std::cout << color::red("\nend\n");
    return 0;
}
