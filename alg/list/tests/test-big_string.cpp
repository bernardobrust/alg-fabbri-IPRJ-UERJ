/* R. Fabbri, 2024 */
#include "big_string.h"
#include <gtest/gtest.h>
#include <stdlib.h>

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
