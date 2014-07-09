#include <iostream>
#include <vector>
#include "persistent_tree.hpp"

int main()
{    
    ch13::PersistentTree<int, std::string> tree;

    tree.insert(1,"001");
    tree.insert(2);
    tree.insert(3);
    tree.insert(0);
    tree.insert(99);

    tree.print();

    std::cout << "\nend" << std::endl;

    return 0;
}

