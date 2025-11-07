/* R. Fabbri, 2024 */
#include "linked_list_string.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*
 * Returning nullptr on error
 */

NoArraySingleLink *
insertToArraySingle (NoArraySingleLink *head, char data[], int pos)
{
  if (pos < 0)
    return nullptr;

  NoArraySingleLink *newNode
      = (NoArraySingleLink *)malloc (sizeof (NoArraySingleLink));
  if (!newNode)
    return nullptr;
  strncpy (newNode->name, data, MAX_SZA);
  // Null termination
  newNode->name[MAX_SZA - 1] = '\0';

  if (pos == 0)
    {
      newNode->next = head;
      return newNode;
    }

  NoArraySingleLink *current{ head };
  int i{ 0 };
  while (i < pos - 1 && current != nullptr)
    {
      current = current->next;
      ++i;
    }

  if (current == nullptr)
    {
      free (newNode);
      return nullptr;
    }

  newNode->next = current->next;
  current->next = newNode;

  return head;
}

NoPointerSingleLink *
insertToPointerSingle (NoPointerSingleLink *head, char *data, int pos)
{
  if (pos < 0)
    return nullptr;

  NoPointerSingleLink *newNode
      = (NoPointerSingleLink *)malloc (sizeof (NoPointerSingleLink));
  if (!newNode)
    return nullptr;

  newNode->name = strdup (data);
  if (!newNode->name)
    {
      free (newNode);
      return nullptr;
    }

  if (pos == 0)
    {
      newNode->next = head;
      return newNode;
    }

  NoPointerSingleLink *current{ head };
  int i{ 0 };
  while (i < pos - 1 && current != nullptr)
    {
      current = current->next;
      ++i;
    }

  if (current == nullptr)
    {
      free (newNode->name);
      free (newNode);
      return nullptr;
    }

  newNode->next = current->next;
  current->next = newNode;

  return head;
}

NoArrayDoubleLink *
insertToArrayDouble (NoArrayDoubleLink *head, char data[], int pos)
{
  if (pos < 0)
    return nullptr;

  NoArrayDoubleLink *newNode
      = (NoArrayDoubleLink *)malloc (sizeof (NoArrayDoubleLink));
  if (!newNode)
    return nullptr;
  strncpy (newNode->name, data, MAX_SZA);
  newNode->name[MAX_SZA - 1] = '\0';
  newNode->prev = nullptr;
  newNode->next = nullptr;

  if (pos == 0)
    {
      newNode->next = head;
      if (head)
        {
          head->prev = newNode;
        }
      return newNode;
    }

  NoArrayDoubleLink *current{ head };
  int i{ 0 };
  while (i < pos - 1 && current != nullptr)
    {
      current = current->next;
      ++i;
    }

  if (current == nullptr)
    {
      free (newNode);
      return nullptr;
    }

  newNode->next = current->next;
  if (current->next != nullptr)
    {
      current->next->prev = newNode;
    }
  current->next = newNode;
  newNode->prev = current;

  return head;
}

NoPointerDoubleLink *
insertToPointerDouble (NoPointerDoubleLink *head, char *data, int pos)
{
  if (pos < 0)
    return nullptr;

  NoPointerDoubleLink *newNode
      = (NoPointerDoubleLink *)malloc (sizeof (NoPointerDoubleLink));
  if (!newNode)
    return nullptr;

  newNode->name = strdup (data);
  if (!newNode->name)
    {
      free (newNode);
      return nullptr;
    }
  newNode->prev = nullptr;
  newNode->next = nullptr;

  if (pos == 0)
    {
      newNode->next = head;
      if (head)
        {
          head->prev = newNode;
        }
      return newNode;
    }

  NoPointerDoubleLink *current{ head };
  int i{ 0 };
  while (i < pos - 1 && current != nullptr)
    {
      current = current->next;
      ++i;
    }

  if (current == nullptr)
    {
      free (newNode->name);
      free (newNode);
      return nullptr;
    }

  newNode->next = current->next;
  if (current->next != nullptr)
    {
      current->next->prev = newNode;
    }
  current->next = newNode;
  newNode->prev = current;

  return head;
}

// Deletes
NoArraySingleLink *
deleteFromArraySingle (NoArraySingleLink *head, int pos)
{
  if (head == nullptr || pos < 0)
    {
      return nullptr;
    }

  NoArraySingleLink *temp{ head };

  if (pos == 0)
    {
      head = head->next;
      free (temp);
      return head;
    }

  NoArraySingleLink *prev{ nullptr };
  int i{ 0 };
  while (temp != nullptr && i < pos)
    {
      prev = temp;
      temp = temp->next;
      ++i;
    }

  if (temp == nullptr)
    {
      return nullptr;
    }

  prev->next = temp->next;
  free (temp);

  return head;
}

NoPointerSingleLink *
deleteFromPointerSingle (NoPointerSingleLink *head, int pos)
{
  if (head == nullptr || pos < 0)
    {
      return nullptr;
    }

  NoPointerSingleLink *temp{ head };

  if (pos == 0)
    {
      head = head->next;
      free (temp->name);
      free (temp);
      return head;
    }

  NoPointerSingleLink *prev{ nullptr };
  int i{ 0 };
  while (temp != nullptr && i < pos)
    {
      prev = temp;
      temp = temp->next;
      ++i;
    }

  if (temp == nullptr)
    {
      return nullptr;
    }

  prev->next = temp->next;
  free (temp->name);
  free (temp);

  return head;
}

NoArrayDoubleLink *
deleteFromArrayDouble (NoArrayDoubleLink *head, int pos)
{
  if (head == nullptr || pos < 0)
    {
      return nullptr;
    }

  NoArrayDoubleLink *temp{ head };

  if (pos == 0)
    {
      head = head->next;
      if (head != nullptr)
        {
          head->prev = nullptr;
        }
      free (temp);
      return head;
    }

  int i{ 0 };
  while (temp != nullptr && i < pos)
    {
      temp = temp->next;
      ++i;
    }

  if (temp == nullptr)
    {
      return nullptr;
    }

  temp->prev->next = temp->next;
  if (temp->next != nullptr)
    {
      temp->next->prev = temp->prev;
    }
  free (temp);

  return head;
}

NoPointerDoubleLink *
deleteFromPointerDouble (NoPointerDoubleLink *head, int pos)
{
  if (head == nullptr || pos < 0)
    {
      return nullptr;
    }

  NoPointerDoubleLink *temp{ head };

  if (pos == 0)
    {
      head = head->next;
      if (head != nullptr)
        {
          head->prev = nullptr;
        }
      free (temp->name);
      free (temp);
      return head;
    }

  int i{ 0 };
  while (temp != nullptr && i < pos)
    {
      temp = temp->next;
      ++i;
    }

  if (temp == nullptr)
    {
      return nullptr;
    }

  temp->prev->next = temp->next;
  if (temp->next != nullptr)
    {
      temp->next->prev = temp->prev;
    }
  free (temp->name);
  free (temp);

  return head;
}

// Gets
void
getFromArraySingle (NoArraySingleLink *head, int pos)
{
  NoArraySingleLink *current = head;
  int i{ 0 };

  if (pos >= 0)
    {
      while (current != nullptr && i < pos)
        {
          current = current->next;
          ++i;
        }
    }

  if (pos < 0 || current == nullptr)
    {
      if (head == nullptr)
        {
          printf ("Posicao invalida, ultimo: (null)\n");
        }
      else
        {
          NoArraySingleLink *last = head;
          while (last->next != nullptr)
            {
              last = last->next;
            }
          printf ("Posicao invalida, ultimo: %s\n", last->name);
        }
    }
  else
    {
      printf ("Item %d: %s\n", i, current->name);
    }
}

NoPointerSingleLink*
getFromPointerSingle (NoPointerSingleLink *head, int pos)
{
  NoPointerSingleLink *current = head;
  int i{ 0 };

  if (pos >= 0)
    {
      while (current != nullptr && i < pos)
        {
          current = current->next;
          ++i;
        }
    }

  if (pos < 0 || current == nullptr)
    {
      if (head == nullptr)
        {
          printf ("Posicao invalida, ultimo: (null)\n");
          return nullptr;
        }
      else
        {
          NoPointerSingleLink *last = head;
          while (last->next != nullptr)
            {
              last = last->next;
            }
          printf ("Posicao invalida, ultimo: %s\n", last->name);
          return nullptr;
        }
    }
  else
      return current;
}

void
getFromArrayDouble (NoArrayDoubleLink *head, int pos)
{
  NoArrayDoubleLink *current = head;
  int i{ 0 };

  if (pos >= 0)
    {
      while (current != nullptr && i < pos)
        {
          current = current->next;
          ++i;
        }
    }

  if (pos < 0 || current == nullptr)
    {
      if (head == nullptr)
        {
          printf ("Posicao invalida, ultimo: (null)\n");
        }
      else
        {
          NoArrayDoubleLink *last = head;
          while (last->next != nullptr)
            {
              last = last->next;
            }
          printf ("Posicao invalida, ultimo: %s\n", last->name);
        }
    }
  else
    {
      printf ("Item %d: %s\n", i, current->name);
    }
}

void
getFromPointerDouble (NoPointerDoubleLink *head, int pos)
{
  NoPointerDoubleLink *current = head;
  int i{ 0 };

  if (pos >= 0)
    {
      while (current != nullptr && i < pos)
        {
          current = current->next;
          ++i;
        }
    }

  if (pos < 0 || current == nullptr)
    {
      if (head == nullptr)
        {
          printf ("Posicao invalida, ultimo: (null)\n");
        }
      else
        {
          NoPointerDoubleLink *last = head;
          while (last->next != nullptr)
            {
              last = last->next;
            }
          printf ("Posicao invalida, ultimo: %s\n", last->name);
        }
    }
  else
    {
      printf ("Item %d: %s\n", i, current->name);
    }
}

// Other operations
int
sum (NoPointerSingleLink *head)
{
  int sum{ 0 };

  if (!head)
    return 0;

  NoPointerSingleLink *cur{ head };

  while (cur)
    {
      sum += strlen (cur->name);
      cur = cur->next;
    }

  return sum;
}

int
sumRec (NoPointerSingleLink *head, int acc)
{
  if (!head)
    return acc;

  return sumRec (head->next, acc + strlen (head->name));
}
