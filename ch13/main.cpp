#include <iostream>
#include <debug.hpp>
#include <vector>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{
    ch13::RedBlackTree<int,std::string> tree;

    std::vector<int> v = {2,6,3};

    for(auto i : v)
        tree.insert(i);

    tree.print();

    std::cout << debug::green("after left-rotate:\n\n");

    tree.left_rotate(tree.search(2));

    tree.print();

    std::cout << "end" << std::endl;

    return 0;
}

