#include <iostream>
#include <vector>
#include "alan.hpp"
#include "insertion_sort.hpp"

int main()
{
    std::vector<std::string> v{"a22","s11","33","0"};

    clrs::ch2::insertion_sort_recur(v.begin(), v.end());
    alan::print_container(v);

    alan::end();
    return 0;
}
