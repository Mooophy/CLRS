#include <iostream>
#include <vector>
#include "persistent_red_black_tree.hpp"
#include "redblacktree.hpp"


int main()
{
    //ch13::PersistentRedBlackTree<int, std::string>
    ch13::RedBlackTree<int, std::string>
            tree;
    std::vector<int> v = {41,38,31,12,19,8,7,5,2,0};
    for(auto i : v)
        tree.insert(i);

    tree.print();
    std::cout << debug::green("\nend") << std::endl;

    return 0;
}

