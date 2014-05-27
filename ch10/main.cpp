#include <iostream>
#include <stack>
#include <vector>
#include "stack.hpp"
#include "queue.hpp"
#include "deque.hpp"


int main()
{
    ch10::queue<int> q(10);

    for(unsigned i=0; i != 8 ; ++i)
        q.enqueue(i);

    for(unsigned i=0; i != 8 ; ++i)
        q.dequeue();

    for(unsigned i=0; i != 8 ; ++i)
        q.enqueue(i);

    for(unsigned i=0; i != 1 ; ++i)
        q.dequeue();

    std::cout << q.size() << std::endl;


    return 0;
}

