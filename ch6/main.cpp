#include <iostream>
#include"heap.h"
#include"heap_build.h"
#include"priority_queue.h"

int main()
{

    std::vector<std::string> v = {"3","2","1","0","zzzzzzzz"};
    ch6::priority_queue<std::string > pq(v);
    std::cout << pq.top() << std::endl;
    std::cout << pq.size()<< std::endl;
    pq.pop();
    std::cout << pq.size()<< std::endl;


    return 0;
}

