#include <iostream>
#include "mergeable_heap.hpp"
#include "merge_sort_for_list.hpp"
#include "list.hpp"

int main()
{
    ch10::mergeable_heap_UL<int> lhs, rhs, uni;

    lhs.insert(1);
    lhs.insert(3);
    lhs.insert(78);

    rhs.insert(78);
    rhs.insert(1);
    rhs.insert(2);

    uni = lhs + rhs;

    uni.print();
}

