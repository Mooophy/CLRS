#include <iostream>
#include "heap.h"
#include "heap_build.h"
#include "priority_queue.h"
#include "stack.h"
#include <functional>
#include "queue.h"
#include <string>
#include "d_ary_heap.h"

int main()
{
    std::vector<std::string> v ={"1","6","5","4","3","2"};

    ch6::max_heap_d(v.begin(), v.end(), v.begin(), 3);

    for(auto i : v) std::cout << i << std::endl;

    //auto chd = ch6::children_d(v.begin(), v.begin(), 3);

    return 0;
}

