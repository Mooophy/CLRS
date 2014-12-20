#ifndef VERTEX_AND_EDGE_HPP
#define VERTEX_AND_EDGE_HPP


#include <string>
#include <limits>


namespace clrs {namespace ch22 {


using std::string;


enum {White, Gray, Black};


/**
 * @brief Vertex
 */
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


}}//namespace

#endif // VERTEX_AND_EDGE_HPP
