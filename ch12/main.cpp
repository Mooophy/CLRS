#include <iostream>
#include <string>
#include "node.hpp"
#include "binary_search_tree.hpp"

int main()
{
    ch12::binary_search_tree<int, std::string> tree;

    tree.insert(12,"002");
    tree.insert(5,"005");
    tree.insert(199,"199");
    tree.insert(6,"006");
    tree.insert(123,"123");
    tree.insert(127,"127");
    tree.insert(666,"666");
    tree.insert(999,"99");
    tree.insert(23,"23");

    auto node = tree.search_itera(5);
    auto pred = tree.predecessor(node);

    if(pred)
        pred->print();
    else
        std::cout << "null" << std::endl;

    return 0;
}

