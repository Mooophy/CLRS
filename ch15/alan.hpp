/***************************************************************************
 *  @file       alan.hpp
 *  @author     alan.w
 *  @date       13  August 2014
 *  @remark     CLRS Algorithms implementation, using C++ templates.
 *              Custom utilites
 ***************************************************************************/

#ifndef ALAN_HPP
#define ALAN_HPP

#include <string>
#include <iostream>

namespace alan {

/**
 * @brief print_container
 * @param rng
 */
template<typename Range>
inline void
print_container(const Range& rng)
{
    for(const auto& elem : rng)
        std::cout << elem ;
}

}//namespaces

#endif // ALAN_HPP
