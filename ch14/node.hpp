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

template<typename K, typename D>
class Node;

template<typename K, typename D>
class RedBlackTree;

template<typename K, typename D>
class OrderStatisticTree;



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
    friend class RedBlackTree<K,D>;
    friend class OrderStatisticTree<K,D>;

public:
    using KeyType   =   K;
    using DataType  =   D;
    using SizeType  =   std::size_t;
    using NodeType  =   Node<K,D>;
    using sPointer  =   std::shared_ptr<NodeType>;
    using wPointer  =   std::weak_ptr<NodeType>;

    Node(){}

    /**
     * @brief Node
     * @param key
     */
    explicit Node(const KeyType& key):
        key(key),left(),right(), parent(), color(Color::BLACK),data(),size(0)
    {}

    /**
     * @brief Node
     * @param key
     * @param data
     */
    Node(const KeyType &key, const DataType& data):
        key(key),left(),right(), parent(), color(Color::BLACK),data(data),size(0)
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
     * @brief return the rank within the subtree rooted at this node.
     *
     * @complx  O(1)
     *
     * implemented for Order Statistic Tree
     */
    SizeType rank() const
    {
        return this->left?  this->left->size + 1    :   0;
    }

    /**
     * @brief print
     */
    void print()const
    {
        std::cout << "key= " + debug::green(std::to_string(key)) + " ";
        std::cout << (color == Color::RED?   debug::red("red ")   :   "blk ");
        std::cout << "parent=" << parent.lock();
        std::cout << debug::green(" self=") << this
                  << " left="   << left
                  << " right="  << right


                  << debug::green(" size=")  << size
                  << std::endl;
    }

protected:
    KeyType     key;
    sPointer    left;
    sPointer    right;
    wPointer    parent;
    Color       color = Color::BLACK;
    DataType    data;
    SizeType    size;
};



}//namespace

#endif // NODE_HPP
