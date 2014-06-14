TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp

HEADERS += \
    queue.hpp \
    stack.hpp \
    deque.hpp \
    queue_by_2stacks.hpp \
    stack_by_2queues.hpp \
    list.hpp \
    circular_list.hpp \
    single_list.hpp \
    stack_by_list.hpp \
    queue_by_list.hpp \
    tree.hpp \
    mergeable_heap.hpp \
    merge_sort_for_list.hpp

