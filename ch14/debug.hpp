/***************************************************************************
 *  @file       debug.hpp
 *  @author     Alan.W
 *  @date       05  July 2014
 *  @remark     used for debugging
 ***************************************************************************/
#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <string>

namespace debug{

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

}//namespace


#endif // DEBUG_HPP
