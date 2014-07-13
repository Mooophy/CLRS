#include <iostream>
#include <vector>
#include "red_black_tree_with_bh.hpp"

int main()
{
    std::vector<int> v;

    ch13::RedBlackTreeWithBh<int, std::string> lhs;
    v = {41,38,31,12,19,8,7,5,2,0};
    for(auto i : v)
        lhs.insert(i);
    lhs.print();

    ch13::RedBlackTreeWithBh<int, std::string> rhs;
    v = {3,8,1,2};
    for(auto i : v)
        rhs.insert(i);
    rhs.print();

    ch13::Node<int, std::string> x(5);

    ch13::join(lhs,x,rhs);


    return 0;
}

