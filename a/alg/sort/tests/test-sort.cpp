/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include <gtest/gtest.h>
#include "sort.h"
#include <cstring>
#include <vector>

class SortTest : public ::testing::TestWithParam<void (*)(char**, int)> {
protected:
    void SetUp() override {
        data.push_back((char*)"banana");
        data.push_back((char*)"apple");
        data.push_back((char*)"cherry");

        expected.push_back((char*)"apple");
        expected.push_back((char*)"banana");
        expected.push_back((char*)"cherry");
    }

    std::vector<char*> data;
    std::vector<char*> expected;
};

TEST_P(SortTest, BasicSort) {
    auto sort_func = GetParam();
    sort_func(data.data(), data.size());
    for (size_t i = 0; i < data.size(); ++i) {
        EXPECT_STREQ(data[i], expected[i]);
    }
}

TEST_P(SortTest, EmptyList) {
    auto sort_func = GetParam();
    char** empty_data = nullptr;
    sort_func(empty_data, 0);
    // No crash is a pass
}

TEST_P(SortTest, AlreadySorted) {
    auto sort_func = GetParam();
    simple_sort(expected.data(), expected.size()); // ensure expected is sorted by a known good sort
    sort_func(expected.data(), expected.size());
    std::vector<char*> sorted_expected = {(char*)"apple", (char*)"banana", (char*)"cherry"};
    for (size_t i = 0; i < expected.size(); ++i) {
        EXPECT_STREQ(expected[i], sorted_expected[i]);
    }
}

INSTANTIATE_TEST_SUITE_P(
    SortImplementations,
    SortTest,
    ::testing::Values(&simple_sort, &fast_sort)
);

