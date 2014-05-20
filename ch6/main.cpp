#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"
#include "stack.h"
#include <functional>
#include "queue.h"
#include <string>
#include "d_ary_heap.h"
#include "Young_tableau.h"

int main()
{
    std::vector<int> v = {42,1,2,3};
    ch6::Young_tableau<int> matrix(v,3,3);

    std::cout << *matrix(0,3) << std::endl;

    return 0;
}

