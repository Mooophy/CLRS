#include <iostream>
#include "matrix.hpp"
#include "color.hpp"

int main()
{
    ch15::Matrix<int> lhs(2,2), rhs(2,2);

    for(unsigned r = 0; r != lhs.size1(); ++r)
        for(unsigned c = 0; c != lhs.size2(); ++c)
            lhs(r,c)    =   r + c;

    for(unsigned r = 0; r != rhs.size1(); ++r)
        for(unsigned c = 0; c != rhs.size2(); ++c)
            rhs(r,c)    =   r + c;



    auto ret = ch15::operator *(lhs,rhs);

    ch15::print(ret);






    std::cout << color::red("\nend\n");
    return 0;
}

