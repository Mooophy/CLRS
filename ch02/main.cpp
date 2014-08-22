#include <iostream>
#include <vector>
#include "insertion_sort.hpp"
#include "alan.hpp"

int main()
{
    std::vector<int> v = {3,2,1,6,99,0};
    clrs::ch2::insertion_sort(v.begin(), v.end());

    alan::prompt("the sorted sequence:");
    alan::print_container(v);
    alan::end();
    return 0;
}
