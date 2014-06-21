/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       21  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 *
 ***************************************************************************/

#include <iostream>
#include <node.hpp>
#include "table_da.hpp"

int main()
{
    ch11::table_da<int, int> table(10);

    table.insert(7,33);
    table.insert(6,42);

    std::cout << table.search(6) << std::endl;

    return 0;
}

