#include <iostream>
#include <vector>
#include <memory>
#include "color.hpp"
#include "node.hpp"

int main()
{
    using NodeType  =   ch15::sec5::Node<std::string,std::string>;
    using sPointer  =   ch15::sec5::sPointer<std::string,std::string>;

    sPointer node(new NodeType("eng","fre"));
    std::cout << *node << std::endl;

    std::cout << color::red("\nend\n");
    return 0;
}
