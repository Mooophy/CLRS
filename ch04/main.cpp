#include <iostream>
#include <vector>
#include "alan.hpp"
#include "max_subarray.hpp"

int main()
{
    std::vector<int> v{2,-1, 3,};
    auto ret = clrs::ch4::find_max_crossing_subarray(v.begin(),v.begin() + 1, v.end());
    std::cout << ret.sum;

    alan::end();
    return 0;
}
