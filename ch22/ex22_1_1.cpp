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
    cout << "Directed Graph g :\n" << g << endl;

    auto print = [&](typename Graph::Table const& table ) -> ostream& {
        for(auto const& pair : table)
            cout << pair.first << " : " << pair.second << endl;
        return cout;
    };

    cout << "deg+\n";
    print(g.outdegree()) << endl;
    cout << "deg-\n";
    print(g.indegre());

    return 0;
}
//!
//! @output :
//!
//Directed Graph g :
//[1]-------{2,5}
//[2]-------{5}
//[5]-------{}

//deg+
//1 : 2
//2 : 1
//5 : 0

//deg-
//1 : 0
//2 : 1
//5 : 2
