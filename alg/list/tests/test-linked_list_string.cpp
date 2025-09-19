/* R. Fabbri, 2024 */
#include "linked_list_string.h"
#include <gtest/gtest.h>
#include <stdlib.h>

// Helper to free list and avoid memory leaks in tests
void
free_list (NoArraySingleLink *head)
{
  NoArraySingleLink *current = head;
  while (current != nullptr)
    {
      NoArraySingleLink *next = current->next;
      free (current);
      current = next;
    }
}

void
free_list (NoPointerSingleLink *head)
{
  NoPointerSingleLink *current = head;
  while (current != nullptr)
    {
      NoPointerSingleLink *next = current->next;
      free (current->name);
      free (current);
      current = next;
    }
}

void
free_list (NoArrayDoubleLink *head)
{
  NoArrayDoubleLink *current = head;
  while (current != nullptr)
    {
      NoArrayDoubleLink *next = current->next;
      free (current);
      current = next;
    }
}

void
free_list (NoPointerDoubleLink *head)
{
  NoPointerDoubleLink *current = head;
  while (current != nullptr)
    {
      NoPointerDoubleLink *next = current->next;
      free (current->name);
      free (current);
      current = next;
    }
}

// --- Tests for NoArraySingleLink ---

TEST (NoArraySingleLinkTest, InsertAndBasicStructure)
{
  NoArraySingleLink *head = nullptr;

  // Insert into empty list
  head = insertToArraySingle (head, (char *)"first", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("first", head->name);
  EXPECT_TRUE (head->next == nullptr);

  // Insert at the beginning
  head = insertToArraySingle (head, (char *)"zero", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("zero", head->name);
  EXPECT_STREQ ("first", head->next->name);

  // Insert in the middle
  head = insertToArraySingle (head, (char *)"middle", 1);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("zero", head->name);
  EXPECT_STREQ ("middle", head->next->name);
  EXPECT_STREQ ("first", head->next->next->name);

  // Insert at the end
  head = insertToArraySingle (head, (char *)"last", 3);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("last", head->next->next->next->name);
  EXPECT_TRUE (head->next->next->next->next == nullptr);

  // Test invalid positions
  EXPECT_TRUE (insertToArraySingle (head, (char *)"invalid", -1) == nullptr);
  EXPECT_TRUE (insertToArraySingle (head, (char *)"invalid", 10) == nullptr);

  free_list (head);
}

TEST (NoArraySingleLinkTest, Delete)
{
  NoArraySingleLink *head = nullptr;
  head = insertToArraySingle (head, (char *)"a", 0);
  head = insertToArraySingle (head, (char *)"b", 1);
  head = insertToArraySingle (head, (char *)"c", 2);
  head = insertToArraySingle (head, (char *)"d", 3);

  // Delete from middle
  head = deleteFromArraySingle (head, 2); // delete "c"
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("b", head->next->name);
  EXPECT_STREQ ("d", head->next->next->name);

  // Delete from beginning
  head = deleteFromArraySingle (head, 0); // delete "a"
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("b", head->name);

  // Delete from end
  head = deleteFromArraySingle (head, 1); // delete "d"
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("b", head->name);
  EXPECT_TRUE (head->next == nullptr);

  // Delete last element
  head = deleteFromArraySingle (head, 0); // delete "b"
  EXPECT_TRUE (head == nullptr);

  // Test invalid deletes
  EXPECT_TRUE (deleteFromArraySingle (head, 0) == nullptr); // from empty
  head = insertToArraySingle (head, (char *)"a", 0);
  EXPECT_TRUE (deleteFromArraySingle (head, -1) == nullptr);
  EXPECT_TRUE (deleteFromArraySingle (head, 5) == nullptr);

  free_list (head);
}

// --- Tests for NoPointerSingleLink ---

TEST (NoPointerSingleLinkTest, InsertAndBasicStructure)
{
  NoPointerSingleLink *head = nullptr;

  head = insertToPointerSingle (head, (char *)"first", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("first", head->name);

  head = insertToPointerSingle (head, (char *)"zero", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("zero", head->name);
  EXPECT_STREQ ("first", head->next->name);

  free_list (head);
}

TEST (NoPointerSingleLinkTest, Delete)
{
  NoPointerSingleLink *head = nullptr;
  head = insertToPointerSingle (head, (char *)"a", 0);
  head = insertToPointerSingle (head, (char *)"b", 1);

  head = deleteFromPointerSingle (head, 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("b", head->name);

  head = deleteFromPointerSingle (head, 0);
  EXPECT_TRUE (head == nullptr);

  free_list (head);
}

// --- Tests for NoArrayDoubleLink ---

TEST (NoArrayDoubleLinkTest, InsertAndBasicStructure)
{
  NoArrayDoubleLink *head = nullptr;

  // Insert into empty
  head = insertToArrayDouble (head, (char *)"first", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("first", head->name);
  EXPECT_TRUE (head->prev == nullptr);
  EXPECT_TRUE (head->next == nullptr);

  // Insert at beginning
  head = insertToArrayDouble (head, (char *)"zero", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("zero", head->name);
  EXPECT_TRUE (head->prev == nullptr);
  EXPECT_TRUE (head->next != nullptr);
  EXPECT_STREQ ("first", head->next->name);
  EXPECT_EQ (head, head->next->prev);

  // Insert in middle
  head = insertToArrayDouble (head, (char *)"middle", 1);
  ASSERT_TRUE (head != nullptr);
  NoArrayDoubleLink *middle = head->next;
  EXPECT_STREQ ("middle", middle->name);
  EXPECT_EQ (head, middle->prev);
  EXPECT_EQ (middle, head->next);
  EXPECT_EQ (middle, middle->next->prev);

  free_list (head);
}

TEST (NoArrayDoubleLinkTest, Delete)
{
  NoArrayDoubleLink *head = nullptr;
  head = insertToArrayDouble (head, (char *)"a", 0);
  head = insertToArrayDouble (head, (char *)"b", 1);
  head = insertToArrayDouble (head, (char *)"c", 2);

  // Delete from middle
  head = deleteFromArrayDouble (head, 1); // delete "b"
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("a", head->name);
  EXPECT_STREQ ("c", head->next->name);
  EXPECT_EQ (head, head->next->prev);
  EXPECT_EQ (head->next, head->next->prev->next);

  // Delete from beginning
  head = deleteFromArrayDouble (head, 0); // delete "a"
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("c", head->name);
  EXPECT_TRUE (head->prev == nullptr);

  // Delete last element
  head = deleteFromArrayDouble (head, 0); // delete "c"
  EXPECT_TRUE (head == nullptr);

  free_list (head);
}

// --- Tests for NoPointerDoubleLink ---

TEST (NoPointerDoubleLinkTest, InsertAndBasicStructure)
{
  NoPointerDoubleLink *head = nullptr;

  head = insertToPointerDouble (head, (char *)"first", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("first", head->name);
  EXPECT_TRUE (head->prev == nullptr);

  head = insertToPointerDouble (head, (char *)"zero", 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("zero", head->name);
  EXPECT_TRUE (head->prev == nullptr);
  EXPECT_EQ (head, head->next->prev);

  free_list (head);
}

TEST (NoPointerDoubleLinkTest, Delete)
{
  NoPointerDoubleLink *head = nullptr;
  head = insertToPointerDouble (head, (char *)"a", 0);
  head = insertToPointerDouble (head, (char *)"b", 1);

  head = deleteFromPointerDouble (head, 0);
  ASSERT_TRUE (head != nullptr);
  EXPECT_STREQ ("b", head->name);
  EXPECT_TRUE (head->prev == nullptr);

  head = deleteFromPointerDouble (head, 0);
  EXPECT_TRUE (head == nullptr);

  free_list (head);
}

TEST (SumLens, Sum)
{
  NoPointerSingleLink *head = nullptr;

  head = insertToPointerSingle (head, (char *)"abc", 0);

  EXPECT_EQ (sum (head), 3);

  head = insertToPointerSingle (head, (char *)"abc", 0);
  head = insertToPointerSingle (head, (char *)"bfed", 0);

  EXPECT_EQ (sum (head), 10);

  head = insertToPointerSingle (head, (char *)"abc", 0);
  head = insertToPointerSingle (head, (char *)"bfed", 0);

  EXPECT_EQ (sum (head), 17);

  free_list (head);
}

TEST (SumLens, SumRec)
{
  NoPointerSingleLink *head = nullptr;

  head = insertToPointerSingle (head, (char *)"abc", 0);

  EXPECT_EQ (sumRec (head, 0), 3);

  head = insertToPointerSingle (head, (char *)"abc", 1);
  head = insertToPointerSingle (head, (char *)"bfed", 2);

  EXPECT_EQ (sumRec (head, 0), 10);

  head = insertToPointerSingle (head, (char *)"abc", 3);
  head = insertToPointerSingle (head, (char *)"bfed", 4);

  EXPECT_EQ (sumRec (head, 0), 17);

  free_list (head);
}
