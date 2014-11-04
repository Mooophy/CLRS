/***************************************************************************
 *  @file       merge_k_sorted_lists.hpp
 *  @author     Yue Wang
 *  @date       14  Sep 2014
 *  @version    2
 *  @remark     CLRS Algorithms implementation in C++ templates.
 ***************************************************************************/

#ifndef MERGE_K_SORTED_LISTS_HPP
#define MERGE_K_SORTED_LISTS_HPP

#include <memory>
#include <iostream>

namespace clrs {namespace ch6 {

template<typename K, typename D>
struct Node
{
    using KeyType   =   K;
    using DataType  =   D;
    using sPointer  =   std::shared_ptr<Node<K,D>>;

    K key;
    D data;
    sPointer next;
};

template<typename K,typename D>
inline std::ostream&
operator <<(std::ostream& os, const Node<K,D>& rhs)
{
    os << "key = " << rhs.key
       << "  data = " << rhs.data
       << "  next = " << rhs.next
       << std::endl;

    return os;
}

template<typename Node>
inline bool
operator <(const Node& lhs, const Node& rhs)
{
    return lhs.key  <   rhs.key;
}


//template<typename Node>
//class List
//{
//public:
//    using sPointer  =   typename Node::sPointer;

//    List():
//        head{nullptr},tail{nullptr}
//    {}

//private:

//};

}}//namespace
#endif // MERGE_K_SORTED_LISTS_HPP

//! @test   Node
//!
//#include <iostream>
//#include "../misc/alan.hpp"
//#include "merge_k_sorted_lists.hpp"

//int main()
//{
//    using namespace clrs::ch6;
//    using NodeType  =   Node<int, std::string>;

//    auto lhs = std::make_shared<NodeType>(NodeType{42, "node1", nullptr});
//    auto rhs = std::make_shared<NodeType>(NodeType{99, "node1", nullptr});
//    std::cout << *lhs << std::endl << *rhs;
//    std::cout << (*lhs < *rhs?  "less"  :   "greater");

//    alan::end();
//    return 0;
//}
//! @output
//!
//key = 42  data = node1  next = 0

//key = 99  data = node1  next = 0
//less
//exit normally

