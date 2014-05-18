#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"
#include "stack.h"
#include <functional>


int main()
{
    ch6::stack<std::string> stk;
    stk.push("sssss");
    stk.push("aa");
    stk.push("0");
    //stk.pop();

    std::cout << stk.top() << std::endl;

    return 0;
}

