#include <iostream>
#include "mergeable_heap.hpp"

int main()
{
    ch10::mergeable_heap_SL<int> heap;
    heap.insert(42);
    heap.insert(48);
    heap.insert(41);
    heap.insert(49);
    heap.insert(41);
    heap.insert(42);

    if(heap.search(41))
        std::cout << "found" << std::endl;

    heap.print();

}

