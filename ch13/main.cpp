#include <iostream>
#include <vector>
#include <node.hpp>
#include "redblacktree.hpp"

int main()
{    
    std::vector<int> v =
        {41,38,31,12,19,8};
    ch13::RedBlackTree<int,std::string> tree;

    for(auto i : v)
        tree.insert(i);
    tree.print();

    tree.remove(tree.search(8));
    tree.print();
    tree.remove(tree.search(12));
    tree.print();
    tree.remove(tree.search(19));
    tree.print();
    tree.remove(tree.search(31));
    tree.print();
    tree.remove(tree.search(38));
    tree.print();
    tree.remove(tree.search(41));
    tree.print();



    std::cout << debug::green("\n====end====") << std::endl;

    return 0;
}

