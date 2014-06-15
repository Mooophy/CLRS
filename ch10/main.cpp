#include <iostream>
#include "mergeable_heap.hpp"
#include "merge_sort_for_list.hpp"
#include "list.hpp"

int main()
{
    ch10::mergeable_heap_UL<int> heap;
    heap.insert(42);

    heap.insert(322);

    heap.insert(255);

    heap.insert(267);

    heap.insert(1);



    heap.sort();

    heap.print();
}

