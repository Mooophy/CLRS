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
     * @brief Ctor
     * @param key
     */
    explicit node(const KeyType& key):
        data(), key(key), parent(), left(), right()
    {}

    /**
     * @brief Ctor
     * @param key
     * @param data
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

    /**
     * @brief data  member
     */
    DataType    data;
    KeyType     key;
    wPointer    parent;
    sPointer    left;
    sPointer    right;
};

/**
 * @brief node with successor
 *
 * inherited from ch12::node, implemented for ex12.3-5
 */
template<typename K,typename D>
struct nodeSucc   : public  node<K,D>
{
    using KeyType   =   K;
    using DataType  =   D;
    using wPointer  =   typename node<K,D>::wPointer;
            //! @attention  :    ^^^^^^^^^^^^^^^^^^^
            //!                 pointer to base class

    /**
     * @brief default Ctor
     */
    nodeSucc() = default;

    /**
     * @brief Ctor
     * @param key
     */
    nodeSucc(const KeyType& key):
        node<KeyType,DataType>(key), successor()
    {}

    /**
     * @brief Ctor
     * @param key
     * @param data
     */
    nodeSucc(const KeyType& key, const DataType& data):
        node<KeyType,DataType>(key,data),successor()
    {}

    /**
     * @brief data  member
     */
    wPointer    successor;
};


}//namespace ch12



#endif // NODE_HPP

//! test code for node
//#include <iostream>
//#include <string>
//#include "node.hpp"

//int main()
//{
//    ch12::node<int, std::string> node(1,"hello world");
//    node.print();

//    return 0;
//}

//! code for testing nodeSucc
//#include <iostream>
//#include <string>
//#include "node.hpp"

//int main()
//{
//    std::shared_ptr<ch12::nodeSucc<int,std::string> > p =
//           std::make_shared<ch12::nodeSucc<int,std::string>>(42,"042");

//    p->successor = p;

//    std::cout << (p->successor.lock()->data) << std::endl;


//    return 0;
//}
