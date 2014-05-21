/***************************************************************************
 *  @file       quick_sort.h
 *  @author     Alan.W
 *  @date       21  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/
//!
//! pseudocode
//! based on RANDOMIZED-PARTITION Page 179
//!
/*      randomized_partion(first, last)
 *1     def random_engine e
 *2     def uniform_distrabution ud(0, last - first - 1)
 *3     def piovt = ud(e)
 *4     swap(*pivot,*(last - 1))
 *5     return partition(first, last)
 */

//!
//! pseudocode
//! based on RANDOMIZED-QUICKSORT Page 179
//!

/*      randomized_quicksort(first, last)
 * 1    if last - first > 1
 * 2        pivot = randomized_partion(first, last)
 * 3        randomized_quicksort(first, pivot)
 * 4        randomized_quicksort(pivot + 1, last )
 */


#ifndef RANDOMIZED_QUICK_SORT_H
#define RANDOMIZED_QUICK_SORT_H



#endif // RANDOMIZED_QUICK_SORT_H
