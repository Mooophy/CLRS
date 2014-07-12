TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp

HEADERS += \
    debug.hpp \
    node.hpp \
    redblacktree.hpp \
    persistent_tree.hpp \
    red_black_tree_no_parent.hpp \
    persistent_red_black_tree.hpp \
    red_black_tree_with_bh.hpp

