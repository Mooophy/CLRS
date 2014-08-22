//! @Alan
//!
//! Ex2.1-2
//! Rewrite the INSERTION-SORT procedure to sort into nonincreasing instead of non-
//! decreasing order.
//!
/** @brief  insertion sort nonincreasing version
 *Insertion_Sort(A)
 *  for j = 2 to A.length
 *      key = a[j]
 *      i = j - 1
 *      while i>0 and A[i] < key    // note: <
 *          A[i+1]=A[i]
 *          i = i - 1
 *      A[i+1] = key
 ************************************************/
#include <iostream>
#include <vector>

//! nonincreasing version
void insertionSort(std::vector<int>& v);
int main()
{
    std::vector<int> v = {5,2,4,6,1,3,8,88,66,87,5};

    insertionSort(v);

    for(const auto i : v)
        std::cout << i << "\n";

    return 0;
}

//! nonincreasing version
void insertionSort(std::vector<int> &v)
{
    for (int j = 1; j!= (int)v.size() ; ++j)
    {
        int key = v[j];
        int i = j-1;
        while(i >= 0 && v[i] < key)
            //!              ^
        {
            v[i+1] = v[i];
            --i;
        }
        v[i+1] = key;
    }
}

