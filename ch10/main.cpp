#include <iostream>
#include "mergeable_heap.hpp"

int main()
{
    ch10::mergeable_heap_SL<int> lhs;

    lhs.insert(10);
    lhs.insert(11);
    lhs.insert(11);
    lhs.insert(1);


    std::cout << (lhs.empty()?  "empty" :   "not empty") << std::endl;

    lhs.print();

    std::cout << lhs.extract_min() << std::endl;


}

