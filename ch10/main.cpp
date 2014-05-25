#include <iostream>
#include <stack>
#include <vector>
#include "stack.h"


int main()
{
    ch10::stack<int> stk;

    stk.push(9);
    //stk.pop();
    std::cout << stk.top()<< std::endl;


    return 0;
}

