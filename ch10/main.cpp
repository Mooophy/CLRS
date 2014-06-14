#include <iostream>
#include "mergeable_heap.hpp"

int main()
{
    ch10::mergeable_heap_UL<int> heap;

    heap.extract_min();


    //heap.print();

    std::cout<< heap.minimum()->key << std::endl;
}

