#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "red_black_tree.hpp"
#include "order_statistic_tree.hpp"


int main()
{
    ch14::RedBlackTree<int, std::string>*
            tree = new ch14::OrderStatisticTree<int, std::string>;

    std::vector<int> v = {3,4,1,7,2,9,0};
    for(auto i : v)
       tree->insert(i);

    tree->print();

    std::cout << debug::green("\nend\n");
    return 0;
}

