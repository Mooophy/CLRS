//! @Alan
//!
//! Ex2.1-4
//! Consider the problem of adding two n-bit binary integers, stored in two n-element
//! arrays A and B. The sum of the two integers should be stored in binary form in
//! an ( n+1 )-element array C .
//!
//! State the problem formally and write pseudocode for
//! adding the two integers.
//  INPUT:  Two sequences of n binary numbers A and B that represent two n-bit integers
//  OUTPUT: One sequences of n+1 binary number C that represents the sum of A and B

/** @brief Pseudocode: sum of two n-bit numbers
 *
 *Sum_of_Two(A,B)
 *  int carry
 *  int C[n + 1]
 *  for i = n downto 1      //note : the first element stores the MSB.
 *      C[i+1]  = (A[i] + B[i] + carry) &   0x01
 *      carry   = (A[i] + B[i] + carry) >>  0x01
 *  C[1] = carry
 ************************************************/

#include <iostream>
#include <vector>

std::vector<int>
sum_of_two(const std::vector<int>& lhs, const std::vector<int>& rhs);
int main()
{
    std::vector<int> lhs = {1,0,0,0,1,0,1,1};
    std::vector<int> rhs = {1,0,1,1,1,1,1,1};

    auto sum = sum_of_two(lhs, rhs);
    for (auto i : sum)  std::cout << i << " ";

    return 0;
}

//! implementation
std::vector<int>
sum_of_two(const std::vector<int> &lhs, const std::vector<int> &rhs)
{
    int carry = 0;
    std::vector<int> ret(lhs.size()+1,0);

    for(int i = lhs.size() -1; i != -1; --i)
    {
        ret[i+1] = (lhs[i] + rhs[i] + carry) &    0x01;
        carry    = (lhs[i] + rhs[i] + carry) >>   0x01;
    }

    ret[0] = carry;

    return ret;
}



