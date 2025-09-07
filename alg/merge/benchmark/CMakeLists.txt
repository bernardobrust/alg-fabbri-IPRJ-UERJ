add_executable(bm-sorted_merge_3way-cmd bm_sorted_merge_3way.cpp)
target_link_libraries(bm-sorted_merge_3way-cmd merge benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-sorted_merge_3way-cmd)
