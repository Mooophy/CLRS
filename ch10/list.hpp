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

/**
 * @brief doubly linked list without sentinel
 */
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

    /**
     * @brief operator []
     */
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
     * @brief operator +
     *
     * @complexity O(1)
     *
     * append the rhs to this list, implemented for ex10.2-6.
     */
    double_list<ValueType>& operator + (double_list<ValueType>& rhs)
    {
        if(rhs.empty())
            return *this;
        else
        {
            if(this->empty())
                return rhs;
            else    //neither is empty
            {
                sPointer tail   =   this->tail();

                tail->next      =   rhs.head;
                rhs.head->prev  =   tail;

                return *this;
            }
        }
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

        if(!empty())
            head->prev  = inserted;

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
     * @complexity  O(1)
     *
     * a const ref to head
     */
    const sPointer& begin() const
    {
        return head;
    }

    /**
     * @brief empty
     */
    bool empty()const
    {
        return head == nullptr;
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
    sPointer head   =   nullptr;

    /**
     * @brief return tail
     *
     * @complexity  O(n)
     */
    sPointer tail() const
    {
        if(empty())
            return head;
        else
        {
            sPointer ret = head;
            while(ret->next != nullptr)
                ret = ret->next;

            return ret;
        }
    }

};//class double_list

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

//!
//! ex10.2-6
//! The dynamic-set operation UNION takes two disjoint sets S1 and S2 as input, and
//! it returns a set S = S1 U S2 consisting of all the elements of S 1 and S 2 . The
//! sets S1 and S2 are usually destroyed by the operation. Show how to support UNION
//! in O(1) time using a suitable list data structure.
//!
//! test code:
//!
//#include <iostream>
//#include "list.hpp"

//int main()
//{
//    ch10::list::double_list<int> s1,s2, uni;

//    for(int i = 0; i !=10 ; ++i)
//    {
//        s1.insert(i);
//        s2.insert(i*10);
//    }

//    uni = s1 + s2;

//    std::cout << s1.empty() << std::endl;
//    std::cout << s2 << std::endl;

//    std::cout << "uni =\n" << uni << std::endl;
//}

