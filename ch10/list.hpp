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
    using Pointer   = std::shared_ptr<node>;

    ValueType   key;
    Pointer     next;
};

}//namespace list
}//namespace ch10

#endif // LIST_H
