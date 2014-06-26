/***************************************************************************
 *  @file       binary_search_tree_succ.hpp
 *  @author     Alan.W
 *  @date       26  June 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
//!
//! 12.3-5
//! Suppose that instead of each node x keeping the attribute x.p, pointing to x’s
//! parent, it keeps x.succ, pointing to x’s successor. Give pseudocode for SEARCH ,
//! INSERT , and DELETE on a binary search tree T using this representation. These
//! procedures should operate in time O(h), where h is the height of the tree T .
//! (Hint:You may wish to implement a subroutine that returns the parent of a node.)
//!

#ifndef BINARY_SEARCH_TREE_SUCC_HPP
#define BINARY_SEARCH_TREE_SUCC_HPP

#include "node.hpp"
#include <memory>

namespace ch12 {

/**
 * @brief binary_search_tree_succ
 *
 * for ex12.3-5, using node with successor
 */
template<typename K, typename D>
class binary_search_tree_succ
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using Node      =   node<K,D>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;

private:
    sPointer root;


};

}//namespace ch12

#endif // BINARY_SEARCH_TREE_SUCC_HPP
