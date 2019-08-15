project(Data-Structure)
set(CMAKE_CXX_STANDARD 14)

#数据结构1
add_executable(Data.stack "1051 Pop Sequence.cpp")
add_executable(Data.queue "1056 Mice And Rice.cpp")
add_executable(Data.list-reverse "1074 Reversing Linked List.cpp")
add_executable(Data.list-sharing "1032 Sharing.cpp")
add_executable(Data.list-sort "1052 Linked List Sorting.cpp")
add_executable(Data.list-depulication "1097 Deduplication on a Linked List.cpp")

#数据结构2
#二叉树的遍历
add_executable(Data.tree-traversals "1020 Tree Traversals.cpp")
add_executable(Data.tree-traversals-again "1086 Tree Traversals Again.cpp")
add_executable(Data.tree-invert "1102 Invert a Binary Tree.cpp")
#树的遍历
add_executable(Data.total-supply "1079 Total Sales of Supply Chain.cpp")
add_executable(Data.highest-supply "1090 Highest Price in Supply Chain.cpp")
add_executable(Data.largest-supply "1094 The Largest Generation.cpp")
add_executable(Data.lowest-supply "1106 Lowest Price in Supply Chain.cpp")
add_executable(Data.count-leaves "1004 Counting Leaves.cpp")
add_executable(Data.path-ew "1053 Path of Equal Weight.cpp")
#二叉查找树
#平衡二叉树
#并查集
#堆