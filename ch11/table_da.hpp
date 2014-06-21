/***************************************************************************
 *  @file       table_da.hpp
 *  @author     Alan.W
 *  @date       21  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/

//! pseudo code
//  DIRECT-ADDRESS-SEARCH(T,k)
//1 return T[k]

//  DIRECT-ADDRESS-INSERT(T,x)
//1 T[x.key] = x

//  DIRECT-ADDRESS-DELETE(T,x)
//1 T[x.key] = n

#ifndef TABLE_DA_HPP
#define TABLE_DA_HPP

#include "node.hpp"
#include <vector>

namespace ch11{

/**
 * @brief direct address table
 */
template<typename K, typename D>
class table_da
{
public:
    using SizeType  =   K;
    using KeyType   =   K;
    using DataType  =   D;
    using Node      =   node<K,D>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;
    using Container =   std::vector<sPointer>;

    table_da()  =   delete;

    /**
     * @brief Ctor
     */
    table_da(SizeType sz):
        container(sz)
    {}

    /**
     * @brief search
     *
     * @complexity  O(1)
     */
    DataType& search(const KeyType& key)
    {
        return container[key]->data;
    }

    /**
     * @brief insert
     *
     * @complexity  O(1)
     */
    void insert(const KeyType& key, const DataType& data)
    {
        container[key]  =   std::make_shared<Node>(key,data);
    }

    /**
     * @brief remove
     *
     * @complexity  O(1)
     */
    void remove(const KeyType& key)
    {
        container[key]  =   nullptr;
    }
private:
    Container container;
};


}//namespace
#endif // TABLE_DA_HPP

//! test code
//#include <iostream>
//#include <node.hpp>
//#include "table_da.hpp"

//int main()
//{
//    ch11::table_da<int, int> table(10);

//    table.insert(7,33);
//    table.insert(6,42);

//    std::cout << table.search(7) << std::endl;

//    return 0;
//}
