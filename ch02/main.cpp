#include <iostream>
#include <vector>
#include "alan.hpp"
#include "merge_sort.hpp"

int main()
{
    std::vector<std::string> v{"99","22","z55","s11","b33"};

    clrs::ch2::merge_sort(v.begin(), v.end());
    alan::print_container(v);

    alan::end();
    return 0;
}
