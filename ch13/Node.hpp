/***************************************************************************
 *  @file       binary_search_tree_succ.hpp
 *  @author     Yue Wang
 *  @date       02  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP


#include <memory>
#include <iostream>

namespace ch13 {

/**
 * @brief Color enum
 */
enum class Color
{
    Black   =   0,
    Red     =   1
};

/**
 * @brief node
 *
 * used for red black tree.
 */
template<typename K, typename D>
struct Node
{
    using KeyType   =   K;
    using DataType  =   D;
    using sPointer  =   std::shared_ptr<Node<K,D> >;
    using wPointer  =   std::weak_ptr<Node<K,D> >;

    /**
     * @brief default ctor
     */
    Node() = default;

    /**
     * @brief Node
     * @param key
     * @param color
     */
    explicit Node(const KeyType& key, Color c = Color::Black):
        data(), key(key), parent(), left(), right(), color(c)
    {}

    /**
     * @brief Node
     * @param key
     * @param data
     * @param color
     */
    Node(const KeyType& key, const DataType& data, Color c = Color::Black):
        data(data), key(key), parent(), left(), right(), color(c)
    {}

    /**
     * @brief print
     */
    void print() const
    {
        std::cout   << "key = "     <<  key
                    << "  data = "  <<  data
                    << "  color = " << (color == Color::Black?  "Black" :   "Red")
                    << std::endl;
    }

    /**
     * @brief data  member
     */
    DataType    data;
    KeyType     key = 0;
    wPointer    parent;
    sPointer    left;
    sPointer    right;
    Color       color = Color::Black;
};




}//namespace ch12

#endif // NODE_HPP
