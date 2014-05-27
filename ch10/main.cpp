#include <iostream>
#include "stack_by_2queues.hpp"

int main()
{
    ch10::stack_by_2queues<int> stk(3);

    for(int i = 0; i != 3; ++i)
        stk.push(i);

    for(int i = 0; i != 3; ++i)
        std::cout << stk.pop() << std::endl;

    return 0;
}

