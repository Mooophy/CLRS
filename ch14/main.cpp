#include <iostream>
#include <string>
#include <vector>
#include "order_statistic_tree.hpp"

int main()
{
    auto tree = new ch14::OrderStatisticTree<int, std::string>;
    std::vector<int> v = {11,22,33,44,55,66,77,88};
    for(auto i : v)
       tree->insert(i);
    tree->print();


    std::cout   <<  debug::green("\ntesting find_rank_with_key(), as required in ex14.1-4:\nrank=")
                <<  tree->find_rank_with_key(44) << std::endl;


    delete tree;
    std::cout << debug::green("\nend\n");
    return 0;
}
