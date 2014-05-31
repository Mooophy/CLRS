#include <iostream>
#include "list.hpp"
#include "circular_list.hpp"
#include "single_list.hpp"

int main()
{

    ch10::list::single_list<int> l;

    l.insert(99);
    l.insert(98);
    l.insert(9);

    std::cout << l.size() << std::endl;

    auto ptr = l.search(90);

    std::cout << ptr->key << std::endl;

    //l.remove(ptr);


    return 0;
}

