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
    std::vector<V> seq {v1, v2, v5};

    G g;
    for(auto const& vertex : seq)
        g.add_vertex(vertex);

    cout << g.empty() << endl;
    cout << g.size()  << endl;

    cout << (g.find(v1) != g.end() ? "found" : "no such thing") << endl;

    return 0;
}

