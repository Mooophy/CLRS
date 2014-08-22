#include <iostream>
#include <vector>
#include "alan.hpp"
#include "linear_search.hpp"
int main()
{
    std::vector<int> v = {3,2,1,6,99,0};
    std::cout << *clrs::ch2::linear_search(v.begin(),v.end(),99);

    alan::end();
    return 0;
}
