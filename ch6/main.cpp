#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"


int main()
{
    ch6::priority_queue<long> q;
    q.push(555555555);
    std::cout << q.top() << std::endl;

    auto q1 = q;

    std::cout << q1.top() << std::endl;
    /*
    std::vector<std::string> v{"s","al","sss"};
    ch6::priority_queue<std::string> pq(v,std::less<std::string>());

    std::cout << pq.size() << std::endl;

    for(int i = 0; i != 3; ++i)
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    std::cout << pq.size() << std::endl;
    */

    return 0;
}

