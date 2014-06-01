#include <iostream>
#include "single_list.hpp"

int main()
{
    ch10::list::single_list_ring<int> l;
    for(int i = 0; i != 10; ++i)
        l.insert(i);

    l.reverse();

    std::cout << l << std::endl;
}

