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

namespace ch6{

template<typename T>
class Young_tableau;

template<typename T>
class Young_tableau
{
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
     * @brief left of target
     */
    Iter left(Iter target)
    {
        return target - 1;
    }

    /**
     * @brief up of target
     */
    Iter up(Iter target)
    {
        return target - cols;
    }

    /**
     * @brief check if target is in the range [begin, end)
     */
    bool verify(Iter target)
    {
        return begin() <= target && target > end();
    }
};

}//namespace

#endif // YOUNG_TABLEAU_H
