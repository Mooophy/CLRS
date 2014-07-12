/***************************************************************************
 *  @file       redblacktree.hpp
 *  @author     Yue Wang
 *  @date       09  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
//!
//! Problem 13-1
//!
//! e.  Show how to use red-black trees to guarantee that the worst-case running time
//! and space are O(lg n) per insertion or deletion.
//!
#ifndef PERSISTENT_RED_BLACK_TREE_HPP
#define PERSISTENT_RED_BLACK_TREE_HPP

#include <memory>
#include <functional>
#include <vector>
#include "node.hpp"

namespace ch13 {

/**
 * @brief Persistent Red Black Tree
 *
 * for problem 13-1.e
 */
template<typename K, typename D>
class PersistentRedBlackTree
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using NodeType  =   Node<K,D>;
    using sPointer  =   std::shared_ptr<NodeType>;
    using wPointer  =   std::weak_ptr<NodeType>;
    using Vector    =   std::vector<sPointer>;

    bool empty()const
    {
        return versions.empty();
    }

    void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    void insert(const KeyType &key, const DataType& data)
    {
        sPointer added = std::make_shared<NodeType>(key, data);
        insert(added);
    }


    /**
     * @brief print
     */
    void print()const
    {
        //! lambda for printing a version
        std::function<void(sPointer)> inorder_walk=
                [&](sPointer node)
        {
            if(node)
            {
                inorder_walk(node->left);
                node->print();
                inorder_walk(node->right);
            }
        };

        //! print all
        int ver = 0;
        for(const auto& root : versions)
        {
            std::string verStr = debug::green(std::to_string(ver++));
            std::cout << debug::green("version " + verStr) << std::endl;
            inorder_walk(root);
        }
    }
private:
    Vector  versions;
    sPointer nil;

    void insert(sPointer added)
    {
       if(empty())
           versions.push_back(added);
       else
       {
            std::cout << debug::green("not implemented!!") << std::endl;
       }
    }
};

}//namespace
#endif // PERSISTENT_RED_BLACK_TREE_HPP
