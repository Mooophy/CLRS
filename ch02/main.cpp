#include <iostream>
#include <vector>
#include "alan.hpp"
#include "bubble_sort.hpp"

int main()
{
    std::vector<int> v{1,6,88,2,0,77};
    clrs::ch2::bubble_sort(v.begin(), v.end());
    alan::print_container(v);

    alan::end();
    return 0;
}
