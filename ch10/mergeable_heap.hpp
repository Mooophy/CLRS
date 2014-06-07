/***************************************************************************
 *  @file       queue_by_2stacks.hpp
 *  @author     Alan.W
 *  @date       6   Jun 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! Problem 10-2 Mergeable heaps using linked lists
//! A mergeable heap supports the following operations: MAKE-HEAP (which creates
//! an empty mergeable heap), INSERT , MINIMUM , EXTRACT-MIN , and UNION
//! Show how to implement mergeable heaps using linked lists in each of the following
//! cases. Try to make each operation as efficient as possible. Analyze the running
//! time of each operation in terms of the size of the dynamic set(s) being operated on.
//!     a. Lists are sorted.
//          MAKE-HEAP       O(1)            the default ctor
//          INSERT          O(2n) = O(n)    eliminating duplicats takes one more O(n)
//          MINIMUM         O(1)
//          EXTRACT-MIN     O(1)
//          UNION           O(n)
//!
//!     b. Lists are unsorted.
//!     c. Lists are unsorted, and dynamic sets to be merged are disjoint.
//!

#ifndef MERGEABLE_HEAP_HPP
#define MERGEABLE_HEAP_HPP

#include "list.hpp"
#include <memory>

namespace ch10 {

/**
 * @brief mergeable heap implemented by sorted list
 *
 * for Problem 10-2
 */
template<typename T>
class mergeable_heap_SL
{
public:
    using ValueType = T;
    using Node      = ch10::list::node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;
    using wPointer  = std::weak_ptr<Node>;
    using SizeType  = std::size_t;

    /**
     * @brief default ctor
     */
    mergeable_heap_SL() = default;

    /**
     * @brief empty
     */
    bool empty() const
    {
        return head == nullptr;
    }

    /**
     * @brief minimum
     *
     * @complexity  O(1)
     */
    sPointer minimum() const
    {
        return head;
    }

    /**
     * @brief extract_min
     *
     * @complexity  O(1)
     */
    ValueType extract_min()
    {
        assert(!empty());
        ValueType ret = head->key;
        head = head->next;

        return ret;
    }

    void operator+(const mergeable_heap_SL<T>& lhs)
    {

    }

    /**
     * @brief search
     *
     * @complexity O(n)
     */
    sPointer search(const ValueType& val) const
    {
        sPointer ret = head;
        while(ret && ret->key != val)
            ret = ret->next;

        return ret;
    }

    /**
     * @brief insert
     *
     * @complexity  O(2n) = O(n)
     *
     * for problem 10-2.a
     * This one is just the interface, insert_node method does the
     * real work.
     */
    void insert(const ValueType& val)
    {
        if(!search(val))    //eliminate duplicates
        {
            sPointer new_node = std::make_shared<Node>(val);

            if(empty())
                head = tail = new_node;
            else
                insert_node(new_node);
        }
    }

    /**
     * @brief print
     *
     * @complexity  O(n)
     */
    void print() const
    {
        sPointer current = head;
        while(current)
        {
            std::cout << current->key << std::endl;
            current = current->next;
        }
    }
private:
    sPointer head = nullptr;
    sPointer tail = nullptr;

    /**
     * @brief insert_node
     *
     * @complexity  O(n)
     *
     * actual implementation for insert method, maintaining increasing order
     */
    void insert_node(sPointer& new_node, sPointer position = nullptr)
    {
        //! if no node specified, use the first node that nonless than new_node
        if(!position)
            position = find_first_nonless_than(new_node);

        if(position)
        {
            //! maintain the head pointer
            if(position == head)
                head = new_node;

            //! manage new_node
            new_node->next  = position;
            new_node->prev  = position->prev.lock();

            //! manage the first less than node
            if(position->prev.lock())
                position->prev.lock()->next = new_node;
            position->prev  = new_node;
        }
        else
        {
            //! manage the tail pointer
            tail->next      = new_node;
            new_node->prev  = tail;
            tail            = new_node;
        }
    }

    /**
     * @brief return the first node nonless than argument or nullptr
     *
     * @complextiy  O(n)
     */
    sPointer find_first_nonless_than(sPointer& node) const
    {
        sPointer current = head;
        while(current && current->key < node->key)
            current = current->next;
        return current;
    }
};

}//namespace ch10


#endif // MERGEABLE_HEAP_HPP
