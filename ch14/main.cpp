#include <iostream>
#include <memory>
#include "debug.hpp"
#include "node.hpp"



int main()
{
    ch14::NodeSz<int,std::string> node(42);

    node.print();


    return 0;
}

