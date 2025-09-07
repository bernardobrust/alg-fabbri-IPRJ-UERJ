add_executable(sorted_merge_3way-cmd sorted_merge_3way-cmd.cpp)
add_executable(linked_list_string-cmd linked_list_string-cmd.cpp)
target_link_libraries(sorted_merge_3way-cmd merge)
target_link_libraries(linked_list_string-cmd merge)
