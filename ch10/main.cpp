#include <iostream>
#include "queue_by_list.h"

int main()
{
    ch10::list::queue_by_list<long> q;

    for(int i = 0; i != 10; ++i)
        q.enqueue(i);

    for(int i = 0; i != 10; ++i)
        std::cout << q.dequeue() << std::endl;

    return 0;
}

