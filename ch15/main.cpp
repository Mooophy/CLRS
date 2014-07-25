#include <iostream>
#include "cut_rod.hpp"
#include "color.hpp"
int main()
{
    std::vector<int> v = {1,5,8,9};

    std::cout << color::green("test cut_rod:\n");
    std::cout << ch15::cut_rod(v.begin(), v.size()) << std::endl;

    return 0;
}

