#include <iostream>
#include "tree.hpp"

int main()
{
    ch10::tree::binary_tree<int> tree;

    for(int i=50; i != 100; ++i)
        tree.insert(i);

    tree.print_with_prev();
}

