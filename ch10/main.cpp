#include <iostream>
#include "list.hpp"
#include "circular_list.hpp"

int main()
{
    ch10::list::circular_list<int> l;

    l.insert(87);
    l.insert(77);
    l.insert(77);

    auto size = l.size();

    std::cout << size <<std::endl;





    return 0;
}

