cmake_minimum_required(VERSION 3.10)
project(alg)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-g -ggdb3 -fsanitize=address -fno-omit-frame-pointer")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb3 -fsanitize=address -fno-omit-frame-pointer")

# ------------------------------------------------------------------------------
# Benchmark and tests
#
option(alg_BUILD_TESTS "Build alg tests" ON)
option(alg_BUILD_THIRD_PARTY "Build third party" ON)
option(alg_BUILD_BENCHMARKS "Build benchmarks" ON)

if (alg_BUILD_THIRD_PARTY)
  add_subdirectory(third_party)
else(alg_BUILD_THIRD_PARTY)
  if (alg_BUILD_TESTS)
    find_package(GTest REQUIRED)
    include(GoogleTest)
  endif(alg_BUILD_TESTS)
  if (alg_BUILD_BENCHMARKS)
    find_package(benchmark REQUIRED)
  endif(alg_BUILD_BENCHMARKS)
endif(alg_BUILD_THIRD_PARTY)

if (alg_BUILD_TESTS)
  enable_testing()
endif (alg_BUILD_TESTS)
  
# ------------------------------------------------------------------------------
# Add the project's source code.
#
add_subdirectory(alg)

# ------------------------------------------------------------------------------
# Add a 'eval' target to run all bencchmarks
#
get_property(benchmark_targets GLOBAL PROPERTY BENCHMARK_TARGETS)
if(benchmark_targets)
    set(run_commands)
    foreach(target ${benchmark_targets})
        list(APPEND run_commands COMMAND $<TARGET_FILE:${target}>)
    endforeach()

    add_custom_target(eval
        ${run_commands}
        COMMENT "Running all benchmarks"
        VERBATIM
    )
    add_dependencies(eval ${benchmark_targets})
endif()
