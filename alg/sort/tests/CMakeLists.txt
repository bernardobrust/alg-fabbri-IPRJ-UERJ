include(GoogleTest)

add_executable(run-sort-tests test-sort.cpp)
target_link_libraries(run-sort-tests PRIVATE sort GTest::gtest_main GTest::gtest)

gtest_discover_tests(run-sort-tests)
