#include <iostream>
#include "mergeable_heap.hpp"

int main()
{
    ch10::mergeable_heap_SL<int> lhs;

    lhs.insert(10);


    std::cout << (lhs.empty()?  "empty" :   "not empty") << std::endl;


}

