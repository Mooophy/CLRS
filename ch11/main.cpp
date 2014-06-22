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

    table.print();

    std::cout << table.search(101)->data << std::endl;
    table.erase(table.search(101));

    return 0;
}

