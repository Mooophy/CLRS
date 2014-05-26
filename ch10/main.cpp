#include <iostream>
#include <stack>
#include <vector>
#include "stack.hpp"
#include "queue.hpp"
#include "deque.hpp"


int main()
{
    ch10::queue<int> q(3);

    q.enqueue(42);
    q.enqueue(42);
    q.enqueue(42);

    std::cout << q.size() << std::endl;

    return 0;
}

