if (alg_BUILD_TESTS)
  add_subdirectory(googletest)
endif(alg_BUILD_TESTS)

if (alg_BUILD_BENCHMARKS)
  add_subdirectory(benchmark)
endif(alg_BUILD_BENCHMARKS)
