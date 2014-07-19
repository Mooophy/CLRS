/***************************************************************************
 *  @file       red_black_tree.hpp
 *  @author     Alan.W
 *  @date       18  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/

#ifndef ORDER_STATISTIC_TREE_HPP
#define ORDER_STATISTIC_TREE_HPP

#include "red_black_tree.hpp"

namespace ch14 {

template<typename K, typename D>
class OrderStatisticTree : public RedBlackTree<K,D>
{
public:
    using B         =               ch14::RedBlackTree<K,D>;
    using KeyType   =   typename    B::KeyType;
    using DataType  =   typename    B::DataType;
    using szNode    =               ch14::NodeSz<K,D>;
    using sPointer  =   typename    B::sPointer;


    OrderStatisticTree():
        B()
    {}

    virtual void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<szNode>(key);
        insert(added);
    }

    virtual void insert(const KeyType &key, const DataType& data)
    {
        sPointer added = std::make_shared<szNode>(key, data);
        insert(added);
    }

    virtual ~OrderStatisticTree(){  }
protected:

    virtual void insert(sPointer added)
    {
        B::insert(added);
        //todo
        //insert fixup
    }

    virtual void insert_fixup(sPointer added)
    {
        std::cout << debug::red("not implemented yet!!") << std::endl;
    }

};


}//namespace




#endif // ORDER_STATISTIC_TREE_HPP
