#include <iostream>
#include "list.hpp"
#include "circular_list.hpp"
#include "single_list.hpp"
#include "stack_by_list.hpp"

int main()
{
//    ch10::list::single_list_ring<int> l;
//    l.insert(99);
//    l.insert(98);
//    l.insert(9);
//    l.insert(1);
//    l.remove(l.begin());
//    auto ptr = l.search(90);

//    std::cout << l ;
    ch10::list::stack_by_list<int> stk;

//    stk.enqueue(1);

//    stk.enqueue(2);

//    stk.enqueue(3);

//    stk.dequeue();

//    stk.print();
    for(int i = 0; i != 10; ++i)
    {
        stk.enqueue(i);
    }

    for(int i = 0; i != 10; ++i)
    {
        std::cout << stk.dequeue() << std::endl;
    }

    return 0;
}

