//!
//! @author Yue Wang
//! @date   19.12.2014
//!
//! @brief  test_for_adj_list.cpp
//!

#include <iostream>
#include <string>
#include "adj_list.hpp"

int main()
{
    using namespace std;
    using V  = clrs::ch22::Vertex<int,std::string>;
    using E  = clrs::ch22::Edge<int,std::string>;
    using DG = clrs::ch22::DirectedGraph<int,std::string>;
    using UG = clrs::ch22::UndirectedGraph<int,std::string>;

    V v1{1}, v2{2}, v5{5};
    vector<V> vs {v1, v2, v5};
    E e12{v1, v2}, e15{v1, v5}, e25{v2, v5};
    vector<E> es {e12, e15, e25};

    DG dg;
    for(auto const& vertex : vs)    dg.add_vertex(vertex);
    for(auto const& edge : es)      dg.add_edge(edge);

    cout << dg.empty() << endl;
    cout << dg.size()  << endl;
    cout << (dg.find(v1) != dg.end() ? "found" : "no such thing") << endl;
    cout << dg ;

    cout << "\n\n----------------\n\n";

    UG ug;
    for(auto const& vertex : vs)    ug.add_vertex(vertex);
    for(auto const& edge : es)      ug.add_edge(edge);

    cout << ug.empty() << endl;
    cout << ug.size()  << endl;
    cout << (ug.find(v1) != ug.end() ? "found" : "no such thing") << endl;
    cout << ug ;

    return 0;
}
//!
//! output:
//!
//0
//3
//found
//[1]-------{2,5}
//[2]-------{5}
//[5]-------{}


//----------------

//0
//3
//found
//[1]-------{2,5}
//[2]-------{1,5}
//[5]-------{1,2}
