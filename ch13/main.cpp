#include <iostream>
#include "Node.hpp"
#include "RedBlackTree.hpp"
#include <vector>

int main()
{
    ch13::RedBlackTree<int,std::string> tree;

    std::vector<int> v = {1,9,5};

    for(auto i :v)
        tree.insert(i,"test");


    std::cout << "\033[1;33m\n\n\nFinal state:\033[0m";
    tree.print();

    std::cout << "\nend" << std::endl;


    return 0;
}

