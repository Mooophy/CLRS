#include <iostream>
#include <string>
#include "node.hpp"

int main()
{
    ch12::node<int, std::string> node(1,"first try");

    node.print();
    return 0;
}

