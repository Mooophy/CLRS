/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       26  June 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <iostream>
#include "debug.hpp"

namespace ch13 {

enum class Color
{
    RED,
    BLACK
};

/**
 * @brief Node
 *
 * used for Red Black Trees.
 */
template<typename K, typename D>
class Node
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using NodeType  =   Node<K,D>;
    using sPointer  =   std::shared_ptr<NodeType>;
    using wPointer  =   std::weak_ptr<NodeType>;

    Node() = default;

    /**
     * @brief Node
     * @param key
     */
    explicit Node(const KeyType& key):
        key(key),left(),right(), parent(), color(Color::BLACK),data()
    {}

    /**
     * @brief Node
     * @param key
     * @param data
     */
    Node(const KeyType &key, const DataType& data):
        key(key),left(),right(), parent(), color(Color::BLACK),data(data)
    {}

    void print()const
    {
    }
private:
    KeyType     key;
    sPointer    left;
    sPointer    right;
    wPointer    parent;
    Color       color = Color::BLACK;
    DataType    data;


};


}//namespace
#endif // NODE_HPP
