#include <iostream>
#include <vector>
#include "alan.hpp"
#include "merge_with_insertion_sort.hpp"

int main()
{
    std::vector<int> v{1,6,88,2,0,77};
    clrs::ch2::merge_with_insertion_sort(v.begin(), v.end(), 2);
    alan::print_container(v);

    alan::end();
    return 0;
}
