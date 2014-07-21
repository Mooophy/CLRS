#include <iostream>
#include <string>
#include <vector>
#include "order_statistic_tree.hpp"

int main()
{
    std::vector<int> v = {41,38,31,12,19,8};

    std::cout << "testing find inversions for ex14.1-7:\ninversions=";
    std::cout << ch14::find_inversions(v) << std::endl;

    std::cout << debug::green("\nend\n");
    return 0;
}
