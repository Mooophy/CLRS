/***************************************************************************
 *  @file       red_black_tree_no_parent.h
 *  @author     Alan.W
 *  @date       11  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
//!
//! ex13.3-6
//! Suggest how to implement RB-I NSERT efficiently if the representation for red-
//! black trees includes no storage for parent pointers.
//!

#ifndef RED_BLACK_TREE_NO_PARENT_H
#define RED_BLACK_TREE_NO_PARENT_H

#include "node.hpp"
#include "debug.hpp"
#include <vector>
#include <functional>

namespace ch13 {

/**
 * @brief RedBlackTreeNoParent
 *
 * using a vector storing path in stead of parent attribute
 * as required in ex13.3-6
 */
template<typename K,typename D>
class RedBlackTreeNoParent
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
    RedBlackTreeNoParent():
        nil(std::make_shared<NodeType>())
    {
        root = nil;
    }

    /**
     * @brief insert
     * @param key
     * @param data
     *
     * just an interface
     */
    void insert(const KeyType& key, const DataType& data)
    {
        sPointer added = std::make_shared<NodeType>(key,data);
        insert(added);
    }

    /**
     * @brief insert
     * @param key
     *
     * just an interface
     */
    void insert(const KeyType &key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    /**
     * @brief insert
     * @param added
     *
     * @complx  O(lg n)
     *
     * based on the insert method of Red Black Tree
     */
    void insert(sPointer added)
    {
        //! search for the appropriate postion and build the path
        sPointer curr   =   root;
        Vector  path;
        path.push_back(nil);
        while(curr != nil)
        {
            path.push_back(curr);
            curr    =   (curr->key > added->key?   curr->left  :  curr->right);
        }

        //! graft on the new node
        if(root == nil)
            root    =   added;
        else
        {
            sPointer tail   =   path.back();
            (added->key < tail->key?    tail->left  :   tail->right)
                    =   added;
        }
        added->left =   added->right    =   nil;
        added->color=   Color::RED;
        path.push_back(added);

        //! fix up
        insert_fixup(path);
    }

    /**
     * @brief print
     *
     * @complx  O(n)
     */
    void print()const
    {
        std::cout << "-----------------------------\n";
        std::cout << debug::yellow("root= ") << root
                  << " key = " << root->key    << std::endl;

        std::cout << debug::yellow("nil = ") << nil
                  << std::endl;

        std::function<void(sPointer node)> inorder_walk =
                [&inorder_walk,this](sPointer node)
        {
            if(node != nil)
            {
                inorder_walk(node->left);
                node->print();
                inorder_walk(node->right);
            }
        };
        inorder_walk(root);
    }

private:
    sPointer root;
    sPointer nil;

    /**
     * @brief left_rotate
     * @param x
     * @param parent
     *
     * @complx  O(1)
     */
    void left_rotate(sPointer x, sPointer parent)
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
    void right_rotate(sPointer y, sPointer parent)
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
     * as requried in ex13.3-6
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
                        left_rotate(path[curr], path[curr - 1]);
                    }
                    path[curr - 1]->color   =   Color::BLACK;
                    path[curr - 2]->color   =   Color::RED;
                    right_rotate(path[curr - 2], path[curr - 3]);
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
                        right_rotate(path[curr], path[curr - 1]);
                    }
                    path[curr - 1]->color   =   Color::BLACK;
                    path[curr - 2]->color   =   Color::RED;
                    left_rotate(path[curr - 2], path[curr - 3]);
                }
            }
        }
        root->color = Color::BLACK;
    }
};

}//namespace
#endif // RED_BLACK_TREE_NO_PARENT_H

//! code for testing
//#include <iostream>
//#include <vector>
//#include "red_black_tree_no_parent.hpp"

//int main()
//{
//    ch13::RedBlackTreeNoParent<int,std::string> tree;

//    std::vector<int> v = {2,6,7,88,1,55,23};
//    for(auto i : v)
//        tree.insert(i);

//    tree.print();

//    return 0;
//}
