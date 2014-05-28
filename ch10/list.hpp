/***************************************************************************
 *  @file       list.hpp
 *  @author     Alan.W
 *  @date       28  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <memory>

namespace ch10{
namespace list{

/**
 * @brief The node struct
 *
 * @attention next : shared_ptr
 *            prev : weak_ptr
 */
template<typename T>
struct node
{
    using ValueType = T;
    using sPointer  = std::shared_ptr<node<ValueType>>;
    using wPointer  = std::weak_ptr<node<ValueType>>;

    /**
     * @brief ctor
     */
    explicit node(const ValueType& val):
        key(val), prev(), next(nullptr)
    {}

    ValueType   key;
    wPointer    prev;
    sPointer    next;
};

template<typename T>
class double_list
{
public:
    using ValueType = T;
    using Node      = node<ValueType>;
    using sPointer  = std::shared_ptr<node<ValueType>>;

    double_list() = default;

    /**
     * @brief insert
     *
     * @complexity O(1)
     *
     * based on LIST-INSERT ,page 238.
     */
    void insert(const ValueType& val)
    {
        sPointer p = std::make_shared<Node>(val);
        if(data != nullptr)
            data->prev = p;
        data = p;
    }

private:    
    sPointer data = nullptr;
};


}//namespace list
}//namespace ch10

#endif // LIST_H
