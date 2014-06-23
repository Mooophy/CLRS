/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       21  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 *
 ***************************************************************************/

#include <iostream>
#include <hash_table.hpp>

int main()
{
    auto hash =
            [](const int key)->int
            {
                return key % 9;
            };

    ch11::hash_table<int, std::string> table(10, hash);

    table.insert(6,"first try");
    table.insert(88,"try 2");
    table.insert(101,"try");

    table.erase(table.search(101));
    table.erase(table.search(6));
    table.erase(table.search(88));

    table.print();

    std::cout << "end" << std::endl;
    return 0;
}

