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
 * used for singly linked list
 */
template<typename T>
struct node
{
    using ValueType = T;
    using Pointer   = std::shared_ptr<node<ValueType>>;

    ValueType   key;
    Pointer     next = nullptr;
};

template<typename T>
class single_list
{
public:
    using ValueType = T;
    using Pointer   = std::shared_ptr<node<ValueType>>;
    using SizeType  = std::size_t;

    single_list():
        head(nullptr)
    {}

    void push_back()
    {

    }

    Pointer end()
    {
        if(head == nullptr)
            return nullptr;
        else
        {
            Pointer p = head;
            while(p->next != nullptr)
                p = p->next;
            return p;
        }
    }

    Pointer begin()
    {
        return head;
    }


private:
    Pointer head;
};

}//namespace list
}//namespace ch10

#endif // LIST_H
