#include <iostream>
#include "queue_by_2stacks.hpp"


int main()
{
    ch10::queue_by_2stacks<int> q;

    for(int i = 0; i != 3 ; ++i)
        q.enqueue(i);

    for(int i = 0; i != 3 ; ++i){
        std::cout << q.dequeue() << std::endl;
        std::cout << "size=" << q.size() << std::endl << std::endl;
    }


    return 0;
}

