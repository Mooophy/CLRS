#include <iostream>
#include <vector>
#include "alan.hpp"
#include "merge_sort.hpp"

int main()
{
    std::vector<int> v{3,2,1};

    clrs::ch2::merge_sort(v.begin(), v.end());
    alan::print_container(v);

    alan::end();
    return 0;
}
