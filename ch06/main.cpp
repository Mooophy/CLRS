#include <vector>
#include <iostream>
#include "../misc/alan.hpp"
#include "priority_queue.hpp"

int main()
{
    clrs::ch6::PriorityQueue<int> queue {{1,2,3,4,5,6}, std::greater<int>()};
    queue.push(43);
    queue.push(42);
    queue.pop();
    for(auto elem : {11,13,15,16,19})
        queue.push(elem);

    std::cout << queue.top();

    alan::end();
    return 0;
}

