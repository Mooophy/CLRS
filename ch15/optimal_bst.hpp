/***************************************************************************
 *  @file       optimal_bst.hpp
 *  @author     alan.w
 *  @date       15  August 2014
 *  @remark     CLRS implementation, using C++ templates.
 ***************************************************************************/
#ifndef OPTIMAL_BST_HPP
#define OPTIMAL_BST_HPP

#include "node.hpp"
#include "matrix.hpp"

namespace ch15 { namespace sec5 {



template<typename Node>
class OptimalBsTree;


template<typename Node>
class OptimalBsTree
{
public:
    using sPointer  =   typename Node::sPointer;

    OptimalBsTree() =   default;
    OptimalBsTree(sPointer root):
        root(root)
    {}
private:
    sPointer root;
};



}}//namespace

#endif // OPTIMAL_BST_HPP
