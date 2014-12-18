//!
//! @author Yue Wang
//! @date   18.12.2014
//!
//! @brief  Adjacency list representations for Graph
//!

#ifndef ADJ_LIST_HPP
#define ADJ_LIST_HPP


#include <iostream>
#include <map>
#include <vector>
#include <limits>


using std::map;
using std::vector;
using std::pair;
using std::string;


namespace clrs {namespace ch22 {


enum {White, Gray, Black};


template <typename Key, typename Data = string>
struct Vertex
{
    Vertex() = default;
    Vertex(int c, long long d, Vertex* p, Key k, Data dt = Data{}):
        color_{c},distance_{d},parent_{p},key_{k}, data_{dt}
    {}
    explicit Vertex( Data k ) :
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


template<typename K,typename D>
struct Edge
{
    Vertex<K,D> u_,v_;
};




}}//namespace
#endif // ADJ_LIST_HPP
