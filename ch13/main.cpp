#include <iostream>
#include <vector>
#include "persistent_tree.hpp"


int main()
{
    ch13::PersistentTree<int, std::string>  tree;

    std::vector<int> v = {2,6,7,88,1,55};
    for(auto i : v)
        tree.insert(i);

    tree.print();

    tree.insert(23);

    tree.print();

    std::cout << "end" << std::endl;

    return 0;
}

