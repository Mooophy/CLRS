#include <iostream>
#include <string>
#include "RadixTree.hpp"

int main()
{
    ch12::RadixTree radix;

    radix.insert("1011");
    radix.insert("100");
    radix.insert("0");
    radix.insert("10");
    radix.insert("011");
    radix.insert("0000");
    radix.insert("111");
    radix.print();

    return 0;
}

