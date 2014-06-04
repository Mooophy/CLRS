#include <iostream>
#include "tree.hpp"

int main()
{
    ch10::tree::node<int> n;
    ch10::tree::binary_tree<int> tree;

    for(int i=0; i != 100; ++i)
        tree.insert(i);

    tree.print_by_recursion();
}

