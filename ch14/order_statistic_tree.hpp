/***************************************************************************
 *  @file       order_statistic_tree.hpp
 *  @author     Alan.W
 *  @date       20  July 2014
 *  @remark     Implementation of CLRS algorithms, using C++ templates.
 ***************************************************************************/
//!
//! ex14.1-3
//!     Write a nonrecursive version of OS-SELECT .
//!
//  as select_nonrecur shows.
//!
//! ex14.1-4
//!     Write a recursive procedure OS-KEY-RANK(T,k) that takes as input an order-
//!     statistic tree T and a key k and returns the rank of k in the dynamic set represented
//!     by T . Assume that the keys of T are distinct.
//!
//  as find_rank_with_key() shows
//!
//! ex14.1-5
//!     Given an element x in an n-node order-statistic tree and a natural number i, how
//!     can we determine the ith successor of x in the linear order of the tree in O(lg n)
//!     time?
//!
//  check below for implementation
//!
//! ex14.1-7
//!     Show how to use an order-statistic tree to count the number of inversions (see
//!     Problem 2-4) in an array of size n in time O(n lg n)
//!
//  use insert and accumulate (count - find_rank_with_key(key)),
//  as the function:
//              find_inversions() shows
//
//!


#ifndef ORDER_STATISTIC_TREE_HPP
#define ORDER_STATISTIC_TREE_HPP

#include <memory>
#include <vector>
#include "red_black_tree.hpp"

namespace ch14 {

template<typename K, typename D = int>
std::size_t
find_inversions(const std::vector<K>& v);

/**
 * @brief The OrderStatisticTree class
 *
 * inherited from Red Black Tree
 */
template<typename K, typename D>
class OrderStatisticTree : public RedBlackTree<K,D>
{
private:
    using B         =               RedBlackTree<K,D>;
    using KeyType   =   typename    B::KeyType;
    using sPointer  =   typename    B::sPointer;
    using SizeType  =               std::size_t;

public:
    using B::insert;
//! ^^^^^^^^^^^^^^^ -- needed to call this virtual function from base class

    /**
     * @brief select
     *
     * @complx  O(lg n)
     *
     * @page    341
     */
    sPointer select(sPointer target, SizeType rank)
    {
        //! must be within the range.
        assert(rank <= target->size + 1);

        SizeType curr    =   target->rank();
        if(rank == curr)
            return target;
        else
            return rank < curr?
                        select(target->left,rank)
                            :   select(target->right, rank - curr);
    }

    /**
     * @brief select_nonrecur
     *
     * @complx  O(lg n)
     *
     * ex14-1.3
     */
    sPointer select_nonrecur(sPointer target, SizeType rank)
    {
        //! must be within the range.
        assert(rank <= target->size + 1);

        SizeType r = target->rank();
        while(r != rank)
        {
            if(rank < r)
                target  =   target->left;
            else
            {
                target  =   target->right;
                rank    -=  r;
            }
            r   =   target->rank();
        }

        return target;
    }

    /**
     * @brief rank
     *          return the rank within the whole tree
     *
     * @complx  O(lg n)
     *
     * @page    342
     */
    SizeType rank(sPointer target)
    {
        SizeType ret    =   target->rank();
        sPointer curr   =   target;
        while(curr != root)
        {
            if(curr->is_right())
                ret +=  sibling(curr)->size +   1;
            curr    =   curr->parent.lock();
        }

        return ret;
    }

    /**
     * @brief find_rank_with_key
     * @param key
     * @return the rank looked for
     *
     * @complx  O(lg n)
     *
     * as required in ex14-1.4
     */
    SizeType find_rank_with_key(const KeyType& key) const
    {
        //! define a lambda to do the job recursively
        std::function<SizeType(sPointer)> find_by_recur=
            [&](sPointer curr)
        {
            assert(curr != nil);
            assert(curr != nullptr);

            //! search for the node with the key specified
            //! and count the rank simultaneously.
            if(curr->key == key)
                return curr->rank();
            else
                return curr->key > key?
                            find_by_recur(curr->left)
                            :   find_by_recur(curr->right)  +   curr->rank();

        };

        //! call the lambda
        return find_by_recur(root);
    }

    /**
     * @brief find_ith_successor
     * @param target
     * @param ith
     *
     * @complx  O(lg n)
     *
     * for ex14.1-5
     */
    sPointer find_ith_successor(sPointer target, SizeType ith)
    {

        if(ith  ==  0)
            return target;
        else
        {
            if(ith <= target->right->size)
                return select(target->right,ith);
            else
            {
                ith -=  target->right->size;

                sPointer trackor;
                do{
                    trackor =   target;
                    target  =   target->parent.lock();
                }while(trackor->is_right());
                --ith;

                return find_ith_successor(target,ith);
            }
        }
    }


    //! Dtor
    virtual ~OrderStatisticTree(){  }

private:
    using B::root;
    using B::nil;
    using B::ascend;
    using B::sibling;
    using B::insert_fixup;

    /**
     * @brief left_rotate
     * @param x
     *
     * @attention   virtual!
     *
     * @complx  O(1)
     *
     * based on the pseudocode P343
     */
    virtual void left_rotate(sPointer x) override
    {
        B::left_rotate(x);

        sPointer parent =   x->parent.lock();
        parent->size    =   x->size;
        x->size         =   x->left->size   +   x->right->size  +   1;
    }

    /**
     * @brief right_rotate
     * @param y
     *
     * @attention   virtual!
     *
     * @complx  O(1)
     */
    virtual void right_rotate(sPointer y) override
    {
        B::right_rotate(y);

        sPointer parent =   y->parent.lock();
        parent->size    =   y->size;
        y->size         =   y->left->size   +   y->right->size  +   1;
    }

    /**
     * @brief insert
     * @param added
     *
     * @attention   virtual!
     *
     * @complx  O(h)
     */
    virtual void insert(sPointer added) override
    {
        added->size =   1;	//The new node added gets a size of 1.(P343)

        sPointer tracker = nil;
        sPointer curr = root;
        while(curr != nil)
        {
            ++curr->size;
       //!  ^^^^^^^^^^^^^   --  added for o s tree

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

        //! fixup
        insert_fixup(added);
    }
};

/**
 * @brief find_inversions
 * @param vector
 *
 * @complx  O(n lg n)
 *
 * for ex14-1.7
 */
template<typename K, typename D>
inline std::size_t
find_inversions(const std::vector<K>& v)
{
    //! types def and initialization
    using OsTree    =   ch14::OrderStatisticTree<K,D>;
    using Tree      =   std::shared_ptr<OsTree>;
    Tree tree = std::make_shared<OsTree>();
    std::size_t count, inversions;
    count   =   inversions  =   0;

    //! counting inversions
    for(const auto& key :   v)                                  //  O(n)
    {
        tree->insert(key);
        std::size_t rank    =   tree->find_rank_with_key(key);  //  O(lg n)
        inversions  +=  ++count - rank;
    }

    return inversions;
}

}//namespace



#endif // ORDER_STATISTIC_TREE_HPP

//! for testing insert and remove
//#include <iostream>
//#include <string>
//#include <memory>
//#include <vector>
//#include "red_black_tree.hpp"
//#include "order_statistic_tree.hpp"

//int main()
//{
//    ch14::RedBlackTree<int, std::string>*
//            tree =
//                new ch14::OrderStatisticTree<int, std::string>;

//    std::vector<int> v = {3,4,1,5,6,2,7,0,10,65,23};
//    for(auto i : v)
//       tree->insert(i);

//    std::cout << debug::red("deleting!!:\n");
//    tree->remove(tree->search(4));

//    tree->print();

//    std::cout << debug::green("\nend\n");
//    delete tree;
//    return 0;
//}

//! for testing select()
//#include <iostream>
//#include <string>
//#include <memory>
//#include <vector>
//#include "red_black_tree.hpp"
//#include "order_statistic_tree.hpp"

//int main()
//{
//    auto tree = new ch14::OrderStatisticTree<int, std::string>;
//    std::vector<int> v = {11,22,33,44,55,66,77,88};
//    for(auto i : v)
//       tree->insert(i);
//    tree->print();

//    std::cout << debug::red("testing select:\n");
//    auto node   =   tree->search(44);
//    auto ret    =   tree->select(node,7);
//    ret->print();

//    delete tree;
//    std::cout << debug::green("\nend\n");
//    return 0;
//}

//! testing rank()
//#include <iostream>
//#include <string>
//#include <memory>
//#include <vector>
//#include "red_black_tree.hpp"
//#include "order_statistic_tree.hpp"

//int main()
//{
//    using Tree  =   ch14::OrderStatisticTree<int, std::string>;

//    Tree* tree = new Tree;
//    std::vector<int> v = {11,22,33,44,55,66,77,88};
//    for(auto i : v)
//       tree->insert(i);
//    tree->print();

//    std::cout << debug::red("\ntesting rank:\n");
//    auto node   =   tree->search(88);
//    std::cout << debug::green("the rank is: ");
//    std::cout << tree->rank(node) << std::endl;

//    delete tree;
//    std::cout << debug::green("\nend\n");
//    return 0;
//}

//! for testing select_nonrecur required in ex14-1.3
//#include <iostream>
//#include <string>
//#include <vector>
//#include "order_statistic_tree.hpp"

//int main()
//{
//    auto tree = new ch14::OrderStatisticTree<int, std::string>;
//    std::vector<int> v = {11,22,33,44,55,66,77,88};
//    for(auto i : v)
//       tree->insert(i);
//    tree->print();

//    std::cout << debug::red("testing select_nonrecur:\n");
//    auto node   =   tree->search(44);
//    auto ret    =   tree->select_nonrecur(node,7);
//    ret->print();

//    delete tree;
//    std::cout << debug::green("\nend\n");
//    return 0;
//}

//! for testing find_rank_with_key()
//! ex14.1-4
//#include <iostream>
//#include <string>
//#include <vector>
//#include "order_statistic_tree.hpp"

//int main()
//{
//    auto tree = new ch14::OrderStatisticTree<int, std::string>;
//    std::vector<int> v = {11,22,33,44,55,66,77,88};
//    for(auto i : v)
//       tree->insert(i);
//    tree->print();


//    std::cout   <<  debug::green("\ntesting find_rank_with_key(), as required in ex14.1-4:\nrank=")
//                <<  tree->find_rank_with_key(44) << std::endl;


//    delete tree;
//    std::cout << debug::green("\nend\n");
//    return 0;
//}

//! for testing find_ith_successor()
//! ex14.1-5
//#include <iostream>
//#include <string>
//#include <vector>
//#include "order_statistic_tree.hpp"

//int main()
//{
//    auto tree = new ch14::OrderStatisticTree<int, std::string>;
//    std::vector<int> v = {41,38,31,12,19,8};
//    for(auto i : v)
//       tree->insert(i);
//    tree->print();


//    std::cout   <<
//            debug::red("\ntesting find_ith_successor(), as required in ex14.1-5:\n");
//    auto node   =   tree->search(38);
//    auto ret    =   tree->find_ith_successor(node,1);
//    ret->print();


//    delete tree;
//    std::cout << debug::green("\nend\n");
//    return 0;
//}

//! for testing ex14-1.7
//#include <iostream>
//#include <string>
//#include <vector>
//#include "order_statistic_tree.hpp"

//int main()
//{
//    std::vector<int> v = {41,38,31,12,19,8};

//    std::cout << "testing find inversions for ex14.1-7:\ninversions=";
//    std::cout << ch14::find_inversions(v) << std::endl;

//    std::cout << debug::green("\nend\n");
//    return 0;
//}
