#include <iostream>
#include <string>
#include "binary_search_tree_succ.hpp"

int main()
{
    ch12::binary_search_tree_succ<int,std::string> tree;

    tree.insert(3,"003");
    tree.insert(9,"009");
    tree.insert(99,"099");
    tree.insert(5,"005");
    tree.insert(2,"002");
    tree.insert(6,"006");

    tree.remove(tree.search(3));

    tree.print();

    return 0;
}

