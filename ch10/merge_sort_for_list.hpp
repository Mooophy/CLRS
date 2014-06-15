/***************************************************************************
 *  @file       merge_sort_for_list.hpp
 *  @author     Alan.W
 *  @date       15   Jun 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note
 ***************************************************************************/
//!
//! merge_sort_for_list(node)
//! complexity  O(n lg n)
//!             no extra space needed
//! pseudo code:
/*      merge_sort_for_list(node)
 * 1    if(!node || !node->next)
 * 2        return node
 * 3    def left, right, temp, last
 * 4    left = right = temp = last = node
 * 5    while(temp && temp->next)   //search for the half node
 * 6        last    = right
 * 7        right   = right->next
 * 8        temp    = temp->next->next
 * 9    last->next = nullptr        //break into two lists
 * 10   left    = merge_sort_for_list(left)
 * 11   right   = merge_sort_for_list(right)
 * 12   def ret, next
 * 13   while(left || right)
 * 14       if(!right)
 * 15           next    =   left
 * 16           left    =   left->next
 * 17       else if(!left)
 * 18           next    =   right
 * 19           right   =   right->next
 * 20       else if(left->key < right->key)
 * 21           next    =   left
 * 22           left    =   left->next
 * 23       else
 * 24           next    =   right
 * 25           right   =   right->next
 * 26       if(!ret)
 * 27           ret     =   next
 * 28       else
 *              tail->next  =   next
 * 29   return ret;
 */

#ifndef MERGE_SORT_FOR_LIST_HPP
#define MERGE_SORT_FOR_LIST_HPP

#include "list.hpp"
#include <memory>

namespace ch10 {

template<typename T>
std::shared_ptr<list::node<T> >
merge_sort_for_list(const std::shared_ptr<list::node<T> >& node);

/**
 * @brief merge_sort_for_list
 *
 * @complexity  time:   O(n lg n)
 *              space:  no extra space needed, compared with the same algorithm on array
 *                      which requires O(n) extra space.
 *
 * check above for pseud code which is based on an alorithm on SO:
 * http://stackoverflow.com/questions/7685/merge-sort-a-linked-list
 */
template<typename T>
inline std::shared_ptr<list::node<T> >
merge_sort_for_list(const std::shared_ptr<list::node<T> >& node)
{
    using ValueType = T;
    using Node      = list::node<ValueType>;
    using sPointer  = std::shared_ptr<Node>;

    //! recursion stopping condition
    if(!node || !node->next)    return node;

    //! search for the middle node
    sPointer left, right, fast, last;
    left = right = fast = last = node;
    while(fast && fast->next)
    {
        last    =   right;
        right   =   right->next;
        fast    =   fast->next->next;
    }

    //! split the original linked list
    last->next  =   nullptr;

    //! recur
    left    =   merge_sort_for_list(left);
    right   =   merge_sort_for_list(right);

    //! merge
    sPointer ret, next, tail;
    while(left || right)
    {
        if(!right)      //when right part is exhausted.
        {
            next    =   left;
            left    =   left->next;
        }
        else if(!left)  //when left  part is exhausted.
        {
            next    =   right;
            right   =   right->next;
        }
        else if(left->key < right->key)
        {
            next    =   left;
            left    =   left->next;
        }
        else
        {
            next    =   right;
            right   =   right->next;
        }

        if(!ret)    ret         =   next;
        else        tail->next  =   next;
        //!         ^^^^^^^^^^^^^^^^^^^^^
        //! @attention tail here is for appending.

        tail    =   next;
    }
    return ret;
}

}//namespace
#endif // MERGE_SORT_FOR_LIST_HPP
