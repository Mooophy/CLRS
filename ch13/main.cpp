#include <iostream>
#include <debug.hpp>
#include <vector>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{
    ch13::RedBlackTree<int,std::string> tree;

    std::vector<int> v = {2,3,5,1,6};

    for(auto i : v)
        tree.insert(i);


    tree.print();

    return 0;
}

