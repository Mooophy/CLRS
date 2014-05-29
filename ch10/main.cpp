#include <iostream>
#include "list.hpp"
#include "circular_list.hpp"

int main()
{
    ch10::list::circular_list<int> l;
    l.insert(87);

    l.remove(l.search(87));

    std::cout << l.size() << std::endl;




    return 0;
}

