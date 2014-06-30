#include <iostream>
#include <string>
#include "binary_search_tree_succ.hpp"

int main()
{
    ch12::binary_search_tree_succ<int,std::string> tree;

    tree.insert(1,"001");
    tree.insert(9,"009");
    tree.insert(99,"099");
    tree.insert(5,"005");
    tree.insert(0,"000");

//    tree.inorder_print();

//    tree.search(99)->key = 88;

//    tree.predessor(tree.search(5))->print();

    tree.parent(tree.search(0))->print();

    return 0;
}

