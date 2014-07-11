/***************************************************************************
 *  @file       redblacktree.hpp
 *  @author     Yue Wang
 *  @date       09  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
//!
//! Problem 13-1
//! a. For a general persistent binary search tree, identify the nodes that we need to
//! change to insert a key k or delete a node y
//  For k, nodes on the path to search for it need to be changed.
//  For y, when less than 2 children, same as k. when 2 children nodes on path to search
//  for y's replacer need to be changed.
//!
//! b.  Write a procedure P ERSISTENT -T REE -I NSERT that, given a persistent tree T
//! and a key k to insert, returns a new persistent tree T 0 that is the result of insert-
//! ing k into T .
//!
//  Shown as the class PersistentTree below
//!
//! c.  If the height of the persistent binary search tree T is h, what are the time and
//! space requirements of your implementation of PERSISTENT-TREE-INSERT()
//! (The space requirement is proportional to the number of new nodes allocated.)
//!
//      time complexity     :   O(h)
//      space complexity    :   O(h)
//!
//! d.  Suppose that we had included the parent attribute in each node. In this case,
//! PERSISTENT-TREE-INSERT would need to perform additional copying. Prove
//! that PERSISTENT-TREE-INSERT would then require omega(n) time and space,
//! where n is the number of nodes in the tree.
//!
//  It implies that all nodes have to copy to build a new tree, otherwise some nodes would have
//  multiple parents
//!

#ifndef PERSISTENT_TREE_HPP
#define PERSISTENT_TREE_HPP

#include "node.hpp"
#include "debug.hpp"
#include <vector>
#include <functional>

namespace ch13 {

/**
 * @brief PersistentTree
 *
 * the Binary Search Tree version
 */
template<typename K, typename D>
class PersistentTree
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using NodeType  =   Node<K,D>;
    using sPointer  =   std::shared_ptr<NodeType>;
    using wPointer  =   std::weak_ptr<NodeType>;
    using Vector    =   std::vector<sPointer>;

    /**
     * @brief insert
     * @param key
     * @param data
     *
     * @complx  O(lg n)
     * overloaded as an interface
     */
    void insert(const KeyType &key, const DataType &data)
    {
        sPointer added = std::make_shared<NodeType>(key,data);
        insert(added);
    }

    /**
     * @brief insert
     * @param key
     *
     * @complx  O(lg n)
     * overloaded as an interface
     */
    void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    /**
     * @brief empty
     */
    bool empty()const
    {
        return versions.empty();
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


    /**
     * @brief insert
     * @param added
     *
     * @complx  O(lg n)
     *
     * @page    332 ,   i.e. Problem 13-1.b
     */
    void insert(sPointer added)
    {
        if(versions.empty())
            versions.push_back(added);
        else
        {
            sPointer old_curr = versions.back();
            sPointer new_root = std::make_shared<NodeType>(*versions.back());
            versions.push_back(new_root);
            sPointer new_curr = new_root;

            while(true)
            {
                if(old_curr->key    <   added->key)
                {
                    new_curr->left  =   old_curr->left;
                    if(old_curr->right)
                    {
                        new_curr->right =
                                std::make_shared<NodeType>(*old_curr->right);
                        new_curr    =   new_curr->right;
                        old_curr    =   old_curr->right;
                    }
                    else
                        break;
                }
                else
                {
                    new_curr->right =   old_curr->right;
                    if(old_curr->left)
                    {
                        new_curr->left  =
                                std::make_shared<NodeType>(*old_curr->left);
                        new_curr    =   new_curr->left;
                        old_curr    =   old_curr->left;
                    }
                    else
                        break;
                }
            }

            //! graft on the inserted node
            (new_curr->key < added->key?   new_curr->right  :   new_curr->left)
                    =   added;
        }
    }
};//class persistent tree

}//namespace
#endif // PERSISTENT_TREE_HPP


//! testing insert i.e.part b
//#include <iostream>
//#include <vector>
//#include "persistent_tree.hpp"

//int main()
//{
//    ch13::PersistentTree<int, std::string> tree;

//    tree.insert(1,"001");
//    tree.insert(2);
//    tree.insert(3);
//    tree.insert(0);

//    tree.print();

//    std::cout << "\nend" << std::endl;

//    return 0;
//}
