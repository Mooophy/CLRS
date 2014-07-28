#include <iostream>
#include <memory>
#include "cut_rod.hpp"
#include "color.hpp"
int main()
{
    //! build the array r
    std::vector<int> v = {1,5,8,9,10};

    int result = ch15::bottom_up_with_cost(v.begin(), v.end(), 1);

    std::cout << result << std::endl;





    std::cout << color::red("\nend\n");
    return 0;
}

