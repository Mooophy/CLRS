#include <iostream>
#include "list.hpp"

int main()
{
    using namespace ch10::list;
    double_list<int> l;
    l.insert(10);
    l.insert(10);

    std::cout << "test" << std::endl;

    return 0;
}

