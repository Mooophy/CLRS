#include <iostream>
#include <memory>
#include "cut_rod.hpp"
#include "color.hpp"
int main()
{
    //! build the array r
    std::vector<int> v = {1,5,8,9};
    using Iter      =   std::vector<int>::iterator;
    using TopDown   =   ch15::RodCutterTopDown<Iter>;

    //! allocation for the top-down dynamic programming
    auto cut =  std::make_shared<TopDown>(v.begin(), v.end());

    //! print
    std::cout << cut->optimize(v.begin(),v.size()) <<std::endl;
    cut->print_container();

    return 0;
}

