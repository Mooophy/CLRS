/***************************************************************************
 *  @file       red_black_tree.hpp
 *  @author     Alan.W
 *  @date       18  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/

#ifndef ORDER_STATISTIC_TREE_HPP
#define ORDER_STATISTIC_TREE_HPP

#include <memory>
#include "red_black_tree.hpp"


namespace ch14 {

template<typename K, typename D>
class OrderStatisticTree : public RedBlackTree<K,D>
{
public:
    using B         =               ch14::RedBlackTree<K,D>;
    using KeyType   =   typename    B::KeyType;
    using DataType  =   typename    B::DataType;
    using szNode    =               ch14::NodeSz<K,D>;
    using sPointer  =   typename    B::sPointer;
    using ossPointer=               std::shared_ptr<szNode>;


    OrderStatisticTree():
        B()
    {}

    virtual void insert(const KeyType& key)
    {
        sPointer added = std::make_shared<szNode>(key);
        insert(added);
    }

    virtual void insert(const KeyType &key, const DataType& data)
    {
        sPointer added = std::make_shared<szNode>(key, data);
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

        insert_fixup(added);       
    }

    virtual void insert_fixup(sPointer added)
    {
        //debug:
        std::cout << "outside while of insert_fixup" << std::endl;

        while(ascend(added,1)->color   ==  Color::RED)
        {
            //debug:
            std::cout << "inside while of insert_fixup" << std::endl;

            if(ascend(added,1)->is_left())
            {
                sPointer uncle = ascend(added,2)->right;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color            =   Color::BLACK;
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    added   =   ascend(added,2);
                }
                else
                {
                    if(added->is_right())
                    {
                        added   =   ascend(added,1);
                        left_rotate(added);
                    }
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    right_rotate(ascend(added,2));
                }
            }
            else
            {
                sPointer uncle = ascend(added,2)->left;
                if(uncle->color ==  Color::RED)
                {
                    uncle->color            =   Color::BLACK;
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    added   =   ascend(added,2);
                }
                else
                {
                    if(added->is_left())
                    {
                        added   =   ascend(added,1);
                        right_rotate(added);
                    }
                    ascend(added,1)->color  =   Color::BLACK;
                    ascend(added,2)->color  =   Color::RED;
                    left_rotate(ascend(added,2));
                }
            }
        }
        root->color = Color::BLACK;
    }

    virtual void left_rotate(sPointer x)
    {
        B::left_rotate(x);
        //debug:
        std::cout << debug::green("from D::left_rotate()!!") << std::endl;
    }

    virtual void right_rotate(sPointer y)
    {
        B::right_rotate(y);
        //debug:
        std::cout << "from D::right_rotate()" << std::endl;
    }

private:
    using B::ascend;
    using B::root;
    using B::nil;
};
}//namespace




#endif // ORDER_STATISTIC_TREE_HPP









