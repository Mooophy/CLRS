#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "red_black_tree.hpp"
#include "order_statistic_tree.hpp"


int main()
{
    ch14::RedBlackTree<int, std::string>*
            tree =
                new ch14::OrderStatisticTree<int, std::string>;

    std::vector<int> v = {3,4,1,5,6,2,7,0,10,65,23};
    for(auto i : v)
       tree->insert(i);

    std::cout << debug::red("deleting!!:\n");
    tree->remove(tree->search(4));

    tree->print();

    std::cout << debug::green("\nend\n");
    delete tree;
    return 0;
}

