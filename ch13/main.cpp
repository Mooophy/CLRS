#include <iostream>
#include <vector>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{    
    std::vector<int> v =
        {6,5,1,1,2,34,5,6,7,8,9,8,7,4,3,2,2,3,5,6,7,2,345};
    ch13::RedBlackTree<int,std::string> tree;

    for(auto i : v)
        tree.insert(i);

    tree.print();
    std::cout << "length = " << v.size() << std::endl;

    return 0;
}

