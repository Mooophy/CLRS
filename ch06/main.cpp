#include <vector>
#include <iostream>
#include "../misc/alan.hpp"
#include "queue.hpp"

int main()
{
    using namespace clrs::ch6;
    Queue<std::string> queue;

    for(auto&& elem : {"alan01","alan02","alan03"})
        queue.push(elem);

    while(!queue.empty())
        std::cout << queue.pop() << std::endl;

    alan::end();
    return 0;
}

