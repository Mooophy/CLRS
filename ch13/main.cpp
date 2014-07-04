#include <iostream>
#include "Node.hpp"
#include "RedBlackTree.hpp"
#include <vector>

int main()
{
    ch13::RedBlackTree<int,std::string> tree;

    std::vector<int> v = {1,5,9};

    for(auto i :v)
        tree.insert(i,"test");


    tree.print();


    return 0;
}

