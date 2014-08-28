#include <iostream>
#include <vector>
#include "alan.hpp"
#include "horner_rule.hpp"

int main()
{
    std::vector<int> v{1,6,88,2,3,77};

    auto by_horner  =   clrs::ch2::horner_rule(v.begin(), v.end(),3);
    auto by_naive   =   clrs::ch2::polynomial_evaluate(v.begin(), v.end(), 3);
    std::cout << "by horner : " << by_horner << std::endl;
    std::cout << "by naive  : " << by_naive  << std::endl;

    alan::end();
    return 0;
}
