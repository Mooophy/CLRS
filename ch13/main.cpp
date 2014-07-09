#include <iostream>
#include <vector>
#include "persistent_tree.hpp"

int main()
{    
    ch13::PersistentTree<int, std::string> tree;

    tree.insert(1);

    return 0;
}

