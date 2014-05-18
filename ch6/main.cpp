#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"
#include "stack.h"
#include <functional>
#include "queue.h"
#include <string>
#include "d_ary_heap.h"

int main()
{
    ch6::queue<std::string> q;

    for(int i = 0; i !=9; ++i)
    {
        q.push(std::to_string(i));
    }

    for(int i = 0; i !=9; ++i)
    {
        std::cout << q.top() << std::endl;
        q.pop();
    }

    return 0;
}

