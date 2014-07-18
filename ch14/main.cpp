#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "red_black_tree.hpp"


int main()
{
    ch14::RedBlackTree<int,std::string> tree;
    std::vector<int> v = {2,5,6,11,1,7};

    for(auto i : v)
        tree.insert(i);

    tree.print();

    std::cout << debug::yellow("\nend") << std::endl;

    return 0;
}

