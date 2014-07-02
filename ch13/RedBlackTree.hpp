/***************************************************************************
 *  @file       RedBlackTree.hpp
 *  @author     Yue Wang
 *  @date       02  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.hpp"

namespace ch13{

template<typename K, typename D>
class RedBlackTree
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using sPointer  =   std::shared_ptr<Node<K,D> >;
    using wPointer  =   std::weak_ptr<Node<K,D> >;

private:
    sPointer root;
};

}//namespace ch13
#endif // REDBLACKTREE_H
