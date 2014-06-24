#include <iostream>
#include <string>
#include "node.hpp"
#include "binary_search_tree.hpp"

int main()
{
    ch12::binary_search_tree<int, std::string> tree;

    tree.insert(12,"002");
    tree.insert(5,"005");
    tree.insert(199,"001");

    tree.search_recur(5)->print();
    tree.search_itera(5)->print();


    return 0;
}

