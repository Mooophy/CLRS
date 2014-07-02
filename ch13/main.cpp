#include <iostream>
#include "Node.hpp"

int main()
{
    ch13::Node<int, std::string> node(2,"003", ch13::Color::Red);

    node.print();

    return 0;
}

