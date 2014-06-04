#include <iostream>
#include "tree.hpp"

int main()
{
    ch10::tree::node<int> n;

    ch10::tree::binary_tree<int> tree;

    tree.insert(42);
    tree.insert(43);

    std::cout << "test" << std::endl;



}

