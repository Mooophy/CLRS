#include <iostream>
#include <vector>
#include <memory>
#include <boost/numeric/ublas/io.hpp>
#include "alan.hpp"
#include "color.hpp"
#include "node.hpp"
#include "matrix.hpp"
#include "optimal_bst.hpp"

int main()
{
    using namespace ch15::sec5;
    using NodeType  =   Node<std::string, std::string>;
    using Table     =   ch15::Matrix<std::size_t>;
    using Range     =   std::vector<NodeType>;

    //!
    Range range =
    {
        NodeType("day"  , "jour"    ),
        NodeType("enter", "entrer"  ),
        NodeType("front", "avant"   ),
        NodeType("game" , "jeu"     ),
        NodeType("hope" , "espoir"  )
    };

    alan::print_container(range);

    //! build a table like that on  Page 403, figure15.10, CLRS.
    Table table(5,5);
    table <<= std::vector<size_t>
            ({
                 2,4,5,5,5,
                 2,2,4,4,0,
                 2,2,3,0,0,
                 1,2,0,0,0,
                 1,0,0,0,0
             });

    ch15::print(table);

    //! build the optimal bst
    using Tree      =   OptimalBsTree<NodeType, Range>;
    Tree tree(table,range);



    std::cout << color::red("\nend\n");
    return 0;
}
