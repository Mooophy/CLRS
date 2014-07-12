#include <iostream>
#include <vector>
#include "persistent_red_black_tree.hpp"


int main()
{
    ch13::PersistentRedBlackTree<int, std::string> tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(9);

    tree.print();

    return 0;
}

