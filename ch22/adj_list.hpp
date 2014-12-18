#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP

#include <iostream>
#include <map>
#include <vector>
#include <limits>

using std::map;
using std::vector;
using std::pair;

namespace clrs {namespace ch22 {

enum {White, Gray, Black};


template <typename Data>
struct Vertex
{
    Vertex() = default;

    Vertex(int c, long long d, Vertex* p, Data k):
        color_{c},distance_{d},parent_{p},key_{k}
    {}

    explicit Vertex( Data k ) :
        Vertex{White, std::numeric_limits<long long>::max(), nullptr, k}
    {}

    int color_ {White};
    long long distance_ {std::numeric_limits<long long>::max()};
    Vertex* parent_{nullptr};
    const Data key_{0};
};

template<typename Data>
using Edge = pair<Vertex<Data>,Vertex<Data>>;


template<typename Data>
class UndirectedGraph : public map<Vertex <Data>, vector<Vertex<Data>*> >
{
public:
    using Adj =  map<Vertex<Data>, vector<Vertex<Data>* > >;
    using Adj::Adj;

    UndirectedGraph() : Adj(){}

    //! Ctor with edges list
    template<typename Iter>
    UndirectedGraph(Iter first, Iter last): Adj{}
    {

    }
};




}}//namespace
#endif // ADJ_LIST_HPP
