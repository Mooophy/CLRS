#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"


int main()
{
    std::vector<std::string> v{"s","al","sss"};
    ch6::priority_queue<std::string> pq(v,std::less<std::string>());

    std::cout << pq.top() << std::endl;


    return 0;
}

