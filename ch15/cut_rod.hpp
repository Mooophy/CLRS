/***************************************************************************
 *  @file       node.hpp
 *  @author     Alan.W
 *  @date       17  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
//!
//! ex15.1-3
//! Consider a modification of the rod-cutting problem in which, in addition to a
//! price pi for each rod, each cut incurs a fixed cost of c. The revenue associated with
//! a solution is now the sum of the prices of the pieces minus the costs of making the
//! cuts. Give a dynamic-programming algorithm to solve this modified problem.
//!

#ifndef CUT_ROD_HPP
#define CUT_ROD_HPP

#include <algorithm>
#include <iterator>
#include <limits>
#include <assert.h>
#include "color.hpp"

namespace ch15 {

template<typename Iter>
typename std::iterator_traits<Iter>::value_type
cut_rod(Iter first, typename std::iterator_traits<Iter>::difference_type len);

template<typename Range>
typename Range::value_type
bottom_up_with_cost(const Range& prices, typename Range::value_type cost);

template<typename Iter>
typename std::iterator_traits<Iter>::value_type
bottom_up_with_cost(
            Iter first,
            Iter last,
            const typename std::iterator_traits<Iter>::value_type& per_cut
                    );


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
 * @brief bottom_up_with_cost
 * @param first
 * @param last
 * @param per_cut
 *
 * @ex  15.1-3
 * @page 370, CLRS
 * @complx  O(n^2)
 */
template<typename Iter>
inline typename std::iterator_traits<Iter>::value_type
bottom_up_with_cost(
            Iter first,
            Iter last,
            const typename std::iterator_traits<Iter>::value_type& per_cut
                    )
{
    using ValueType =   typename    std::iterator_traits<Iter>::value_type;
    using DiffType  =   typename    std::iterator_traits<Iter>::difference_type;

    //! lambda for cut cost
    auto cost = [&](DiffType outer, DiffType inner)->ValueType
    {
          return (outer == inner)?  0   :   per_cut;
    };

    DiffType size   =   last - first;
    assert(size > 0);
    std::vector<ValueType>  records(size + 1, 0);

    //! find solutions to all lengths , storing in records
    for(DiffType outer = 0; outer != size; ++outer)
    {
        ValueType maximum = std::numeric_limits<ValueType>::min();

        //! find the optimal solution for the current length
        for(DiffType inner = 0; inner != outer + 1; ++inner)
            maximum = std::max(maximum,
                              *(first + inner) + records[outer - inner]
                                    - cost(outer, inner));

        records[outer + 1] = maximum;
    }
    return records.back();
}


/**
 * @brief The RodCutter class
 *
 * abstract
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
        revenue(sz + 1, std::numeric_limits<ValueType>::min()),
        solutions(sz + 1)
    {}

    /**
     * @brief   return the optimal revenue
     *
     * @note    just a wraper for virtual function
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

    /**
     * @brief print_solutions
     */
    void print_solutions(Iter first, SizeType len)
    {
        print_solu(first, len);
    }

    virtual ~RodCutter(){}

protected:
    Container   revenue;
    Container   solutions;

private:
    /**
     * @brief private absolute virtual functions
     */
    virtual ValueType dynamic_program(Iter first, SizeType len) = 0;
    virtual void print_solu(Iter first, SizeType len) = 0;
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

    using B::RodCutter;
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
     *
     * @complx O(n^2)
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

/**
 * @brief BottomUp
 */
template<typename Iter>
class RodCutterBottomUp : public RodCutter<Iter>
{
public:
    using B         =               ch15::RodCutter<Iter>;
    using SizeType  =   typename    B::SizeType;
    using ValueType =   typename    B::ValueType;

    using B::RodCutter;
    virtual ~RodCutterBottomUp(){}

protected:
    using B::revenue;
    using B::solutions;

    /**
     * @brief the virtual function
     */
    virtual ValueType dynamic_program(Iter first, SizeType len) override
    {
        std::cout << color::yellow("By bottom-up dynamic programming:\n");
        return bottom_up(first, len);
    }

    /**
     * @brief print_solu
     *
     * @pseudocode  PRINT-CUT-SOLUTION(p,n)
     * @page    369,CLRS
     * @complx  O(n)
     */
    virtual void print_solu(Iter first, SizeType len) override
    {
        bottom_up(first, len);

        std::cout << color::green("the optimal solution is:\n");
        while(len > 0)
        {
            std::cout << solutions[len] << " ";
            len -=  solutions[len];
        }
    }

    /**
     * @brief top_down
     *
     * @pseudocode  BOTTOM-UP-CUT-ROD, EXTENDED-BOTTOM-UP-CUT-ROD
     * @page 366, 369, CLRS
     * @complx O(n^2)
     */
    virtual ValueType bottom_up(Iter first, SizeType len)
    {
        //! update the container
        std::fill(revenue.begin(),revenue.end(),0);

        for(int outer = 1; outer != len + 1; ++outer)
        {
            ValueType result = std::numeric_limits<ValueType>::min();
            for(int inner = 0; inner != outer; ++inner)
            {
                if(result   <   *(first + inner) + revenue[outer - inner - 1] )
                {
                    result = std::max(result,
                                      *(first + inner) + revenue[outer - inner - 1]);
                    solutions[outer] =  inner + 1;
                }
            }
            revenue[outer] = result;
        }

        return revenue.back();
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

//! test bottom-up
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
//    using BottomUp  =   ch15::RodCutterBottomUp<Iter>;

//    //! allocation for the top-down dynamic programming
//    auto cut =  std::make_shared<BottomUp>(v.size());

//    //! print
//    std::cout << cut->optimize(v.begin(),v.size()) <<std::endl;
//    cut->print_container();

//    return 0;
//}

//! test extended-bottom-up-cut-rod and print-cut-rod-solution
//#include <iostream>
//#include <memory>
//#include "cut_rod.hpp"
//#include "color.hpp"
//int main()
//{
//    //! build the array r
//    std::vector<int> v = {1,5,8,9,10,17,17,20,24,30};
//    using Iter      =   std::vector<int>::iterator;
//    using TopDown   =   ch15::RodCutterTopDown<Iter>;
//    using BottomUp  =   ch15::RodCutterBottomUp<Iter>;

//    //! allocation for the top-down dynamic programming
//    auto cut =  std::make_shared<BottomUp>(v.size());

//    //! print
//    std::cout << cut->optimize(v.begin(),v.size()) <<std::endl;
//    cut->print_container();
//    cut->print_solutions(v.begin(),v.size());

//    std::cout << color::red("\nend\n");
//    return 0;
//}

//! test ex15.1-3 : cut with cost
//#include <iostream>
//#include <memory>
//#include "cut_rod.hpp"
//#include "color.hpp"
//int main()
//{
//    //! build the array r
//    std::vector<int> v = {1,5,8,9,10};

//    int result = ch15::bottom_up_with_cost(v.begin(), v.end(), 1);
//    std::cout << result << std::endl;


//    std::cout << color::red("\nend\n");
//    return 0;
//}
