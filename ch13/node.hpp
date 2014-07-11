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
#include <assert.h>
#include "debug.hpp"

namespace ch13 {


template<typename K, typename D>
class RedBlackTree;

template<typename K, typename D>
class PersistentTree;

template<typename K,typename D>
class RedBlackTreeNoParent;

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
    friend class RedBlackTree<K,D>;
    friend class PersistentTree<K,D>;
    friend class RedBlackTreeNoParent<K,D>;
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

    /**
     * @brief is_left
     */
    bool is_left() const
    {
        assert(parent.lock());
        return this == parent.lock()->left.get();
    }

    /**
     * @brief is_right
     */
    bool is_right() const
    {
        assert(parent.lock());
        return this == parent.lock()->right.get();
    }


    /**
     * @brief print
     */
    void print()const
    {
        std::cout << "key= " + debug::green(std::to_string(key)) + " ";
        std::cout << (color == Color::RED?   debug::red("red  ")   :   "blk  ");
        std::cout << "parent=" << parent.lock();
        std::cout << debug::green(" self=") << this << " left=" << left << " right=" << right ;


        std::cout << std::endl ;
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
