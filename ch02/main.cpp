#include <iostream>
#include <vector>
#include "alan.hpp"
#include "merge_sort.hpp"

int main()
{
    std::vector<int> v{1,2,3};

    clrs::ch2::merge(v.begin(), v.begin()+1, v.end());

    alan::end();
    return 0;
}
