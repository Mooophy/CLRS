/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       19  May 2014
 *  @remark     This code is for Introduction to Algorithms 3rd
 *  @note       code style : STL,BOOSTs
 ***************************************************************************/

#include <vector>
#include <iterator>
#include <iostream>
#include "Young_tableau.h"

int main()
{
    ch6::Young_tableau<int> yt(3,3);
    yt.push(3);
    yt.push(2);
    yt.push(1);
    yt.push(0);

    std::cout << yt << std::endl;



    return 0;
}

