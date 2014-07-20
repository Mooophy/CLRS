#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "red_black_tree.hpp"
#include "order_statistic_tree.hpp"

int main()
{
    auto tree = new ch14::OrderStatisticTree<int, std::string>;
    std::vector<int> v = {11,22,33,44,55,66,77,88};
    for(auto i : v)
       tree->insert(i);
    tree->print();

    std::cout << debug::red("testing select:\n");
    auto node   =   tree->search(44);
    auto ret    =   tree->select(node,8);
    ret->print();

    delete tree;
    std::cout << debug::green("\nend\n");
    return 0;
}

