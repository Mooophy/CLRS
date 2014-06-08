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

/*      union(lhs, rhs)
 * 1    if rhs.empty
 * 2        return lhs
 * 3    else if lhs.empty
 * 4        return rhs
 * 5    else
 *          def ret
 * 6        ret.insert (lhs.head->key)
 * 7        def l = lhs.head->next
 * 8        def r = rhs.head
 * 9        def current = ret.head
 * 10       while(l && r)
 * 11           if(l->key == r->key)
 * 12               current->next = new (l->key)
 * 13               l = l->next
 * 14               r = r->next
 * 15           else if(l->key < r->key)
 * 16               current->next = new (l->key)
 * 17               l = l->next
 * 18           else
 *                  current->next = new (r->key)
 * 19               r = r->next
 * 20           current = current->next
 * 21       while(!l && r)
 * 22           current->next = new (r->key)
 * 23           r = r->next
 * 24           current = current->next
 * 25       while(l && !r)
 * 26           current->next = new (l->key)
 * 27           l = l->next
 * 28           current = current->next
 * 29       return ret
 */

//!
//!
//!     b. Lists are unsorted.
//!     c. Lists are unsorted, and dynamic sets to be merged are disjoint.
//!

#ifndef MERGEABLE_HEAP_HPP
#define MERGEABLE_HEAP_HPP

#include "list.hpp"
#include <memory>

namespace ch10 {

template<typename T>
class mergeable_heap_SL;

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

    mergeable_heap_SL() = default;

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
        ValueType min = head->key;
        head = head->next;
        return min;
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
     * @brief empty
     */
    bool empty() const
    {
        return head == nullptr;
    }

    void print()const
    {
        sPointer current = head;
        while(current)
        {
            std::cout << current->key << std::endl;
            current = current->next;
        }
    }

    /**
     * @brief insert
     *
     * @complexity  O(n)
     */
    void insert(const ValueType& val)
    {
        if(!search(val))    //eliminate duplicates
        {
            sPointer new_node = std::make_shared<Node>(val);

            if(empty())
                head = new_node;
            else
            {
                //! find the first node nonless than val
                sPointer succ = head;
                sPointer prev = nullptr;
                while(succ && succ->key < val)
                {
                    prev = succ;
                    succ = succ->next;
                }

                //! insert new_node
                if(!prev)
                {
                    new_node->next  =   head;
                    head            =   new_node;
                }
                else if(succ)
                {
                    new_node->next  =   succ;
                    prev->next      =   new_node;
                }
                else
                    prev->next      =   new_node;
            }
        }
    }

private:
    sPointer head = nullptr;
};




}//namespace ch10


#endif // MERGEABLE_HEAP_HPP
