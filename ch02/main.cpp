#include <iostream>
#include <vector>
#include "alan.hpp"
#include "binary_search.hpp"
int main()
{
    std::vector<int> v{1,2,3,4,5,6,32,99};

    auto ret = clrs::ch2::binary_search(v.begin(),v.end(),32);
    std::cout << *ret;

    alan::end();
    return 0;
}
