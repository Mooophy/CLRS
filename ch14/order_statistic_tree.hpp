/***************************************************************************
 *  @file       order_statistic_tree.hpp
 *  @author     Alan.W
 *  @date       20  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/

#ifndef ORDER_STATISTIC_TREE_HPP
#define ORDER_STATISTIC_TREE_HPP

#include "red_black_tree.hpp"

namespace ch14 {

template<typename K, typename D>
class OrderStatisticTree : public RedBlackTree<K,D>
{

public:

    using B         =               RedBlackTree<K,D>;
    using NodeType  =   typename    B::NodeType;
    using KeyType   =   typename    B::KeyType;
    using DataType  =   typename    B::DataType;
    using sPointer  =   typename    B::sPointer;

    /**
     * @brief insert
     * @param key
     *
     * just an interface
     */
    virtual void insert(const KeyType& key)
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
    virtual void insert(const KeyType &key, const DataType& data)
    {
        sPointer added = std::make_shared<NodeType>(key,data);
        insert(added);
    }

    virtual ~OrderStatisticTree(){  }

protected:
    virtual void insert(sPointer added)
    {
        sPointer tracker = nil;
        sPointer curr = root;
        while(curr != nil)
        {
            ++curr->size;
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

        //! @todo   add fixup
    }

private:
    using B::root;
    using B::nil;
};
}//namespace


#endif // ORDER_STATISTIC_TREE_HPP
