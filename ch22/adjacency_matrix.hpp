#ifndef ADJACENCY_MATRIX_HPP
#define ADJACENCY_MATRIX_HPP


#include <vector>
#include "vertex_and_edge.hpp"
using std::vector;



namespace clrs {namespace ch22 {

template<typename Key>
struct Matrix : public vector<vector<Key> >{};

}}//namespace
#endif // ADJACENCY_MATRIX_HPP
