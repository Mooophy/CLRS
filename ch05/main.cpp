#include"random.hpp"
#include <iostream>

int main ()
{
    std::string s;
    while(std::cin >>s)
    {
        if (s == "q")   break;
        else std::cout << clrs::ch5::random_ex512(1,6) << std::endl;
    }

}
