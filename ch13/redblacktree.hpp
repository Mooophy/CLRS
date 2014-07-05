/***************************************************************************
 *  @file       redblacktree.hpp
 *  @author     Alan.W
 *  @date       05  July 2014
 *  @remark     Algorithims implementation for CLRS, using C++ templates.
 ***************************************************************************/
#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include <memory>
#include <functional>
#include "node.hpp"


namespace ch13{

/**
 * @brief The RedBlackTree class
 */
template<typename K, typename D>
class RedBlackTree
{
public:
    using KeyType   =   K;
    using DataType  =   D;
    using NodeType  =   Node<K,D>;
    using sPointer  =   std::shared_ptr<NodeType>;
    using wPointer  =   std::weak_ptr<NodeType>;

    RedBlackTree():
        nil(std::make_shared<NodeType>())
    {
        root = nil;
    }

    /**
     * @brief print
     *
     * O(n)
     */
    void print()const
    {
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

    /**
     * @brief insert
     * @param key
     *
     * O(h)
     */
    void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<NodeType>(key);
        insert(added);
    }

    /**
     * @brief insert
     * @param added
     *
     * O(h)
     */
    void insert(sPointer added)
    {
        sPointer tracker = nil;
        sPointer curr = root;
        while(curr != nil)
        {
            tracker =   curr;
            curr    =   curr->key > added->key?     curr->left  :   curr->right;
        }

        added->parent   =   tracker;
        if(tracker == nil)
            root    =   added;
        else
            (added->key < tracker->key?     tracker->left   :   tracker->right)
                    =   added;

        added->left =   added->right    =   nil;
        added->color=   Color::RED;

        //--to do   :   add fixup
    }
private:
    sPointer root;
    sPointer nil;
};
}//namespace


#endif // REDBLACKTREE_HPP
