#include <iostream>
#include "../misc/alan.hpp"
#include "stack_n_queue.hpp"

int main()
{
    using namespace clrs::ch6;
    StaQue<int,decltype(std::less<Element<int> >{})> queue;

    queue.push(42);
    queue.push(41);
    queue.push(40);

    while(! queue.empty())
    {
        std::cout << queue.top() << " ";
        queue.pop();
    }

    alan::end();
    return 0;
}
