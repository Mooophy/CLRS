#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "red_black_tree.hpp"
#include "order_statistic_tree.hpp"



int main()
{
    std::shared_ptr<ch14::RedBlackTree<int, std::string>> tree =
            std::make_shared<ch14::OrderStatisticTree<int, std::string>>();


    std::vector<int> v = {3,5,1,2,8,7,9,0};
    for(auto i : v)
        tree->insert(i);

    tree->print();


    std::cout << debug::green("\nend") << std::endl;
    return 0;
}

