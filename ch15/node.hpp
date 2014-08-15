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
class Node;

template<typename K, typename V>
std::ostream&
operator <<(std::ostream& os, const Node<K,V>& node);

/**
 * @brief The NodeBase class
 */
template<typename K, typename V>
class Node
{
    friend std::ostream&
    operator << <K,V>(std::ostream& os, const Node<K,V>& node);
public:
    using KeyType   =   K;
    using ValueType =   V;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;

    //! Ctors
    Node() = default;
    Node(const KeyType& key, const ValueType& val):
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

template<typename K, typename V>
std::ostream&
operator <<(std::ostream& os, const Node<K, V> &node)
{
    os << color::yellow("key = "    +   node.key) << " "
       << color::green("value = "   +   node.value) << std::endl;

    return os;
}


}}//namespace
#endif // NODE_HPP
