/***************************************************************************
 *  @file       hash_table.hpp
 *  @author     Alan.W
 *  @date       21  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include "node.hpp"

namespace ch11 {

template<typename K, typename D>
class hash_table
{
public:
    using SizeType  =   K;
    using KeyType   =   K;
    using DataType  =   D;
    using sPointer  =   std::shared_ptr<node<K, D>>;
    using wPointer  =   std::weak_ptr<node<K, D>>;
    using Hash      =   std::function<K(K)>;

    hash_table()    =   delete;

    /**
     * @brief Ctor
     */
    hash_table(const SizeType& sz, const Hash& h):
        hash(h), rows(sz)
    {}

private:
    SizeType    rows;
    Hash        hash;


};

}//namespace
#endif // HASH_TABLE_HPP
