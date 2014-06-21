/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       21  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include <memory>

namespace ch11{


/**
 * @brief The node struct
 */
template<typename K, typename D>
struct node
{
    using KeyType   =   K;
    using DataType  =   D;
    using sPointer  =   std::shared_ptr<node<K, D>>;
    using wPointer  =   std::weak_ptr<node<K, D>>;

    /**
     * @brief ctor
     */
    explicit node(const KeyType& k, const DataType d):
        key(k), data(d), prev(), next(nullptr)
    {}

    /**
     * @brief members
     */
    KeyType     key;
    DataType    data;
    wPointer    prev;
    sPointer    next;
};

}//namespace
#endif // NODE_HPP
