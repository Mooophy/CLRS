#include <iostream>
#include "adj_list.hpp"

int main()
{
    using V = clrs::ch22::Vertex<int>;
    using E = clrs::ch22::Edge<int>;
    using G = clrs::ch22::UndirectedGraph<int>;

    V l{0}, r{42};
    E edg{l,r};

    std::vector<E> v{edg};
    G g{v.begin(), v.end()};


    return 0;
}

