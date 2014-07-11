#include <iostream>
#include <vector>
#include "red_black_tree_no_parent.hpp"

int main()
{    
    ch13::RedBlackTreeNoParent<int,std::string> tree;

    std::vector<int> v = {2,6,7,88,1,55,23};
    for(auto i : v)
        tree.insert(i);

    tree.print();

    return 0;
}

