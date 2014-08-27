#include <iostream>
#include <vector>
#include "alan.hpp"
#include "horner_rule.hpp"

int main()
{
    std::vector<int> v{1,6,88,2,3,77};
    auto ret = clrs::ch2::horner_rule(v.begin(), v.end(),3);
    std::cout << ret;

    alan::end();
    return 0;
}
