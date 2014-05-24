#include <iostream>
#include <vector>
#include <algorithm>

#include "quick_sort.h"
#include "randomized_quick_sort.h"

int main()
{
    std::vector<float> v = {5, 3, 2, 6, 9};

/*  -- uncomment for test
    //! test quick_sort
    //ch7::quick_sort(v.begin(), v.end());
    //! test randomized_quick_sort
    ch7::randomized_quicksort(v.begin(),v.end());
*/
    for(auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

