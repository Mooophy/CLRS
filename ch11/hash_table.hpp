/***************************************************************************
 *  @file       hash_table.hpp
 *  @author     Alan.W
 *  @date       21  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include <vector>
#include "node.hpp"

namespace ch11 {

template<typename K, typename D>
class hash_table
{
public:
    using SizeType  =   K;
    using KeyType   =   K;
    using DataType  =   D;
    using Node      =   node<K,D>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;
    using Hash      =   std::function<K(K)>;
    using Container =   std::vector<sPointer>;

    hash_table()    =   delete;

    /**
     * @brief Ctor
     */
    hash_table(const SizeType& sz, const Hash& h):
        hash(h), container(sz)
    {}

private:
    Hash        hash;
    Container   container;

};

}//namespace
#endif // HASH_TABLE_HPP
