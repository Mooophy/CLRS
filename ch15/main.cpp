#include <iostream>
#include <vector>
#include <memory>
#include "color.hpp"
#include "node.hpp"

int main()
{
    using NodeType  =   ch15::sec5::NodeBase<std::string, std::string>;
    using sPointer  =   std::shared_ptr<NodeType>;

    sPointer node   =   std::make_shared<ch15::sec5::Node>("ss","zz");
    sPointer dummy  =   std::make_shared<ch15::sec5::Dummy>();

    std::cout << *node  << std::endl;
    std::cout << *dummy << std::endl;

    std::cout << color::red("\nend\n");
    return 0;
}
