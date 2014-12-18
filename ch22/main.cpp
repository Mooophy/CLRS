#include <iostream>
#include "adj_list.hpp"

int main()
{
    using V = clrs::ch22::Vertex<int,int>;
    using E = clrs::ch22::Edge<int,int>;

    V v1{1}, v2{2}, v5{5};
    E e12{v1,v2}, e25{v2,v5}, e15{v1,v5};
    std::vector<E> vec{e12, e25, e15};


    return 0;
}

