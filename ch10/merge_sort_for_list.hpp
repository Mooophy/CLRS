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
 * 28   return ret;
 */

#ifndef MERGE_SORT_FOR_LIST_HPP
#define MERGE_SORT_FOR_LIST_HPP

#endif // MERGE_SORT_FOR_LIST_HPP
