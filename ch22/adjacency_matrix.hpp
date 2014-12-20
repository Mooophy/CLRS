#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP


#include <vector>
#include "vertex_and_edge.hpp"
using std::vector;



namespace clrs {namespace ch22 {

template<typename Key>
class Matrix : public vector<vector<Key> >
{
    using Super = vector<vector<Key> >;

public:
};


template<typename Key, typename Data>
class AdjMatrix
{
    using V = Vertex<Key,Data>;
    using E = Edge<Key,Data>;
public:
    using SizeType = typename vector<V>::size_type;

    AdjMatrix() = default;

    void add_vertex(V const& vertex)
    {
        Key key = vertex.key_;
        data_.push_back(vertex);
    }

    SizeType    size()  const   {return data_.size();   }
    bool        empty() const   {return data_.empty();  }


private:
    Matrix<Key> mat_;
    vector<V> data_;
};

}}//namespace
#endif // ADJACENCY_MATRIX_HPP
