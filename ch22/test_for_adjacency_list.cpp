//!
//! @author Yue Wang
//! @date   19.12.2014
//!
//! @brief  test code for Adjacency List representations for graph
//!

#include <iostream>
#include <string>
#include "adjacency_list.hpp"


using namespace std;
using V  = clrs::ch22::Vertex<int,std::string>;
using E  = clrs::ch22::Edge<int,std::string>;
using DG = clrs::ch22::DirectedGraph<int,std::string>;
using UG = clrs::ch22::UndirectedGraph<int,std::string>;

/**
 * @brief operator << for degree table
 */
inline ostream& operator<<(ostream& os, typename DG::Table const& table)
{
    for(auto const& pair : table)
        os << pair.first << " : " << pair.second << endl;
    return os;
}


/**
 * @brief make 3 edges
 *          {1  -> 2, 1  -> 5, 2  -> 5}    seen by directed    graph
 *          {1 <-> 2, 1 <-> 5, 2 <-> 5}    seen by unddirected graph
 * @return
 */
vector<E> make_edges()
{
    V v1{1}, v2{2}, v5{5};
    E e12{v1, v2}, e15{v1, v5}, e25{v2, v5};
    return {e12, e15, e25};
}

int main()
{
    vector<E> es = make_edges();
    cout << "testing Adjacency List \n\n";

    DG dg(es.cbegin(), es.cend());
    cout << "Directed Graph :\n";
    cout << "empty() = " << dg.empty()      << endl;
    cout << "size()  = " << dg.size()       << endl;
    cout << (dg.find(V{1}) != dg.end() ? "found" : "no such thing") << endl;
    cout << dg;
    cout << "deg+ : \n" << dg.outdegree()   << endl;
    cout << "deg- : \n" << dg.indegre()     << endl;


    cout << "-------------------\n\n";


    UG ug(es.cbegin(),es.cend());
    cout << "Undirected Graph :\n";
    cout << "empty() = " << ug.empty()      << endl;
    cout << "size()  = " << ug.size()       << endl;
    cout << (ug.find(V{1}) != ug.end() ? "found" : "no such thing") << endl;
    cout << ug ;

    return 0;
}
//!
//! output:
//!
//testing Adjacency List :
//Directed Graph :
//empty() = 0
//size()  = 3
//found
//[1]-------{2,5}
//[2]-------{5}
//[5]-------{}
//deg+ :
//1 : 2
//2 : 1
//5 : 0

//deg- :
//1 : 0
//2 : 1
//5 : 2

//-------------------

//Undirected Graph :
//empty() = 0
//size()  = 3
//found
//[1]-------{2,5}
//[2]-------{1,5}
//[5]-------{1,2}
