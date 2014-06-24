/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       23  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <iostream>

namespace ch12 {

/**
 * @brief node
 *
 * used for binary tree.
 */
template<typename K, typename D>
struct node
{
    using KeyType   =   K;
    using DataType  =   D;
    using Node      =   node<K,D>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;

    /**
     * @brief default ctor
     */
    node() = default;

    /**
     * @brief ctor
     */
    node(const KeyType& key, const DataType& data):
        data(data), key(key), parent(), left(), right()
    {}

    /**
     * @brief print
     */
    void print() const
    {
        std::cout   << "key = "   <<  key
                    << "  data = "<<  data
                    << std::endl;
    }

    DataType    data;
    KeyType     key;
    wPointer    parent;
    sPointer    left;
    sPointer    right;
};

}//namespace ch12

#endif // NODE_HPP
