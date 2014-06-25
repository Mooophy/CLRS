#include <iostream>
#include <string>
#include "node.hpp"
#include "binary_search_tree.hpp"

int main()
{
    ch12::binary_search_tree<int, std::string> tree;

    tree.insert_recur(5,"005");
    tree.insert_recur(611,"611");
    tree.insert_recur(6,"006");
    tree.insert_recur(16,"016");

    tree.inorder_print();

    return 0;
}

