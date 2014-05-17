#include <iostream>
#include"heap.h"
#include"heap_build.h"
#include"priority_queue.h"

int main()
{
    //! test:
    std::vector<std::string> v = {"3","2","44","0","zzzzzzzz"};
    ch6::priority_queue<std::string, std::less<std::string>> pq(v);

    pq.push("alan");
    std::cout << pq.size() << std::endl;
    std::cout << "\n\n" << std::endl;
    for(unsigned i = 0; i != v.size(); ++i)
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}

