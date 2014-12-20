#include "adjacency_matrix.hpp"
#include <iostream>

using namespace std;
using AdjMatrix = clrs::ch22::AdjMatrix<int, std::string>;

int main()
{

    AdjMatrix g;
    cout << g.empty() << endl;
    cout << g.size()  << endl;

    cout << "exit" << endl;
    return 0;
}
