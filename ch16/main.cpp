#include <iostream>
#include <vector>
#include "activity.hpp"
#include "alan.hpp"

int main()
{
    std::vector<int> starts     =   {1,3,0,5,3,5,6,8,8,2,12};
    std::vector<int> finishes   =   {4,5,6,7,9,9,10,11,12,14,16};
    std::vector<int> activites;

    ch16::activity_select_recur(starts, finishes, 0, activites);
    alan::print_container(activites);

    std::cout << alan::green("\nexit normally.\n");
    return 0;
}

