/***************************************************************************
 *  @file       heap.h
 *  @author     Alan.W
 *  @date       7  May 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

//! revised on CLRS page 152
//! parent
/*      parent(first, target)
 * 1    assert first <= target
 * 2    if(first == target)
 * 3        return target
 * 4    else
 *          return first + (target - first - 1)/2
 */

//! MAX-HEAPIFY
//! based on clrs page 154
/*      max_heapify(first, last, target)
 * 1    l = left(first, target)
 * 2    r = right(first,target)
 * 3    if (l < last) && (*l > *target)
 * 4        largest = l
 * 5    else
 *          largest = target
 * 6    if (r < last) && (*r > *largest)
 * 7        largest = r
 * 8    if largest != target
 * 9        exchange(*target, *largest)
 * 10        max_heapify(first, last, largest)
 */

//! MAX-HEAPIFY-ITERATIVE   PART 1
/*      max_heapify_single_step(first, last, target)
 * 1    l = left(first, target)
 * 2    r = right(first,target)
 * 3    if (l < last) && (*l > *target)
 * 4        largest = l
 * 5    else
 *          largest = target
 * 6    if (r < last) && (*r > *largest)
 * 7        largest = r
 * 8    if largest != target
 * 9        exchange(*target, *largest)
 * 10   return largest
 */

//! MAX-HEAPIFY-ITERATIVE   PART 2
/* 1    max_heapify_iterative(first, last, target)
 * 2    def previous, current
 * 3    previous = current = target
 * 4    do
 * 5        previous    = current
 * 6        current     = max_heapify_single_step(first, last, previous)
 * 7    while   current != previous
 */



//! MIN-HEAPIFY
/*      min_heapify(first, last, target)
 * 1    l = left(first, target)
 * 2    r = right(first,target)
 * 3    if( l<last && *l<*target)
 * 4        smallest = l
 * 5    else
 *          smallest = target
 * 6    if( r<last && *r<*target )
 * 7        smallest =r
 * 8    if(smallest != target)
 * 9        excheange(*target, *largest)
 * 10       min_heapify(first, last, smallest)
 */

#ifndef HEAP_H
#define HEAP_H

#include <assert.h>
#include <algorithm>

namespace ch6 {

/**
 * Declarations
 */

//! MAX-HEAPIFY-ITERATIVE   PART 1
template<typename Iter>
Iter max_heapify_single_step(Iter first, Iter last, Iter target);
//! MAX-HEAPIFY-ITERATIVE   PART 2
template<typename Iter>
void max_heapify_iterative(Iter first, Iter last, Iter target);


//! min heapify
template<typename Iter>
void min_heapify(Iter first, Iter last,Iter target);

//! max heapify
template<typename Iter>
void max_heapify(Iter first, Iter last, Iter target);

//! parent
template<typename Iter>
Iter parent(Iter first, Iter target);

//! left
template<typename Iter>
Iter left(Iter first, Iter target);

//! right
template<typename Iter>
Iter right(Iter first, Iter target);




/**
 * Implementation
 */

//! parent
template<typename Iter>
inline Iter parent(Iter first, Iter target)
{
    assert(first <= target);
    if(first == target)
        return target;
    else
        return first + (target - first - 1)/2;
}

//! left
template<typename Iter>
inline Iter left(Iter first, Iter target)
{
    assert(first <= target);
    return first + 2 * (target - first) + 1;
}

template<typename Iter>
inline Iter right(Iter first, Iter target)
{
    assert(first <= target);
    return first + 2 * (target - first + 1);
}

//! max heapify
//! @running time : O(lg n) = O(h)  (p156)
template<typename Iter>
inline void max_heapify(Iter first, Iter last, Iter target)
{
    assert((first <= target) && (target < last));
    Iter l = left(first, target);
    Iter r = right(first, target);

    Iter largest = (l < last  &&  *l > *target)?     l   :   target;

    if(r < last  &&  *r > *largest)
        largest = r;

    if(largest != target){
        std::swap(*target, *largest);
        max_heapify(first, last, largest);
    }
}

//! min heapify
//! @running time : O(lg n) = O(h)
template<typename Iter>
inline void min_heapify(Iter first, Iter last, Iter target)
{
    assert((first <= target) && (target < last));

    Iter l = left(first, target);
    Iter r = right(first,target);

    Iter smallest = ( l < last  &&  *l < *target)?      l   :   target;

    if( r < last  &&  *r < *target )
        smallest = r;

    if(smallest != target){
        std::swap(*target, *smallest);
        min_heapify(first, last, smallest);
    }
}

//! MAX-HEAPIFY-ITERATIVE   PART 1
template<typename Iter>
inline Iter max_heapify_single_step(Iter first, Iter last, Iter target)
{
    assert((first <= target) && (target < last));
    Iter l = left(first, target);
    Iter r = right(first, target);

    Iter largest = (l < last  &&  *l > *target)?     l   :   target;

    if(r < last  &&  *r > *largest)
        largest = r;

    if(largest != target)
        std::swap(*target, *largest);

    return largest;
}
//! MAX-HEAPIFY-ITERATIVE   PART 2
template<typename Iter>
inline void max_heapify_iterative(Iter first, Iter last, Iter target)
{
    assert((first <= target) && (target < last));

    Iter previous, current;
    previous = current = target;
    do{
        previous = current;
        current  = max_heapify_single_step(first, last, previous);
    }
    while(current != previous);
}


}//namespace
#endif // HEAP_H

//! for test
/*
int main ()
{
    std::vector<long long > v = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};

    //auto iter = v.begin() + 6;
    //std::cout << *ch6::parent(v.begin(), iter) << std::endl;
    //std::cout << *ch6::left(v.begin(),  iter)  << std::endl;
    //std::cout << *ch6::right(v.begin(), iter)  << std::endl;
    //ch6::max_heapify_iterative(v.begin(),v.end(), v.begin()+2);
    //ch6::max_heapify(v.begin(),v.end(),v.begin()+2);

    for(auto i : v)
        std::cout << i << std::endl;
}
*/
