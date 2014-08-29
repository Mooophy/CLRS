#include <iostream>
#include <vector>
#include "alan.hpp"
#include "max_subarray.hpp"


int main()
{
    std::vector<int> v{1,-2, -3};
    auto ret = clrs::ch4::brute_force_find_max_subarray(v.begin(), v.end());
    std::cout << ret.sum;

    alan::end();
    return 0;
}
