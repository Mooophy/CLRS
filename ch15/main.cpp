#include <iostream>
#include <memory>
#include "cut_rod.hpp"
#include "color.hpp"
int main()
{
    //! build the array r
    std::vector<int> v = {1,5,8,9,10,17,17,20,24,30};
    using Iter      =   std::vector<int>::iterator;
    using TopDown   =   ch15::RodCutterTopDown<Iter>;
    using BottomUp  =   ch15::RodCutterBottomUp<Iter>;

    //! allocation for the top-down dynamic programming
    auto cut =  std::make_shared<BottomUp>(v.size());

    //! print
    std::cout << cut->optimize(v.begin(),v.size()) <<std::endl;
    cut->print_container();
    cut->print_solutions(v.begin(),v.size());

    std::cout << color::red("\nend\n");
    return 0;
}

