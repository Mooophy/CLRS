/***************************************************************************
 *  @file       main.cpp
 *  @author     Alan.W
 *  @date       18  Mar 2014
 *  @remark     This code is for Introduction to Algorithms
 *  @note       code style : STL
 ***************************************************************************/

//!
//! ex2.3-7 ★
//! Given a set S of n intergers and another integer x.
//! Describe a O(nlog2(n))- time algorithm to determine whether or not there exist
//! two elements in S whose sum is exactly x.
//!
//! psyeudocode:    range[set, value)
/*      bool find_sum(set value)
 *1     if (set.begin - set.end) < 1
 *2         return false
 *3     merge_sort(set.begin, (set.end - 1))     //takes O(nlog2(n)) worst running time
 *4     for iter = first to (last-1)             //4-6 takes O(nlog2(n)) as well
 *5         if (set.end != binary_search(iter, set.end, value - *iter))
 *6             return true
 *7     return false
 */

#include<iostream>
#include<vector>

/**
 * @brief find_sum  for ex2.3-7
 */
template<typename ValueType>
bool find_sum(std::vector<ValueType>& v, const ValueType& value);




//! binary_search
template<typename Iter, typename ValueType>
Iter binary_search(Iter first, Iter last, ValueType value);
//! recur_binary_search
template<typename Iter, typename ValueType>
Iter recur_binary_search(Iter first, Iter last, ValueType value, Iter Nil);
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
    std::vector<unsigned> v = {3,4,5,64,6,7};
    std::cout << find_sum(v, unsigned(71));
    return 0;
}

/**
 * @brief find_sum
 */
template<typename ValueType>
bool find_sum(std::vector<ValueType>& v, const ValueType& value)
{
    if (v.end() - v.begin() < 1)
        return false;
    merge_sort(v.begin(), (v.end() - 1));
    for(auto iter = v.begin(); iter != v.end(); ++iter)
        if(v.end() != binary_search(iter+1, v.end(), value - *iter))
            return true;
    return false;
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
        if(it_L == L.end())
        {
            *it = *it_R++;  continue;
        }

        if(it_R == R.end())
        {
            *it = *it_L++;  continue;
        }

        *it = (*it_L <= *it_R)  ?  *it_L++  :  *it_R++  ;
        //!          ^^
        //! @note L has priority, hence it becomes empty first.
    }
}



//! @part 1     interface
//! check pseudocode for detailed algorithm
template<typename Iter, typename ValueType>
inline Iter binary_search(Iter first, Iter last, ValueType value)
{
    Iter Nil = last;
    return recur_binary_search(first, last, value, Nil);
}


//! @part 2     actual recursion part
//! check pseudocode for detailed algorithm
template<typename Iter, typename ValueType>
inline Iter recur_binary_search(Iter first, Iter last, ValueType value, Iter Nil)
{
    Iter mid = first + (last - first)/2;
    if (*mid == value)  return mid;
    else
    {
        if(mid == first) return Nil;
        if(*mid < value)
            return recur_binary_search(mid  , last, value, Nil);
        else
            return recur_binary_search(first, mid , value, Nil);
    }
}







