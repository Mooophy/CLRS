#include <iostream>
#include <string>
#include <memory>
#include "debug.hpp"
#include "node.hpp"



int main()
{
    std::shared_ptr<ch14::Node<int,std::string>> node

    = std::make_shared<ch14::NodeSz<int, std::string>>();

    node->print();


    return 0;
}

