include(GoogleTest)

add_executable(run-list-tests test-linked_list_string.cpp)
target_link_libraries(run-list-tests PRIVATE list GTest::gtest_main GTest::gtest)

gtest_discover_tests(run-list-tests)