#include <iostream>
#include "list.hpp"

int main()
{
    using namespace ch10::list;
    double_list<int> l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.insert(4);
    l.insert(5);

    std::cout << l;



    return 0;
}

