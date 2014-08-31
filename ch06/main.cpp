#include <vector>
#include <iostream>
#include "../misc/alan.hpp"
#include "heap.hpp"

int main()
{
    std::vector<int> v {16,4,10,14,7,9,3,2,8,1};
    auto v2 = v;

    clrs::ch6::heapify(v.begin(), v.end(), v.begin() + 1);
    alan::print_container(v);

    std::cout << "\n";

    clrs::ch6::heapify_itera(v2.begin(), v2.end(), v2.begin() + 1);
    alan::print_container(v2);

    alan::end();
    return 0;
}

