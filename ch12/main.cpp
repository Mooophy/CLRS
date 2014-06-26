#include <iostream>
#include <string>
#include "node.hpp"

int main()
{
    std::shared_ptr<ch12::nodeSucc<int,std::string> > p =
           std::make_shared<ch12::nodeSucc<int,std::string>>(42,"042");

    p->successor = p;

    std::cout << (p->successor.lock()->data) << std::endl;


    return 0;
}

