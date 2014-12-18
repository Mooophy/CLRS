#include <iostream>
#include <string>
#include "adj_list.hpp"

int main()
{
    using namespace std;
    using V = clrs::ch22::Vertex<int,std::string>;
    using E = clrs::ch22::Edge<int,std::string>;
    using G = clrs::ch22::UndirectedGraph<int,std::string>;

    V v1{1}, v2{2}, v5{5};
    vector<V> vs {v1, v2, v5};

    E e12{v1, v2}, e15{v1, v5}, e25{v2, v5};
    vector<E> es {e12, e15, e25};

    G g;
    for(auto const& vertex : vs)    g.add_vertex(vertex);
    for(auto const& edge : es)      g.add_edge(edge);

    cout << g.empty() << endl;
    cout << g.size()  << endl;

    cout << (g.find(v1) != g.end() ? "found" : "no such thing") << endl;
    cout << g ;

    return 0;
}

