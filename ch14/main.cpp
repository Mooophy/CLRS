#include <iostream>
#include <string>
#include <vector>
#include "order_statistic_tree.hpp"

int main()
{
    auto tree = new ch14::OrderStatisticTree<int, std::string>;
    std::vector<int> v = {41,38,31,12,19,8};
    for(auto i : v)
       tree->insert(i);
    tree->print();


    std::cout   <<
            debug::red("\ntesting find_ith_successor(), as required in ex14.1-5:\n");
    auto node   =   tree->search(38);
    auto ret    =   tree->find_ith_successor(node,1);
    ret->print();


    delete tree;
    std::cout << debug::green("\nend\n");
    return 0;
}
