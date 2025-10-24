add_library(graph
  graph.cpp
  tree.cpp
  dynagraph.c
  oopdynagraph.cpp
)
# export public header path for other components
target_include_directories(graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(dynagraph-cmd dynagraph.c)
add_executable(oopdynagraph-cmd oopdynagraph.cpp)
add_subdirectory(cmd)

if (alg_BUILD_TESTS)
add_subdirectory(tests)
endif(alg_BUILD_TESTS)

if (alg_BUILD_BENCHMARKS)
add_subdirectory(benchmark)
endif(alg_BUILD_BENCHMARKS)
