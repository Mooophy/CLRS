#include <iostream>
#include <stack>
#include <vector>
#include "stack.h"
#include "queue.h"


int main()
{
    ch10::queue<int> q(3);

    q.enqueue(42);
    q.enqueue(42);
    q.enqueue(42);
    q.enqueue(42);

    std::cout << q.dequeue() << std::endl;

    return 0;
}

