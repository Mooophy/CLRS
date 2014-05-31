#include <iostream>
#include "list.hpp"
#include "circular_list.hpp"
#include "single_list.hpp"
#include "stack_by_list.hpp"

int main()
{

    ch10::list::single_list_ring<int> l;

    l.insert(99);
    l.insert(98);
    l.insert(9);
    l.insert(1);

    //std::cout << l.size() << std::endl;

    auto ptr = l.search(90);

    std::cout << l ;

//    //l.remove(ptr);


    return 0;
}

