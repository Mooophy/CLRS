#include <iostream>
#include <vector>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{    
    std::vector<int> v =
        {2,3,6,99,22,33,5,67};
    ch13::RedBlackTree<int,std::string> tree;

    for(auto i : v)
        tree.insert(i);
    tree.print();

    tree.remove(tree.search(6));
    tree.print();

    std::cout << debug::green("\n====end====") << std::endl;

    return 0;
}

