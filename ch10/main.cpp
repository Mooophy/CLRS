#include <iostream>
#include <stack>
#include <vector>
#include "stack.hpp"
#include "queue.hpp"
#include "deque.hpp"


int main()
{
    ch10::deque<int> dq(10);

    for(int i = 0; i != 10 ; ++i)
        dq.push_back(i);

    for(int i = 0; i != 10 ; ++i)
    {
        std::cout << dq.front() << std::endl;
        dq.pop_front();
    }

    return 0;
}

