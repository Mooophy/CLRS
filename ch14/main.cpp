#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "red_black_tree.hpp"
#include "order_statistic_tree.hpp"

int main()
{
    using Tree  =   ch14::OrderStatisticTree<int, std::string>;

    Tree* tree = new Tree;
    std::vector<int> v = {11,22,33,44,55,66,77,88};
    for(auto i : v)
       tree->insert(i);
    tree->print();

    std::cout << debug::red("\ntesting rank:\n");
    auto node   =   tree->search(88);
    std::cout << debug::green("the rank is: ");
    std::cout << tree->rank(node) << std::endl;

    delete tree;
    std::cout << debug::green("\nend\n");
    return 0;
}

