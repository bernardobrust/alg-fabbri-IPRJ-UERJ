/* R. Fabbri, 2024 */
#include "big_string.h"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <string> // For std::string
#include <random> // For random number generation
#include <chrono> // For seeding random number generator

// Helper function to convert BigString to std::string
std::string BigStringToString(const BigString& bs) {
    std::string result = "";
    for (unsigned int i = 0; i < bs.get_char_size(); ++i) {
        result += bs[i];
    }
    return result;
}

TEST (BigStringTest, Constructor)
{
  char *data = (char *)"test";
  BigString bs (data);
  EXPECT_EQ (bs.get_char_size (), 4);
  EXPECT_EQ (bs.get_size (), 1);
  EXPECT_EQ (bs[0], 't');
  EXPECT_EQ (bs[3], 't');
}

TEST (BigStringTest, Insert)
{
  BigString bs;
  bs.insert (0, (char *)"world");
  bs.insert (0, (char *)"Hello ");
  bs.insert (1, (char *)"beautiful ");

  EXPECT_EQ (bs.get_char_size (), 21);
  EXPECT_EQ (bs.get_size (), 3);
}

TEST (BigStringTest, OperatorOverload)
{
  BigString bs;
  bs.insert (0, (char *)"Hello");
  bs.insert (1, (char *)" ");
  bs.insert (2, (char *)"world");
  bs.insert (3, (char *)"!");

  EXPECT_EQ (bs[0], 'H');
  EXPECT_EQ (bs[4], 'o');
  EXPECT_EQ (bs[5], ' ');
  EXPECT_EQ (bs[6], 'w');
  EXPECT_EQ (bs[10], 'd');
  EXPECT_EQ (bs[11], '!');
}

TEST (BigStringTest, Remove)
{
  BigString bs;
  bs.insert (0, (char *)"Hello");
  bs.insert (1, (char *)" ");
  bs.insert (2, (char *)"beautiful");
  bs.insert (3, (char *)" ");
  bs.insert (4, (char *)"world");

  // "Hello beautiful world"
  // remove "beautiful"
  bs.remove (2);
  // "Hello  world"

  EXPECT_EQ (bs.get_char_size (), 12);
  EXPECT_EQ (bs.get_size (), 4);
  EXPECT_EQ (bs[5], ' ');
  EXPECT_EQ (bs[6], ' ');

  // remove "Hello"
  bs.remove (0);
  // "  world"
  EXPECT_EQ (bs.get_char_size (), 7);
  EXPECT_EQ (bs.get_size (), 3);
  EXPECT_EQ (bs[0], ' ');
  EXPECT_EQ (bs[1], ' ');
  EXPECT_EQ (bs[2], 'w');

  // remove "world"
  bs.remove (2);
  // " "
  EXPECT_EQ (bs.get_char_size (), 2);
  EXPECT_EQ (bs.get_size (), 2);
}

TEST (BigStringTest, InsertAndRemove)
{
  BigString bs;
  bs.insert (0, (char *)"a");
  bs.insert (1, (char *)"b");
  bs.insert (2, (char *)"c");

  EXPECT_EQ (bs[0], 'a');
  EXPECT_EQ (bs[1], 'b');
  EXPECT_EQ (bs[2], 'c');

  bs.remove (1); // remove "b"
  EXPECT_EQ (bs[0], 'a');
  EXPECT_EQ (bs[1], 'c');

  bs.insert (1, (char *)"d"); // "adc"
  EXPECT_EQ (bs[0], 'a');
  EXPECT_EQ (bs[1], 'd');
  EXPECT_EQ (bs[2], 'c');
}

TEST (BigStringTest, GetHeadAndTail)
{
  BigString bs;
  EXPECT_EQ (bs.get_head (), nullptr);
  EXPECT_EQ (bs.get_tail (), nullptr);

  bs.insert (0, (char *)"Hello");
  EXPECT_NE (bs.get_head (), nullptr);
  EXPECT_EQ (bs.get_head (), bs.get_tail ());
  EXPECT_STREQ ((char *)bs.get_head ()->name, "Hello");

  bs.insert (1, (char *)"World");
  EXPECT_NE (bs.get_head (), bs.get_tail ());
  EXPECT_STREQ ((char *)bs.get_head ()->name, "Hello");
  EXPECT_STREQ ((char *)bs.get_tail ()->name, "World");

  bs.insert (0, (char *)"Prefix ");
  EXPECT_STREQ ((char *)bs.get_head ()->name, "Prefix ");
  EXPECT_STREQ ((char *)bs.get_tail ()->name, "World");
}

TEST (BigStringTest, Concat)
{
  BigString bs1;
  bs1.insert (0, (char *)"Hello ");
  bs1.insert (1, (char *)"beautiful ");

  BigString bs2;
  bs2.insert (0, (char *)"world");
  bs2.insert (1, (char *)"!");

  bs1.concat (bs2);

  EXPECT_EQ (bs1.get_size (), 4);
  EXPECT_EQ (bs1.get_char_size (), 22);
  EXPECT_EQ (bs1[0], 'H');
  EXPECT_EQ (bs1[16], 'w');
  EXPECT_EQ (bs1[21], '!');

  // Check that bs2 is empty
  EXPECT_EQ (bs2.get_size (), 0);
  EXPECT_EQ (bs2.get_char_size (), 0);
  EXPECT_EQ (bs2.get_head (), nullptr);
  EXPECT_EQ (bs2.get_tail (), nullptr);
}

TEST (BigStringTest, InsertBigString)
{
  // Insert in the middle
  BigString bs1;
  bs1.insert (0, (char *)"Hello ");
  bs1.insert (1, (char *)"world");

  BigString bs2;
  bs2.insert (0, (char *)"beautiful ");

  bs1.insert_big_string (bs2, 1);

  EXPECT_EQ (bs1.get_size (), 3);
  EXPECT_EQ (bs1.get_char_size (), 21);
  EXPECT_EQ (bs1[0], 'H');     // Hello
  EXPECT_EQ (bs1[6], 'b');     // beautiful
  EXPECT_EQ (bs1[16], 'w');    // world

  // Check that bs2 is empty
  EXPECT_EQ (bs2.get_size (), 0);
  EXPECT_EQ (bs2.get_char_size (), 0);

  // Insert at the beginning
  BigString bs3;
  bs3.insert (0, (char *)"world");
  BigString bs4;
  bs4.insert (0, (char *)"Hello ");
  bs3.insert_big_string (bs4, 0);
  EXPECT_EQ (bs3.get_size (), 2);
  EXPECT_EQ (bs3.get_char_size (), 11);
  EXPECT_EQ (bs3[0], 'H');
  EXPECT_EQ (bs3[6], 'w');

  // Insert at the end
  BigString bs5;
  bs5.insert (0, (char *)"Hello ");
  BigString bs6;
  bs6.insert (0, (char *)"world");
  bs5.insert_big_string (bs6, 1);
  EXPECT_EQ (bs5.get_size (), 2);
  EXPECT_EQ (bs5.get_char_size (), 11);
  EXPECT_EQ (bs5[0], 'H');
  EXPECT_EQ (bs5[6], 'w');
}

TEST (BigStringTest, InsertBigStringAt)
{
  BigString bs1;
  bs1.insert (0, (char *)"HelloWorld"); // "HelloWorld"

  BigString bs2;
  bs2.insert (0, (char *)" ");
  bs2.insert (1, (char *)"beautiful");
  bs2.insert (2, (char *)" "); // " beautiful "

  // Insert " beautiful " at index 5 (after "Hello")
  bs1.insert_big_string_at (bs2, 5); // "Hello beautiful World"

  EXPECT_EQ (bs1.get_char_size (), 21);
  EXPECT_EQ (bs1.get_size (), 5);
  EXPECT_STREQ ((char *)bs1.get_head ()->name, "Hello");
  EXPECT_STREQ ((char *)bs1.get_head ()->next->name, " ");
  EXPECT_STREQ ((char *)bs1.get_head ()->next->next->name, "beautiful");
  EXPECT_STREQ ((char *)bs1.get_head ()->next->next->next->name, " ");
  EXPECT_STREQ ((char *)bs1.get_head ()->next->next->next->next->name, "World");

  EXPECT_EQ (bs1[0], 'H');
  EXPECT_EQ (bs1[4], 'o');
  EXPECT_EQ (bs1[5], ' ');
  EXPECT_EQ (bs1[6], 'b');
  EXPECT_EQ (bs1[14], 'l');
  EXPECT_EQ (bs1[15], ' ');
  EXPECT_EQ (bs1[16], 'W');
  EXPECT_EQ (bs1[20], 'd');

  // Check that bs2 is empty
  EXPECT_EQ (bs2.get_size (), 0);
  EXPECT_EQ (bs2.get_char_size (), 0);
  EXPECT_EQ (bs2.get_head (), nullptr);
  EXPECT_EQ (bs2.get_tail (), nullptr);

  // Insert at the beginning
  BigString bs3;
  bs3.insert (0, (char *)"world");
  BigString bs4;
  bs4.insert (0, (char *)"Hello ");
  bs3.insert_big_string_at (bs4, 0);
  EXPECT_EQ (bs3.get_char_size (), 11);
  EXPECT_STREQ ((char *)bs3.get_head ()->name, "Hello ");
  EXPECT_STREQ ((char *)bs3.get_head ()->next->name, "world");

  // Insert at the end
  BigString bs5;
  bs5.insert (0, (char *)"Hello ");
  BigString bs6;
  bs6.insert (0, (char *)"world");
  bs5.insert_big_string_at (bs6, 6);
  EXPECT_EQ (bs5.get_char_size (), 11);
  EXPECT_STREQ ((char *)bs5.get_head ()->name, "Hello ");
  EXPECT_STREQ ((char *)bs5.get_head ()->next->name, "world");

  // Insert into an empty BigString
  BigString bs7;
  BigString bs8;
  bs8.insert (0, (char *)"Test");
  bs7.insert_big_string_at (bs8, 0);
  EXPECT_EQ (bs7.get_char_size (), 4);
  EXPECT_STREQ ((char *)bs7.get_head ()->name, "Test");

  // Insert at a position that splits a string
  BigString bs9;
  bs9.insert (0, (char *)"ABCDEF"); // "ABCDEF"
  BigString bs10;
  bs10.insert (0, (char *)"123"); // "123"
  bs9.insert_big_string_at (bs10, 3); // "ABC123DEF"
  EXPECT_EQ (bs9.get_char_size (), 9);
  EXPECT_STREQ ((char *)bs9.get_head ()->name, "ABC");
  EXPECT_STREQ ((char *)bs9.get_head ()->next->name, "123");
  EXPECT_STREQ ((char *)bs9.get_head ()->next->next->name, "DEF");
}

// Stress tests
TEST(BigStringStressTest, RandomInsertionsAndConcatenations) {
    BigString bs;
    std::string reference_str = "";

    // Use a fixed seed for reproducibility
    std::mt19937 gen(0);

    auto generate_random_string = [&](int max_len) {
        std::string s = "";
        int len = std::uniform_int_distribution<>(1, max_len)(gen);
        for (int i = 0; i < len; ++i) {
            s += (char)std::uniform_int_distribution<>('a', 'z')(gen);
        }
        return s;
    };

    // Initial state
    std::string initial_str = generate_random_string(10);
    bs.insert(0, (char*)initial_str.c_str());
    reference_str += initial_str;

    for (int i = 0; i < 100; ++i) {
        int operation_type = std::uniform_int_distribution<>(0, 1)(gen); // 0 for insert_big_string_at, 1 for concat

        if (operation_type == 0) { // insert_big_string_at
            std::string to_insert_str = generate_random_string(5);
            BigString to_insert_bs;
            to_insert_bs.insert(0, (char*)to_insert_str.c_str());

            unsigned int insert_pos = 0;
            if (reference_str.length() > 0) {
                insert_pos = std::uniform_int_distribution<>(0, reference_str.length())(gen);
            }

            bs.insert_big_string_at(to_insert_bs, insert_pos);
            reference_str.insert(insert_pos, to_insert_str);
        } else { // concat
            std::string to_concat_str = generate_random_string(7);
            BigString to_concat_bs;
            to_concat_bs.insert(0, (char*)to_concat_str.c_str());

            bs.concat(to_concat_bs);
            reference_str += to_concat_str;
        }

        // Verify after each operation
        EXPECT_EQ(BigStringToString(bs), reference_str);
        EXPECT_EQ(bs.get_char_size(), reference_str.length());
    }
}
