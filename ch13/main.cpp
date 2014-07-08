#include <iostream>
#include <vector>
#include "redblacktree.hpp"

int main()
{    
    std::vector<int> v =
        {5,1,8};
    ch13::RedBlackTree<int,std::string> tree;

    for(auto i : v)
        tree.insert(i);
    tree.print();

    //! insert node with key = 3
    tree.insert(3);
    tree.print();

    //! delete it
    tree.remove(tree.search(3));
    tree.print();

    std::cout << debug::green("\n====end====") << std::endl;

    return 0;
}

