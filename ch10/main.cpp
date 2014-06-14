#include <iostream>
#include "mergeable_heap.hpp"

int main()
{
    ch10::mergeable_heap_UL<int> heap;

    for(int i=0; i != 100; ++i)
        heap.insert(i);

    for(int i=0; i != 100; ++i)
        std::cout << heap.extract_min() << std::endl;
}

