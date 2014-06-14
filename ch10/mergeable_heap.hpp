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
//!     b. Lists are unsorted.
//          MAKE-HEAP       O(1)            the default ctor
//          INSERT          O(n)            eliminating duplicats takes O(n)
//          MINIMUM         O(n)
//!     c. Lists are unsorted, and dynamic sets to be merged are disjoint.
//!

#ifndef MERGEABLE_HEAP_HPP
#define MERGEABLE_HEAP_HPP

#include "list.hpp"
#include <memory>

namespace ch10 {

template<typename T>
class mergeable_heap_SL;

template<typename T>
class mergeable_heap_UL;

template<typename T>
mergeable_heap_SL<T>
operator+(const mergeable_heap_SL<T>&, const mergeable_heap_SL<T>&);

/**
 * @brief mergeable heap implemented by sorted list
 *
 * for Problem 10-2.a
 */
template<typename T>
class mergeable_heap_SL
{
    friend mergeable_heap_SL<T>
    operator+<T>(const mergeable_heap_SL<T>&, const mergeable_heap_SL<T>&);
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
     * @return the sPointer to the node whose key equal to val ,or nullptr.
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

    /**
     * @brief print
     */
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


/**
 * @brief mergeable heap implemented by sorted list
 *
 * for Problem 10-2.b
 */
template<typename T>
class mergeable_heap_UL
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
    mergeable_heap_UL() = default;

    /**
     * @brief search
     *
     * @return the sPointer to the node whose key equal to val ,or nullptr.
     *
     * @complexity O(n)
     */
    sPointer search(const ValueType& val) const
    {
        sPointer curr = head;
        while(curr && curr->key != val)
            curr = curr->next;

        return curr;
    }

    /**
     * @brief insert
     *
     * @complexity  O(n)
     *              used for dupicates searching.
     */
    void insert(const ValueType& val)
    {
        if(!search(val))
        {
            sPointer new_node = std::make_shared<Node>(val);
            new_node->next  =   head;
            head            =   new_node;
        }
    }

    /**
     * @brief print
     */
    void print() const
    {
        sPointer curr = head;
        while(curr)
        {
            std::cout << curr->key << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

    /**
     * @brief minimum
     *
     * @return an sPointer to the node whose key is the smallest one
     *
     * @complexity  O(n)
     */
    sPointer minimum() const
    {
        sPointer min, curr;
        min = curr = head;
        while(curr)
        {
            if(curr->key < min->key)
                min = curr;
            curr = curr->next;
        }
        return min;
    }

    /**
     * @brief extract_min
     *
     * @complexity  O(n)
     */
    ValueType extract_min()
    {
        assert(head);
        sPointer prev, prev_min;

        sPointer curr, min;
        curr = min = head;

        if(head->next)
        {
            //! seach the node with minimum key and its predecessor
            while(curr)
            {
                if(curr->key < min->key)
                {
                    min = curr;
                    prev_min = prev;
                }
                prev = curr;
                curr = curr->next;
            }
            //! delete the minimum node
            prev_min->next = min->next;
        }
        else
            head = nullptr;

        return min->key;
    }


private:
    sPointer head = nullptr;
};




/**
 * @brief operator +    i.e. UNION
 *
 * @complexity  O(n)
 */
template<typename T>
inline mergeable_heap_SL<T>
operator+(const mergeable_heap_SL<T>& lhs, const mergeable_heap_SL<T>& rhs)
{
    using sPointer  =   typename ch10::mergeable_heap_SL<T>::sPointer;
    using Node      =   typename ch10::mergeable_heap_SL<T>::Node;

    if(rhs.empty())         return lhs;
    else if (lhs.empty())   return rhs;
    else
    {
        mergeable_heap_SL<T> ret;
        ret.insert(lhs.head->key);
        sPointer l          = lhs.head->next;
        sPointer r          = rhs.head;
        sPointer current    = ret.head;

        while(l && r)   //when neither exhausted
        {
            if(l->key == r->key)
            {
                current->next = std::make_shared<Node>(l->key);
                l = l->next;
                r = r->next;
            }
            else if(l->key < r->key)
            {
                current->next = std::make_shared<Node>(l->key);
                l = l->next;
            }
            else
            {
                current->next = std::make_shared<Node>(r->key);
                r = r->next;
            }
            current = current->next;
        }
        while(!l && r)  //when l exhausted
        {
            current->next = std::make_shared<Node>(r->key);
            r = r->next;
            current = current->next;
        }
        while(l && !r)  //when r exhausted
        {
            current->next = std::make_shared<Node>(l->key);
            l = l->next;
            current = current->next;
        }
        return ret;
    }
}

}//namespace ch10
#endif // MERGEABLE_HEAP_HPP


//! test code for problem 10-2.a
//#include <iostream>
//#include "mergeable_heap.hpp"
//int main()
//{
//    ch10::mergeable_heap_SL<int> lhs, rhs;

//    lhs.insert(10);
//    lhs.insert(11);
//    lhs.insert(11);
//    lhs.insert(1);

//    rhs.insert(2);
//    rhs.insert(3);
//    rhs.insert(6);

//    ch10::mergeable_heap_SL<int> ret = lhs + rhs;

//    ret.print();
//}
