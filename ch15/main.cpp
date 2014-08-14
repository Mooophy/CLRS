#include <iostream>
#include <vector>
#include "color.hpp"
#include "alan.hpp"
#include "longest_mono_increasing_subseq.hpp"

int main()
{
    std::vector<int> v = {1,2,5,3,4};
    auto lmis = ch15::find_lmis_On2(v);
    alan::print_container(lmis);

    std::cout << color::red("\nend\n");
    return 0;
}
