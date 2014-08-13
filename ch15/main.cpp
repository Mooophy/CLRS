#include <iostream>
#include <vector>
#include "color.hpp"
#include "longest_mono_increasing_subseq.hpp"

int main()
{
    std::vector<int> v = {1,5,2,3,6,7,0,4,99};
    auto lmis = ch15::find_lmis(v);
    for(auto elem : lmis)
        std::cout << elem << " ";

    std::cout << color::red("\nend\n");
    return 0;
}
