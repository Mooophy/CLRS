/***************************************************************************
 *  @file       hash_table.hpp
 *  @author     Alan.W
 *  @date       22  June 2014
 *  @remark     Implementations for algorithims from CLRS using C++ templates.
 ***************************************************************************/

//! pseudo code     page 258
//  CHAINED-HASH-INSERT(T,x)    O(1)
//1 insert x at the head of list T[h(x.key)]

//  CHAINED-HASH-SEARCH(T,k)    O(1)
//1 search for an element with key k in list T[h(k)]

//  CHAINED-HASH-DELETE(T,x)    O(1)
//1 delete x from the list T[h(x.key)]

#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include <vector>
#include "node.hpp"

namespace ch11 {

/**
 * @brief hash table class
 *
 * using double linked list each slot
 * using std::vector as underlying data structure
 */
template<typename K, typename D>
class hash_table
{
public:
    using SizeType  =   K;
    using KeyType   =   K;
    using DataType  =   D;
    using Node      =   node<K,D>;
    using sPointer  =   std::shared_ptr<Node>;
    using wPointer  =   std::weak_ptr<Node>;
    using Hash      =   std::function<K(K)>;
    using Container =   std::vector<sPointer>;

    hash_table()    =   delete;

    /**
     * @brief Ctor
     */
    hash_table(const SizeType& sz, const Hash& h):
        hash(h), container(sz,sPointer())
    {}

    /**
     * @brief insert
     * @param key
     * @param data
     * @complexity  O(1)
     *
     * refer to CLRS 11.2 for compexity proof.
     */
    void insert(const KeyType& key, const DataType& data)
    {
        sPointer&   head        =   container[hash(key)];
        sPointer    inserted    =   std::make_shared<Node>(key, data);
        if(!head)
            head    =   inserted;
        else
        {
            inserted->next  =   head;
            head->prev      =   inserted;
            head            =   inserted;
        }
    }

    /**
     * @brief search
     * @param key
     * @return shared pointer
     *
     * @complexity  O(1)
     * refer to CLRS 11.2 for compexity proof.
     */
    sPointer search(const KeyType key)
    {
        sPointer ret = nullptr;
        sPointer curr = container[hash(key)];
        while(curr)
        {
            if(curr->key    ==   key)
            {
                ret = curr;
                break;
            }
        }
        return ret;
    }

    /**
     * @brief erase
     *
     * @complexity  O(1)
     *
     * refer to figure 11.3 on page 257 for all 4 cases
     */
    void erase(sPointer target)
    {
        sPointer&   head = container[hash(target->key)];
        sPointer&   next = target->next;
        wPointer&   prev = target->prev;

        if(!next && !prev.lock())       //only one node
            head    =   nullptr;
        else if(next && !prev.lock())   //the first one of multiple nodes
        {
            next->prev.reset();
            head    =   next;
        }
        else if (!next && prev.lock())  //the last one of multiple nodes
            prev.lock()->next   =   nullptr;
        else                            //the middle one of multiple nodes
        {
            next->prev  =   prev;
            prev.lock()->next   =   next;
        }
    }

    /**
     * @brief print
     *
     * @complexity  O(n)
     */
    void print() const
    {
        for(const auto& elem : container)
        {
            sPointer curr = elem;
            while(curr)
            {
                std::cout << "key=" << curr->key
                          << " data=" << curr->data
                          << std::endl;

                curr = curr->next;
            }
        }
    }

private:
    Hash        hash;
    Container   container;

};

}//namespace
#endif // HASH_TABLE_HPP


//! test code
//#include <iostream>
//#include <hash_table.hpp>

//int main()
//{
//    auto hash =
//            [](const int key)->int
//            {
//                return key % 9;
//            };

//    ch11::hash_table<int, std::string> table(10, hash);

//    table.insert(6,"first try");
//    table.insert(88,"try 2");
//    table.insert(101,"try");

//    table.erase(table.search(101));
//    table.erase(table.search(6));
//    table.erase(table.search(88));

//    table.print();

//    std::cout << "end" << std::endl;
//    return 0;
//}
