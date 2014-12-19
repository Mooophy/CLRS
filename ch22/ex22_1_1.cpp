#include "adj_list.hpp"
#include <iostream>
#include <string>

int main()
{
    using namespace std;
    using V      = clrs::ch22::Vertex<int,std::string>;
    using E      = clrs::ch22::Edge<int,std::string>;
    using Graph  = clrs::ch22::DirectedGraph<int,std::string>;

    V v1{1}, v2{2}, v5{5};
    E e12{v1, v2}, e15{v1, v5}, e25{v2, v5};
    vector<E> es {e12, e15, e25};

    Graph g;
    for(auto const& edge : es)
        g.add_edge(edge);
    cout << g;

    auto print_outdegree = [&g]{
        cout << "outdegree of directed graph g:\n";
        auto table = g.outdegree();
        for(auto const& pair : table)
            cout << pair.first << "-->" << pair.second << endl;
    };

    print_outdegree();

    return 0;
}
