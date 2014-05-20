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
    std::vector<int> v = {1,2,3,4,888};
    ch6::Young_tableau<int> matrix(v,4,3);

    matrix.push(99);



    std::cout << matrix << std::endl;

    return 0;
}

