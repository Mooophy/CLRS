/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       17  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : CLRS
 *              That is, use the last one rather than one pass last one
 ***************************************************************************/
//!
//! Merge-Sort
//!             for EX2.3-2
//!
//!     @pseudocode for meger:
/*      Merge(A, p, q, r)
 *1     n1 = q - p + 1
 *2     n2 = r - q
 *3     let L[1..n1 + 1] and R[1..n2 + 1] be new arrays
 *4     for i = 1 to n1
 *5         L[i] = A[p + i - 1]
 *6     for j = 1 to n2
 *7         R[j] = A[q + j]
 *8     i = 1
 *9     j = 1
 *10    for k = p to r
 *11        if i == n1 + 1
 *12            while j != n2 +1
 *13                A[k] = R[j]
 *14                j = j + 1
 *15            return
 *16        if j == n2 + 1
 *17            while i != n2 +1
 *18                A[k] = L[i]
 *19                i = i + 1
 *20            return
 *21        if L[i] <= R[j]
 *22            A[k] = L[i]
 *23            i = i + 1
 *24        else A[k] = R[j]
 *25            j = j + 1
 */

//!     @pseudocode for merge_sort:
/*      Merge_Sort(A,p,r)
 *1     if p < r
 *2         q = [(p + r)/2]
 *3         Merge_Sort(A, p, q)
 *4         Merge_Sort(A, q + 1, r)
 *5         Merge(A, p, q, r)
 */

#include <iostream>
#include <vector>
#include <algorithm>

/**
 *  merge_sort
 */
template<typename Iterator>
void merge_sort(Iterator p, Iterator r);

/**
 *  Merge
 */
template<typename Iterator>
void merge(Iterator p, Iterator q, Iterator r);

int main()
{
    //! test:
    std::vector<float> v = {0,0,3.2,4.5,5,1,23,5,1,23,51,23,12,5123,2};
    std::vector<std::string> vs={};
    //merge(v.begin(), v.begin() + 1, v.end()- 1);

    merge_sort(v.begin(), v.end() - 1);

    for(auto i : v)
        std::cout << i << std::endl;

    return 0;
}

/**
 *  merge_sort
 */
template<typename Iterator>
void merge_sort(Iterator p, Iterator r)
{
    if (p < r)
    {
        Iterator q = p + (r - p)/2 ;
        merge_sort(p , q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}



/**
 *  Merge
 *
 *  devide a vector into two parts[p,q] and [q + 1, r].
 *  and merge them by comparing each pair.Check the pseudocaode for detail.
 *
 *  @note   this code use end() to detect if empty, instead of infinity
 *          sentinel as did in pseudocode.
 */
template<typename Iterator>
void merge(Iterator p, Iterator q, Iterator r)
{
    //! fetch the type the iterators point
    typedef typename std::iterator_traits<Iterator>::
            value_type  ValueType;

    //! lines 1 - 7  : copy construct L and R from A.
    std::vector<ValueType> L(p     , q + 1);     //  [p  , q + 1)
    std::vector<ValueType> R(q + 1 , r + 1);     //  [q+1, r + 1)

    //! linse 8 - 17 : merge the two parts.
    auto it_L = L.begin();
    auto it_R = R.begin();
    for(auto it = p; it != r + 1; ++it)
    {
        //! modified for ex2.3-2
        if(it_L == L.end())
        {
            while(it != r+1)    *it++ = *it_R++;
            break;
        }

        if(it_R == R.end())
        {
            while(it != r+1)    *it++ = *it_L++;
            break;
        }

        *it = (*it_L <= *it_R)  ?  *it_L++  :  *it_R++  ;
        //!          ^^
        //! @note L has priority, hence it becomes empty first.
    }
}
