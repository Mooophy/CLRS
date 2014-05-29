/***************************************************************************
 *  @file       circular_list.hpp
 *  @author     Alan.W
 *  @date       29  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <memory>
#include <iostream>
#include <assert.h>

namespace ch10{
namespace list{

template<typename T>
struct node;

template<typename T>
class double_list;

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
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;
    using SizeType  = std::size_t;

    double_list() = default;

    ValueType& operator[](SizeType index) const
    {
        assert(index < size());

        SizeType count = 0;
        sPointer ptr = head;
        while(count++ != index)
            ptr = ptr->next;

        return ptr->key;
    }

    /**
     * @brief insert
     *
     * @complexity O(1)
     *
     * based on LIST-INSERT, page 238.
     */
    void insert(const ValueType& val)
    {
        sPointer inserted = std::make_shared<Node>(val);

        inserted->next = head;
        if(head != nullptr)
            head->prev = inserted;
        head = inserted;
    }

    /**
     * @brief size
     *
     * @complexity  O(size)
     */
    SizeType size() const
    {
        SizeType size = 0;
        sPointer ptr = head;
        while(ptr != nullptr)
        {
            ++size;
            ptr = ptr->next;
        }
        return size;
    }

    /**
     * @brief search
     *
     * @param key
     *
     * @complexity  O(1)
     */
    sPointer search(const ValueType& key) const
    {
        sPointer ret = head;
        while(ret != nullptr && ret->key != key)
            ret = ret->next;
        return ret;
    }

    /**
     * @brief begin
     *
     * a const ref to head
     */
    const sPointer& begin() const
    {
        return head;
    }

    /**
     * @brief remove
     *
     * @param target    a shared_ptr pointing to a node on the list
     *
     * @complexity  O(1)
     *
     * based on LIST-DELETE page 238.
     */
    void remove(sPointer target)
    {
        assert(target != nullptr);

        if(target->prev.lock() != nullptr)
            target->prev.lock()->next = target->next;
        else
            head = target->next;

        if(target->next != nullptr)
            target->next->prev = target->prev;
    }

private:    
    sPointer head = nullptr;
};

/**
 * @brief operator <<
 */
template<typename T>
inline std::ostream& operator <<(std::ostream& os, const double_list<T>& l)
{
    using sPointer = typename ch10::list::double_list<T>::sPointer;

    sPointer ptr = l.begin();
    while(ptr != nullptr)
    {
        os << ptr->key << std::endl;
        ptr = ptr->next;
    }
    return os;
}

}//namespace list
}//namespace ch10

#endif // LIST_H
