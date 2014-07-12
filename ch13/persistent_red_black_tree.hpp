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
       //!  initial case
       if(empty())
       {
           versions.push_back(added);
           return;
       }

       //!  previous and current version
       sPointer prev = versions.back();
       sPointer curr = std::make_shared<NodeType>(*prev);
       versions.push_back(curr);

       //!  search for the appropriate position, building the path.
       Vector   path = {nil, curr};
       while(true)
       {
            if(prev->key < added->key)
            {
                //! use existing node
                curr->left  =   prev->left;

                if(prev->right  ==  nil)    break;

                curr->right =   std::make_shared<NodeType>(*prev->right);
                prev        =   prev->right;
                curr        =   curr->right;
            }
            else
            {
                //! use existing node
                curr->right =   prev->right;

                if(prev->left   ==  nil)    break;

                curr->left  =   std::make_shared<NodeType>(*prev->left);
                prev        =   prev->left;
                curr        =   curr->left;
            }
            path.push_back(curr);
       }

       //!  graft on the inserted node
       (curr->key < added->key?     curr->right :   curr->left)     =   added;
       added->left  =   added->right    =   nil;
       added->color =   Color::RED;

       //!  @todo
       //insert_fixup(path);
    }
};

}//namespace
#endif // PERSISTENT_RED_BLACK_TREE_HPP
