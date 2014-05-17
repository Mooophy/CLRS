//!	check sorts.h for style version
#include <iostream>
#include <algorithm>

//! the ordinary version
void insertionSort(std::vector<int>& v);

//! the template version
template<typename T>
void
insertionSortTPL(std::vector<T>& v)
{
    for(int j =1; j != (int)v.size(); ++j)
    {
        T key = v[j];
        int i = j - 1;
        while(i >= 0 && v[i] > key)
        {
            v[i+1] = v[i];
            --i;
        }
        v[i+1] = key;
    }
}
int main()
{
    std::vector<std::string> v = {"zaa","dd","ss","bb","66"};

    insertionSortTPL<std::string>(v);

    for(auto i : v)
        std::cout << i << "\n";

    return 0;
}


void insertionSort(std::vector<int> &v)
{
    for (int j = 1; j!= (int)v.size() ; ++j)
    {
        int key = v[j];
        int i = j-1;
        while(i >= 0 && v[i]>key)
        {
            v[i+1] = v[i];
            --i;
        }
        v[i+1] = key;
    }
}

