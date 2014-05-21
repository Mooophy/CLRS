#include <iostream>
#include "quick_sort.h"
#include <vector>


int main()
{
    std::vector<std::string> v = {"13","19","9","5","12","8","7","4","21","2","6","11"};
    //std::cout << *ch7::partition(v.begin(),v.end()) << std::endl;

    ch7::quick_sort(v.begin(), v.end());

    for(auto i : v)
        std::cout << i << " ";

    std::cout << std::endl;

    return 0;
}

