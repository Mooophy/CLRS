/***************************************************************************
 *  @file       persistent_red_black_tree.hpp
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
//  as implemented below, the red black tree guarantee that only the searching path is
//  needed,which means that O(lg n) is the worst-case time and space requirement.
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

    /**
     * @brief default Ctor
     */
    PersistentRedBlackTree():
        nil(std::make_shared<NodeType>(12345))
    {}

    /**
     * @brief empty
     */
    bool empty()const
    {
        return versions.empty();
    }

    /**
     * @brief insert
     * @param key
     *
     * just an interface
     */
    void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    /**
     * @brief insert
     * @param key
     * @param data
     *
     * just an interface
     */
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
            if(node != nil)
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

    /**
     * @brief insert
     * @param added
     *
     * @complx  O(lg n)
     */
    void insert(sPointer added)
    {
       //!  initial case
       if(empty())
       {           
           added->left  =   added->right    =   nil;
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

       //!  fixup
       insert_fixup(path);
    }

    /**
     * @brief left_rotate
     * @param x
     * @param parent
     *
     * @complx  O(1)
     */
    void left_rotate(sPointer x, sPointer parent, sPointer root)
    {
        sPointer y  =   x->right;
        x->right    =   y->left;

        if(parent   ==  nil)
            root    =   y;
        else
            (x == parent->left?     parent->left    :   parent->right)
                    =   y;

        y->left     =   x;
    }

    /**
     * @brief right_rotate
     * @param y
     * @param parent
     *
     * @complx  O(1)
     */
    void right_rotate(sPointer y, sPointer parent, sPointer root)
    {
        sPointer x  =   y->left;
        y->left     =   x->right;

        if(parent   ==  nil)
            root    =   x;
        else
            (y == parent->left?     parent->left    :   parent->right)
                    =   x;

        x->right    =   y;
    }

    /**
     * @brief insert_fixup
     * @param path
     *
     * @complx  O(lg n)
     * using path vector instead of parent attribute
     */
    void insert_fixup(const Vector& path)
    {
        auto curr   =   path.size() - 1;
        while(path[curr-1]->color   ==  Color::RED)
        {
            if(path[curr - 1]   ==  path[curr - 2]->left)
            {
                sPointer uncle  =   path[curr - 2]->right;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color            =   Color::BLACK;
                    path[curr - 1]->color   =   Color::BLACK;
                    path[curr - 2]->color   =   Color::RED;
                    curr -=  2;
                }
                else
                {
                    if(path[curr] == path[curr - 1]->right)
                    {
                        --curr;
                        left_rotate(path[curr], path[curr - 1], path[1]);
                    }
                    path[curr - 1]->color   =   Color::BLACK;
                    path[curr - 2]->color   =   Color::RED;
                    right_rotate(path[curr - 2], path[curr - 3], path[1]);
                }
            }
            else
            {
                sPointer uncle  =   path[curr - 2]->left;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color            =   Color::BLACK;
                    path[curr - 1]->color   =   Color::BLACK;
                    path[curr - 2]->color   =   Color::RED;
                    curr -=  2;
                }
                else
                {
                    if(path[curr] == path[curr - 1]->left)
                    {
                        --curr;
                        right_rotate(path[curr], path[curr - 1], path[1]);
                    }
                    path[curr - 1]->color   =   Color::BLACK;
                    path[curr - 2]->color   =   Color::RED;
                    left_rotate(path[curr - 2], path[curr - 3], path[1]);
                }
            }
        }
        path[1]->color = Color::BLACK;
    }
};//class

}//namespace
#endif // PERSISTENT_RED_BLACK_TREE_HPP

//! code for testing prblem 13-1.e
//#include <iostream>
//#include <vector>
//#include "persistent_red_black_tree.hpp"

//int main()
//{
//    ch13::PersistentRedBlackTree<int, std::string> tree;
//    std::vector<int> v = {3,2,6,7,4,9,8};
//    for(auto i : v)
//        tree.insert(i);

//    tree.print();
//    std::cout << debug::green("\nend") << std::endl;

//    return 0;
//}
