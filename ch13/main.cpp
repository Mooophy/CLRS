#include <iostream>
#include <debug.hpp>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{
    ch13::RedBlackTree<int,std::string> tree;

    tree.insert(3);
    tree.insert(5);
    tree.insert(1);


    tree.print();

    return 0;
}

