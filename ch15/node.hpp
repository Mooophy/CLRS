/***************************************************************************
 *  @file       longest_mono_increasing_subseq.hpp
 *  @author     alan.w
 *  @date       15  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
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

    //! Ctos
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

/**
 * @brief The Node class
 */
class Node : public NodeBase<std::string, std::string>
{
public:
    using B = NodeBase<std::string,std::string>;

    Node(const std::string& key, const std::string& val):
        B::NodeBase(key,val)
    {}

    ~Node(){}
};

/**
 * @brief The Dummy class
 */
class Dummy : public NodeBase<std::string, std::string>
{
public:
    using B = NodeBase<std::string,std::string>;

    Dummy():
        B::NodeBase("NA", "NA")
    {}
};

/**
 * @brief operator <<
 * @param os
 * @param node
 */
template<typename K, typename V>
inline std::ostream&
operator <<(std::ostream& os, const NodeBase<K,V>& node)
{
    os << color::yellow("key = "    +   node.key) << " "
       << color::green("value = "   +   node.value) << "\n";

    return os;
}


}}//namespace
#endif // NODE_HPP

//! @test
//!
//#include <iostream>
//#include <vector>
//#include <memory>
//#include "color.hpp"
//#include "node.hpp"

//int main()
//{
//    using NodeType  =   ch15::sec5::NodeBase<std::string, std::string>;
//    using sPointer  =   std::shared_ptr<NodeType>;

//    sPointer node   =   std::make_shared<ch15::sec5::Node>("ss","zz");
//    sPointer dummy  =   std::make_shared<ch15::sec5::Dummy>();

//    std::cout << *node  << std::endl;
//    std::cout << *dummy << std::endl;

//    std::cout << color::red("\nend\n");
//    return 0;
//}
//! @output:
//!
//key = ss value = zz

//key = NA value = NA


//end
