#include <iostream>
#include <vector>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{    
    std::vector<int> v =
        {6,5,9};
    ch13::RedBlackTree<int,std::string> tree;

    for(auto i : v)
        tree.insert(i);


    tree.print();

    tree.sibling(tree.search(9))->print();




    std::cout << debug::green("\n====end====") << std::endl;


    return 0;
}

