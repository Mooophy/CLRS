/***************************************************************************
 *  @file       node.hpp
 *  @author     alan.w
 *  @date       15  August 2014
 *  @remark     CLRS implementation, using C++ templates.
 ***************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
#include <memory>
#include "color.hpp"

namespace ch15 { namespace sec5 {

template<typename K, typename V>
class NodeBase;

template<typename K, typename V>
std::ostream&
operator <<(std::ostream& os, const NodeBase<K,V>& node);

/**
 * @brief The NodeBase class
 */
template<typename K, typename V>
class NodeBase
{
    friend std::ostream&
    operator << <K,V>(std::ostream& os, const NodeBase<K,V>& node);
public:
    using KeyType   =   K;
    using ValueType =   V;
    using sPointer  =   std::shared_ptr<NodeBase>;
    using wPointer  =   std::weak_ptr<NodeBase>;

    //! Ctors
    NodeBase() = default;
    NodeBase(const KeyType& key, const ValueType& val):
        key(key),
        value(val)
    {}

protected:
    KeyType key;
    ValueType value;
    sPointer left;
    sPointer right;
    wPointer parent;
};




}}//namespace
#endif // NODE_HPP
