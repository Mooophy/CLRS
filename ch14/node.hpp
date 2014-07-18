/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       17  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <iostream>
#include <assert.h>
#include "debug.hpp"

namespace ch14 {
/**
 * @brief The Color enum
 *
 * for red black tree
 */
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

    Node(){}

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

    /**
     * @brief is_left
     *
     * Since no parent can be used for persistent trees, this metod can not
     * used directly
     */
    bool is_left() const
    {
        assert(parent.lock());
        return this == parent.lock()->left.get();
    }

    /**
     * @brief is_right
     *
     * Since no parent can be used for persistent trees, this metod can not
     * used directly
     */
    bool is_right() const
    {
        assert(parent.lock());
        return this == parent.lock()->right.get();
    }

    /**
     * @brief print
     */
    virtual void print()const
    {
        std::cout << "key= " + debug::green(std::to_string(key)) + " ";
        std::cout << (color == Color::RED?   debug::red("red  ")   :   "blk  ");
        std::cout << "parent=" << parent.lock();
        std::cout << debug::green(" self=") << this << " left=" << left << " right=" << right ;
    }

protected:
    KeyType     key;
    sPointer    left;
    sPointer    right;
    wPointer    parent;
    Color       color = Color::BLACK;
    DataType    data;
};


/**
 * @brief The NodeSz class
 *
 * node template with a size attribute
 *
 * inherited from Node.
 */
template<typename K, typename D>
class NodeSz: public Node<K,D>
{
public:
    using SizeType  =   std::size_t;
    using B         =   Node<K,D>;
    using KeyType   =   typename B::KeyType;
    using DataType  =   typename B::DataType;

    NodeSz():
        B(),size(0)
    {}

    /**
     * @brief NodeSz
     * @param key
     * @param sz
     */
    explicit NodeSz(const KeyType &key, SizeType sz = 0):
        B(key), size(sz)
    {}

    /**
     * @brief NodeSz
     * @param key
     * @param data
     * @param sz
     */
    NodeSz(const KeyType& key, const DataType& data, SizeType sz = 0):
        B(key, data), size(sz)
    {}

    /**
     * @brief print
     */
    virtual void print() const
    {
        B::print();
        std::cout << debug::green(" size=")
                  << size << " ";
    }

protected:
    SizeType    size;

};
}//namespace

#endif // NODE_HPP
