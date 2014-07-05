#include <iostream>
#include <debug.hpp>
#include <vector>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{
    ch13::RedBlackTree<int,std::string> tree;

    std::vector<int> v = {8,5,7,1};

    for(auto i : v)
        tree.insert(i);

    tree.print();

    std::cout << debug::green("after left-rotate:\n\n");

    tree.right_rotate(tree.search(8));

    tree.print();

    std::cout << "end" << std::endl;

    return 0;
}

