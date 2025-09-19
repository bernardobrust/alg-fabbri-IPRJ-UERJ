add_library(list
  linked_list_string.cpp
)

target_include_directories(list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(cmd)

if (alg_BUILD_TESTS)
  add_subdirectory(tests)
endif()

if (alg_BUILD_BENCHMARKS)
  add_subdirectory(benchmark)
endif()