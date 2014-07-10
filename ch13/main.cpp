#include <iostream>
#include <vector>
#include "redblacktree.hpp"

int main()
{    

    ch13::RedBlackTree<int,std::string> tree;

    std::vector<int> v = {3,1,0,2,4,5,1};

    for(auto i : v)
        tree.insert(i);

    tree.print();

    return 0;
}

