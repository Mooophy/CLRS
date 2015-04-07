#include <iostream>
#include <vector>
#include <algorithm>

#include "quick_sort.h"
#include "randomized_quick_sort.h"
#include "hoare_quicksort.h"

int main()
{
    std::vector<int> v = {5, 3, 2, 6, 9,13,67,2,1};

    //auto it = ch7::hoare_partition(v.begin(),v.end());

    ch7::hoare_quicksort(v.begin(),v.end());

    for(auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

