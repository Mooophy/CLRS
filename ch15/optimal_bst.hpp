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

template<typename Node, typename Range>
class OptimalBsTree
{
public:
    using SizeType  =   typename Range::size_type;
    using sPointer  =   std::shared_ptr<Node>;
    using Table     =   ch15::Matrix<SizeType>;

    OptimalBsTree() = default;
    OptimalBsTree(const Table& table, const Range& range)
    {

    }

protected:
    sPointer root;
};

}}//namespace

#endif // OPTIMAL_BST_HPP
