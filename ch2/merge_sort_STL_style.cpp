#include <vector>
#include <iostream>


/**
 *  merge_sort
 *  @param [first, last)
 */
template<typename Iter>
void merge_sort(Iter first, Iter last);

/**
 * @brief merge     divide the original array
 * into two parts:  [first, mid) and [mid, last)
 * @para  [first..mid..last)
 */
template<typename Iter>
void merge(Iter first, Iter mid, Iter last);

template<typename Iter>
void merge_sort(Iter first, Iter last)
{
    if(first < last - 1)
    {           //! ^^^ -- due to STL style, last must be minus 1
                //! so that it terminates recursions when only 1 element
                //! left in vector,otherwise it causes deadlock
        Iter mid = first + (last - first)/2;
        merge_sort(first, mid );
        merge_sort(mid  , last);
        merge(first, mid, last);
    }
}

template<typename Iter>
void merge(Iter first, Iter mid, Iter last)
{
    //! create two local vector to store the two parts
    typedef typename std::iterator_traits<Iter>::
            value_type      ValueType;
    std::vector<ValueType> lhs(first, mid);
    std::vector<ValueType> rhs(mid  , last);

    //! compare each element from lhs and rhs, then copy the
    //! smaller one to the original vector.
    auto l  = lhs.begin();
    auto r  = rhs.begin();
    auto it = first;
    while((it != last) && (r != rhs.end()) && l != lhs.end())
    {
        if(*r < *l)     *it++ = *r++;
        else            *it++ = *l++;
    }

    //! if either one is empty, copy all left in the other.
    if(l == lhs.end())
        while(it != last)   *it++ = *r++;
    if(r == rhs.end())
        while(it != last)   *it++ = *l++;
}
int main()
{
    std::vector<int> v = {5,4,6,6,6,48,0,-22};
    std::vector<std::string>
            vs = {"44","33","22","11","00","66"};

    //merge(v.begin(), v.begin() + 1, v.end());
    merge_sort(v.begin(), v.end());

    for(auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << std::endl;
}

