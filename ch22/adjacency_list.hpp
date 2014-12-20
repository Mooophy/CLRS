//!
//! @author Yue Wang
//! @date   18.12.2014
//!
//! @brief  Adjacency list representations for Graph
//!

#ifndef ADJACENCY_LIST_HPP
#define ADJACENCY_LIST_HPP


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <map>
#include "vertex_and_edge.hpp"


using std::vector;
using std::pair;
using std::string;
using std::list;
using std::find_if;
using std::ostream;
using std::endl;
using std::to_string;
using std::map;


namespace clrs {namespace ch22 {


template<typename Key,typename Data>
class AdjList;
template<typename Key,typename Data>
ostream& operator<<(ostream& os, AdjList<Key, Data> const&);


/**
 * @brief Adjacency list
 * @note abstract base class for both Directed and Undirected Graph
 *
 * @concepts:
 *      Container::push_back()
 */
template<typename Key,typename Data>
class AdjList
{
    friend ostream&
    operator<< <Key, Data> (ostream& os, AdjList<Key, Data> const&);

    using V     =   Vertex<Key,Data>;
    using E     =   Edge<Key,Data>;
    struct List
    {
        void add(Key k){    neighbours_.push_back(k);   }
        V vertex_;
        vector<Key> neighbours_;
    };
    using Adj   =   vector<List>;

public:

    using SizeType  =   typename Adj::size_type;
    using Iter      =   typename Adj::iterator;
    using ConstIter =   typename Adj::const_iterator;

    AdjList() = default;

    void add_vertex(V const& v)
    {
        if(end() == find(v))
            adj_.push_back(List{v, {}});
    }

    void add_edge(E const& edge)
    {
        do_add_edge(edge);
    }

    Iter find(V const& v)
    {
        return find_if(adj_.begin(), adj_.end(),[&v](List const& li){
            return  li.vertex_ == v;
        });
    }

    ConstIter   begin()     const   {   return adj_.cbegin();   }
    ConstIter   end()       const   {   return adj_.cend();     }

    Iter        begin()             {   return adj_.begin();    }
    Iter        end()               {   return adj_.end();      }

    SizeType    size()      const   {   return adj_.size();     }
    bool        empty()     const   {   return adj_.empty();    }

    virtual ~AdjList(){}
protected:
    Adj adj_;
private:
     virtual void do_add_edge(E const&) = 0;
};


template<typename Key,typename Data>
ostream& operator<<(ostream& os, AdjList<Key, Data> const& g)
{
    for(auto const& li : g)
    {
        auto ver = li.vertex_.str();
        string line(10, '-');
        for(unsigned i=0; i!=ver.size(); ++i)   line[i] = ver[i];
        line += "{";
        for(auto const& key : li.neighbours_)   line += to_string(key) + ",";
        if(! li.neighbours_.empty())
            line.back() = '}';
        else
            line += "}";
        os << line << endl;
    }
    return os;
}


/**
 * @brief Directed Graph
 *
 * Adjacency list representation.
 */
template<typename Key, typename Data>
class DirectedGraph : public AdjList<Key, Data>
{
    using Super = AdjList<Key,Data>;
    virtual void do_add_edge(Edge<Key,Data> const& edge) override
    {
        Super::add_vertex(edge.u_);
        Super::add_vertex(edge.v_);
        Super::find(edge.u_)->add(edge.v_.key_);
    }

public:
    using Table = map<Key, typename Super::SizeType>;

    DirectedGraph() = default;
    template<typename Iter>
    DirectedGraph(Iter first, Iter last) : Super{}
    {
        for(auto it = first; it != last; ++it)    Super::add_edge(*it);
    }

    Table outdegree() const
    {
        Table ret;
        for(auto const& li : *this)
            ret[li.vertex_.key_] = li.neighbours_.size();
        return ret;
    }

    Table indegre() const
    {
        Table ret;
        for(auto const& li : *this)
            ret[li.vertex_.key_] = 0;
        for(auto const& li : *this)
            for(auto const& key : li.neighbours_)
                ++ret[key];
        return ret;
    }
};


/**
 * @brief The UndirectedGraph class
 *
 * Adjacency list representation.
 */
template<typename Key, typename Data>
class UndirectedGraph : public AdjList<Key, Data>
{
    using Super = AdjList<Key,Data>;
    virtual void do_add_edge(Edge<Key,Data> const& edge) override
    {
        Super::add_vertex(edge.u_);
        Super::add_vertex(edge.v_);
        Super::find(edge.u_)->add(edge.v_.key_);
        Super::find(edge.v_)->add(edge.u_.key_);
    }

public:
    UndirectedGraph() = default;
    template<typename Iter>
    UndirectedGraph(Iter first, Iter last) : Super{}
    {
        for(auto it = first; it != last; ++it)    Super::add_edge(*it);
    }
};


}}//namespace
#endif // ADJACENCY_LIST_HPP
