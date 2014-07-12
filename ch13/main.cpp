#include <iostream>
#include <vector>
#include "red_black_tree_with_bh.hpp"

int main()
{
    ch13::RedBlackTreeWithBh<int, std::string> tree;

    std::vector<int> v = {41,38,31,12,19,8,7,5,2,0};

    for(auto i : v)
        tree.insert(i);
    tree.print();

    std::cout << debug::green("\n\nend") << std::endl;

    return 0;
}

