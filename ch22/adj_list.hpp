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
#include <string>


using std::vector;
using std::pair;
using std::string;
using std::list;
using std::find_if;
using std::ostream;
using std::endl;
using std::to_string;


namespace clrs {namespace ch22 {


enum {White, Gray, Black};


template <typename Key, typename Data>
struct Vertex
{
    Vertex() = default;

    Vertex(int c, long long d, const Vertex* p, Key k, Data dt = Data{}):
        color_{c},distance_{d},parent_{p},key_{k}, data_{dt}
    {}

    explicit Vertex(Key k) :
        Vertex{White, std::numeric_limits<long long>::max(), nullptr, k, Data{}}
    {}

    string str() const
    {
        return "[" + std::to_string(key_) + "]";
    }

    int color_ {White};
    long long distance_ {std::numeric_limits<long long>::max()};
    const Vertex* parent_{0};
    const Key key_{0};
    Data data_{};
};


template<typename Key, typename Data>
inline ostream& operator <<(ostream& os, Vertex<Key, Data> const& v)
{
    return os << "[" << v.key_ << "]";
}


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
class AdjList;
template<typename Key,typename Data>
ostream& operator<<(ostream& os, AdjList<Key, Data> const&);


/**
 * @brief The UndirectedGraph class
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

    void add_edge(E const& e)
    {
        add_vertex(e.u_);
        add_vertex(e.v_);
        find(e.u_)->add(e.v_.key_);
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

private:
    Adj adj_;
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


}}//namespace
#endif // ADJ_LIST_HPP
