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

template<typename K, typename V>
using sPointer  =   std::shared_ptr<Node<K,V>>;

template<typename K, typename V>
using wPointer  =   std::weak_ptr<Node<K,V>>;

/**
 * @brief The Node class
 */
template<typename K, typename V>
class Node
{
    friend std::ostream&
    operator << <K,V>(std::ostream& os, const Node<K,V>& node);
public:
    using KeyType   =   K;
    using ValueType =   V;
    using sPointer  =   ch15::sec5::sPointer<K,V>;
    using wPointer  =   ch15::sec5::wPointer<K,V>;

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

/**
 * @brief operator <<
 * @param os
 * @param node
 */
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

//! @test   Node and opertor <<
//#include <iostream>
//#include <vector>
//#include <memory>
//#include "color.hpp"
//#include "node.hpp"

//int main()
//{
//    using NodeType  =   ch15::sec5::Node<std::string,std::string>;
//    using sPointer  =   ch15::sec5::sPointer<std::string,std::string>;

//    sPointer node(new NodeType("eng","fre"));
//    std::cout << *node << std::endl;

//    std::cout << color::red("\nend\n");
//    return 0;
//}
