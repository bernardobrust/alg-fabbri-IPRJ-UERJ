add_library(merge 
  sorted_merge_3way.cpp
  linked_list_string.cpp
)
# export public header path for other components
target_include_directories(merge PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(cmd)

if (alg_BUILD_TESTS)
add_subdirectory(tests)
endif(alg_BUILD_TESTS)

if (alg_BUILD_BENCHMARKS)
add_subdirectory(benchmark)
endif(alg_BUILD_BENCHMARKS)
