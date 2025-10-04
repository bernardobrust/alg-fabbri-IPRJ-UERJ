add_executable(bm-graph-cmd bm_graph.cpp)
target_link_libraries(bm-graph-cmd graph benchmark::benchmark)
set_property(GLOBAL APPEND PROPERTY BENCHMARK_TARGETS bm-graph-cmd)
