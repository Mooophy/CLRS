#include <vector>
#include <iostream>
#include "../misc/alan.hpp"
#include "heap.hpp"

int main()
{
    std::vector<int> v {1,4};
//    clrs::ch6::heap_sort(v);
    clrs::ch6::heapify(v.begin(), v.end(), v.begin() + 1);
    alan::print_container(v);

    alan::end();
    return 0;
}

