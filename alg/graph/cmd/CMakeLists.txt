add_executable(graph-cmd graph-cmd.cpp)
add_executable(tree-cmd tree-cmd.cpp)

target_link_libraries(graph-cmd graph)
target_link_libraries(tree-cmd graph)