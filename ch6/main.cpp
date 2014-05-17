#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"


int main()
{
    std::vector<std::string> v{"s","al","sss"};
    ch6::priority_queue<std::string> pq(v,std::greater<std::string>());


    for(int i = 0; i != 3; ++i)
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}

