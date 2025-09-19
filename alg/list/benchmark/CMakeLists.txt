add_executable(bm-list-cmd bm_list.cpp)
target_link_libraries(bm-list-cmd list benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-list-cmd)