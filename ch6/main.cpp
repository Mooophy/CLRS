#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"
#include "stack.h"

int main()
{
    //! test:
    ch6::stack<std::string> stk;

    std::cout << stk.get_current() << std::endl;

    return 0;
}

