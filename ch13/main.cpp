#include <iostream>
#include "Node.hpp"
#include "RedBlackTree.hpp"

int main()
{
    ch13::RedBlackTree<int,std::string> tree;

    tree.insert(1,"001");

    tree.print();

    return 0;
}

