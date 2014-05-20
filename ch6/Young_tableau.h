/***************************************************************************
 *  @file       d_ary_heap.h
 *  @author     Alan.W
 *  @date       19  May 2014
 *  @remark     This code is for Introduction to Algorithms 3rd
 *  @note       code style : STL,BOOSTs
 ***************************************************************************/

//! for ch6 problem 6.3

#ifndef YOUNG_TABLEAU_H
#define YOUNG_TABLEAU_H

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <assert.h>

namespace ch6{


template<typename T>
class Young_tableau;
template<typename T>
std::ostream& operator <<(std::ostream& os, const Young_tableau<T>& rhs);

/**
 * @brief The Young_tableau class
 *
 * @note Ascending Order
 */
template<typename T>
class Young_tableau
{
    friend std::ostream& operator<< <T>(std::ostream& os, const Young_tableau<T>& rhs);
public:
    using ValueType = T;
    using Iter      = typename std::vector<ValueType>::iterator;
    using SizeType  = std::size_t;
    using Container = std::vector<ValueType>;

    /**
     * @brief default ctor
     */
    Young_tableau() = default;

    /**
     * @brief ctor
     */
    Young_tableau(const Container& vec, SizeType r, SizeType c ):
        data(vec), rows(r), cols(c)
    {}

    /**
     * @brief operator ()
     *
     * convert coordinate to iterator
     */
    Iter operator()(SizeType r, SizeType c)
    {
        return begin() + r * rows + c;
    }

    /**
     * @brief empty
     */
    bool empty() const
    {
        return data.empty();
    }

    /**
     * @brief pop
     */
    void pop()
    {
        assert(!empty());

        data.front() = data.back();
        data.resize(data.size() - 1);

        make_min(begin());
    }


    ~Young_tableau() = default;
private:
    /**
     * @brief data members
     */
    Container data;
    SizeType rows = 0;
    SizeType cols = 0;

    /**
     * @brief begin of Container
     */
    Iter begin()
    {
        return data.begin();
    }

    /**
     * @brief end of Container
     */
    Iter end()
    {
        return data.end();
    }

    /**
     * @brief left
     */
    Iter left(Iter target)
    {
        return target - 1;
    }

    /**
     * @brief up
     */
    Iter up(Iter target)
    {
        return target - cols;
    }

    /**
     * @brief right
     */
    Iter right(Iter target)
    {
        return target + 1;
    }

    /**
     * @brief down
     */
    Iter down(Iter target)
    {
        return target + cols;
    }

    /**
     * @brief check if target is in the range [begin, end)
     */
    bool verify(Iter target)
    {
        return begin() <= target && target < end();
    }

    /**
     * @brief make_min
     *
     * @complexity O( rows + cols )
     *
     * implemented for Problem 6-3 c, Page 168.
     * the same as max-heapify Page 154.
     */
    void make_min(Iter target)
    {
        Iter d = down(target);
        Iter r = right(target);
        Iter least = target;

        //! find the smallest one among right, down and target.
        if(verify(d) && *d < *target)   least = d;
        if(verify(r) && *r < *least)    least = r;

        //! swap and recur, if true.
        if(least != target)
        {
            std::swap(*target, *least);
            make_min(least);
        }
    }
};

/**
 * @brief operator <<   print in matrix style
 */
template<typename T>
inline std::ostream& operator <<(std::ostream& os, const ch6::Young_tableau<T>& rhs)
{
    std::size_t count = 0;
    for(const auto& item : rhs.data)
    {
        os << item << "    ";
        if(count++ == rhs.cols - 1)
        {
            std::cout << std::endl;
            count = 0;
        }
    }
    return os;
}
}//namespace

#endif // YOUNG_TABLEAU_H
