#include <iostream>
#include <vector>
#include "alan.hpp"
#include "inversions.hpp"

int main()
{
    std::vector<int> v{2,3,8,6,1};
    auto count = clrs::ch2::inversions_count(v.begin(), v.end());
    std::cout << count;

    alan::end();
    return 0;
}
