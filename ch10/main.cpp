#include <iostream>
#include "list.hpp"

int main()
{
    using namespace ch10::list;
    double_list<int> l;
    l.insert(10);
    l.insert(9);
    l.insert(10);
    l.insert(10);
    l.insert(10);

    std::cout << l.size() << std::endl;

    return 0;
}

