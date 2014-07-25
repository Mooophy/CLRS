/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       17  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
#ifndef CUT_ROD_HPP
#define CUT_ROD_HPP

#include <algorithm>
#include <iterator>
#include <limits>
#include "color.hpp"

namespace ch15 {

template<typename Iter>
typename std::iterator_traits<Iter>::value_type
cut_rod(Iter first, typename std::iterator_traits<Iter>::difference_type len);

/**
 * @brief cut_rod
 *          return the optimal solution without using dynamic programming
 * @param first     the first iterator of p
 * @param len       n
 *
 * @complx  O(2^n)
 * @page    363, CLRS
 */
template<typename Iter>
inline typename std::iterator_traits<Iter>::value_type
cut_rod(Iter first, typename std::iterator_traits<Iter>::difference_type len)
{
    using ValueType =   typename std::iterator_traits<Iter>::value_type;
    using SizeType  =   typename std::iterator_traits<Iter>::difference_type;

    //! stop condition
    if(len == 0)
        return 0;

    //! initialize it as -infinity
    ValueType ret = std::numeric_limits<ValueType>::min();

    //! iteration with recursion
    for(SizeType count = 0 ; count != len ; ++count)
        ret = std::max(ret, *(first + count) + cut_rod(first,len - count - 1));

    return ret;
}



/**
 * @brief The RodCutter class
 *
 * abstract class
 */
template<typename Iter>
class RodCutter
{
public:
    using ValueType =   typename    std::iterator_traits<Iter>::value_type;
    using SizeType  =   typename    std::iterator_traits<Iter>::difference_type;
    using Container =               std::vector<ValueType>;

    /**
     * @brief   Ctor
     * @page    365
     * essentially, implementing MEMOIZED-CUT-ROD
     */
    RodCutter(SizeType sz):
        revenue(sz + 1, std::numeric_limits<ValueType>::min())
    {}

    /**
     * @brief reset
     *
     * call this function when applied on another array.
     */
    void reset(SizeType sz)
    {
        *this = RodCutter(sz);
    }

    /**
     * @brief   return the optimal revenue
     *
     * @note    just a wraper for virtual functions
     */
    ValueType optimize(Iter first, SizeType len)
    {
        return dynamic_program(first, len);
    }

    /**
     * @brief print the data stored in buffer.
     */
    void print_container() const
    {
        std::cout << color::green("The buffer data in container:\n");
        for(const auto& item : revenue)
            std::cout << item << " ";
        std::cout << std::endl;
    }

    virtual ~RodCutter(){}

protected:
    Container   revenue;

    /**
     * @brief the virtual function.
     */
    virtual ValueType dynamic_program(Iter first, SizeType len) = 0;
};

/**
 * @brief top-down dynamic programming for cut_rod
 */
template <typename Iter>
class RodCutterTopDown : public RodCutter<Iter>
{
public:
    using B         =               ch15::RodCutter<Iter>;
    using SizeType  =   typename    B::SizeType;
    using ValueType =   typename    B::ValueType;

    /**
     * @brief Ctor for top-down dynamic programming
     */
    RodCutterTopDown(SizeType sz):
        B(sz)
    {}

    virtual ~RodCutterTopDown(){}

protected:

    using B::revenue;

    /**
     * @brief the virtual function
     */
    virtual ValueType dynamic_program(Iter first, SizeType len) override
    {
        std::cout << color::yellow("By top-down dynamic programming:\n");
        return top_down(first, len);
    }

private:
    /**
     * @brief top_down
     * @param first the begin iterator for array p
     * @param len   n
     *
     * @page 365
     * @note essentially implementing MEMOIZED-CUT-ROD-AUX(p,n,r)
     */
    ValueType top_down(Iter first, SizeType len)
    {
        if(revenue[len] == 0)
            return revenue[len];

        ValueType ret;
        if(len == 0)
            ret = 0;
        else
        {
            ret = std::numeric_limits<ValueType>::min();
            for(SizeType count = 0 ; count != len ; ++count)
                ret = std::max(ret, *(first + count) + top_down(first, len - count - 1));
        }

        return revenue[len] = ret;
    }
};

}//namespace
#endif // CUT_ROD_HPP

//! test for top-down
//#include <iostream>
//#include <memory>
//#include "cut_rod.hpp"
//#include "color.hpp"
//int main()
//{
//    //! build the array r
//    std::vector<int> v = {1,5,8,9};
//    using Iter      =   std::vector<int>::iterator;
//    using TopDown   =   ch15::RodCutterTopDown<Iter>;

//    //! allocation for the top-down dynamic programming
//    auto cut =  std::make_shared<TopDown>(v.size());

//    //! print
//    std::cout << cut->optimize(v.begin(),v.size()) <<std::endl;
//    cut->print_container();

//    return 0;
//}
