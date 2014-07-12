#include <iostream>
#include <vector>
#include "persistent_red_black_tree.hpp"


int main()
{
    ch13::PersistentRedBlackTree<int, std::string> tree;
    std::vector<int> v = {3,2,6,7,4,9,8};
    for(auto i : v)
        tree.insert(i);

    tree.print();
    std::cout << debug::green("\nend") << std::endl;

    return 0;
}

