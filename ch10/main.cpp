#include <iostream>
#include "mergeable_heap.hpp"

int main()
{
    ch10::mergeable_heap_SL<int> lhs, rhs;

    lhs.insert(10);
    lhs.insert(11);
    lhs.insert(11);
    lhs.insert(1);

    rhs.insert(2);
    rhs.insert(3);
    rhs.insert(6);

    ch10::mergeable_heap_SL<int> ret = lhs + rhs;

    ret.print();
}

