/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       4  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

//! ex 5.1-2 *
//! Describe an implementation of the procedure RANDOM (a,b) that only makes calls
//! to RANDOM (0,1) What is the expected running time of your procedure, as a
//! function of a and b?
//  check random.h for pyseudocode.
//  As can be seen in the pyseudocade, the running time is theata(b+1 - a).That is
//  theata(n)
//!
//! ex 5.1-3 *
//!
//! BEGIN:
//! if heads then tails, return heads
//! if tails then heads, return tails
//! otherwise, goto BEGIN
//! referred to http://algox0.wordpress.com/2011/01/31/clrs-5-1-3/
//!



#include"random.h"
#include <iostream>

int main ()
{
    std::string s;
    while(std::cin >>s)
    {
        if (s == "q")   break;
        else std::cout << ch5::random_ex512(1,6) << std::endl;
    }

}










