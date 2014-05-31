#include <iostream>
#include "circular_list.hpp"

int main()
{
    ch10::list::circular_list<int> l;
    l.insert(1);
    l.insert(222);

    std::cout << l.search(223)->key << std::endl;

    return 0;
}

