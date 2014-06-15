#include <iostream>
#include "mergeable_heap.hpp"
#include "merge_sort_for_list.hpp"
#include "list.hpp"

int main()
{
    std::shared_ptr<ch10::list::node<int>> node = std::make_shared<ch10::list::node<int>>(42);
    ch10::merge_sort_for_list(node);
}

