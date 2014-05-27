#include <iostream>
#include "queue_by_2stacks.hpp"
#include "queue.hpp"
#include <vector>


int main()
{
    ch10::queue<int> q(10);
    ch10::queue<int>& r = q;

    std::cout << (q == r) << std::endl;




    return 0;
}

