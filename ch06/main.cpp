#include <vector>
#include <iostream>
#include "../misc/alan.hpp"
#include "heap.hpp"

int main()
{
    std::vector<int> v {16,4,10,14,7,9,3,2,8,1};
    std::vector<int> v1,v2,v3,v4,v5,v6;
    v1 = v2 = v3 = v4 = v5 = v6 = v;

    //! max heapify
    clrs::ch6::max_heapify(v1,1);
    alan::print_container(v1);
    std::cout << "\n";
    clrs::ch6::heapify(v2,1,std::greater<int>());
    alan::print_container(v2);

    std::cout << "\n\n";

    //! min heapify
    clrs::ch6::min_heapify(v3,1);
    alan::print_container(v3);
    std::cout << "\n";
    clrs::ch6::heapify(v4,1,std::less<int>());
    alan::print_container(v4);

    //! iteration version
    std::cout << "\n";
    clrs::ch6::heapify_itera(v5,1,std::less<int>());
    alan::print_container(v5);


    alan::end();
    return 0;
}

