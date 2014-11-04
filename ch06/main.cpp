#include <iostream>
#include "../misc/alan.hpp"
#include "merge_k_sorted_lists.hpp"

int main()
{
    using namespace clrs::ch6;
    using NodeType  =   Node<int, std::string>;

    auto lhs = std::make_shared<NodeType>(NodeType{42, "node1", nullptr});
    auto rhs = std::make_shared<NodeType>(NodeType{99, "node1", nullptr});



    std::cout << *it;

    alan::end();
    return 0;
}
