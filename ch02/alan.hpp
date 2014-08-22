/***************************************************************************
 *  @file       alan.hpp
 *  @author     alan.w
 *  @date       13  August 2014
 *  @remark     CLRS Algorithms implementation in C++ templates.
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
        std::cout << elem << " ";
}

/**
 * @brief green
 */
std::string green(const std::string& str)
{
    return "\033[1;32m" + str + "\033[0m";
}

/**
 * @brief red
 */
std::string red(const std::string& str)
{
    return "\033[1;31m" + str + "\033[0m";
}

/**
 * @brief yellow
 */
std::string yellow(const std::string& str)
{
    return "\033[1;33m" + str + "\033[0m";
}

/**
 * @brief prompt
 * @param description
 */
void prompt(std::string&& description = "the output is")
{
    std::cout << std::move(green(description + "\n"));
}

/**
 * @brief end
 * @param description   string
 */
void end(std::string&& description = "exit normally")
{
    std::cout << std::move(green("\n" + description + "\n"));
}


}//namespaces

#endif // ALAN_HPP
