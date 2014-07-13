#include <iostream>
#include <vector>
#include "red_black_tree_with_bh.hpp"

int main()
{
    using Tree      =   ch13::RedBlackTreeWithBh<int, std::string>;
    using NodeType  =   ch13::Node<int, std::string>;
    using sPointer  =   typename ch13::RedBlackTree<int, std::string>::sPointer;
    using namespace ch13;

    std::vector<int> v;

    Tree lhs;
    v = {41,38,31,12,19,8,7,5,2,0};
    for(auto i : v)
        lhs.insert(i);
    lhs.print();

    Tree rhs;
    v = {3,8,1,2};
    for(auto i : v)
        rhs.insert(i);
    rhs.print();

    sPointer x = std::make_shared<NodeType>(41);
    join(lhs,x,rhs);

    std::cout << debug::green("end\n");

    return 0;
}

