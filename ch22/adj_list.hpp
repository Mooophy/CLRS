//!
//! @author Yue Wang
//! @date   18.12.2014
//!
//! @brief  Adjacency list representations for Graph
//!

#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP


#include <iostream>
#include <vector>
#include <limits>
#include <list>
#include <algorithm>


using std::vector;
using std::pair;
using std::string;
using std::list;
using std::find_if;


namespace clrs {namespace ch22 {


enum {White, Gray, Black};


template <typename Key, typename Data>
struct Vertex
{
    Vertex() = default;
    Vertex(int c, long long d, Vertex* p, Key k, Data dt = Data{}):
        color_{c},distance_{d},parent_{p},key_{k}, data_{dt}
    {}
    explicit Vertex(Key k) :
        Vertex{White, std::numeric_limits<long long>::max(), nullptr, k, Data{}}
    {}

    int color_ {White};
    long long distance_ {std::numeric_limits<long long>::max()};
    Vertex* parent_{nullptr};
    const Key key_{0};
    Data data_{};
};


template<typename K, typename D>
inline bool
operator <(Vertex<K,D> const& lhs, Vertex<K,D> const& rhs)
{
    return lhs.key_ < rhs.key_;
}

template<typename K, typename D>
inline bool
operator ==(Vertex<K,D> const& lhs, Vertex<K,D> const& rhs)
{
    return lhs.key_ == rhs.key_;
}


template<typename K,typename D>
struct Edge
{
    Vertex<K,D> u_,v_;
};


template<typename Key,typename Data>
class UndirectedGraph
{
    using V     =   Vertex<Key,Data>;
    struct List
    {
        V vertex_;
        std::list<Key> neighbors_;
    };
    using Adj   =   vector<List>;

public:

    using SizeType = typename Adj::size_type;

    UndirectedGraph() = default;

    void add_vertex(V const& v)
    {
        adj_.push_back(List{v, {}});
    }

    typename Adj::iterator find(V const& v)
    {
        return find_if(adj_.begin(), adj_.end(),[&v](List const& li){
            return  li.vertex_ == v;
        });
    }

    typename Adj::iterator begin()  {return adj_.begin();   }
    typename Adj::iterator end()    {return adj_.end();     }

    SizeType    size()  const   {   return adj_.size();     }
    bool        empty() const   {   return adj_.empty();    }

private:
    Adj adj_;
};


}}//namespace
#endif // ADJ_LIST_HPP
