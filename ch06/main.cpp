#include <vector>
#include <iostream>
#include "../misc/alan.hpp"
#include "heap.hpp"

int main()
{
    std::vector<int> v {16,4,10,14,7,9,3,2,8,1};
    clrs::ch6::min_heapify(v,1);
    alan::print_container(v);

    alan::end();
    return 0;
}

