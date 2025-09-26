#include "big_string.h"
#include <cstdlib>
#include <cstring>
#include <utility>

BigString::BigString (char *data) { insert (0, data); }

BigString::~BigString ()
{
  NoPointerSingleLink *current{ strings };
  while (current != nullptr)
    {
      NoPointerSingleLink *next{ current->next };
      free (current->name);
      free (current);
      current = next;
    }
}

char
BigString::operator[] (unsigned int index)
{
  assert (index < char_size);

  // Modified Binary Search
  unsigned int low{ 0 };
  unsigned int high{ size - 1 };

  while (low <= high)
    {
      unsigned int mid{ (high + low) >> 1 };
      unsigned int start = indicies[mid].first;
      unsigned int end
          = (mid + 1 < size) ? indicies[mid + 1].first : char_size;

      if (start <= index && index < end)
        {
          return indicies[mid].second->name[index - start];
        }
      else if (indicies[mid].first < index)
        {
          low = mid + 1;
        }
      else
        {
          high = mid - 1;
        }
    }

  // Invalid position, should never happen
  return '\0';
}

void
BigString::insert (unsigned int pos, char *data)
{
  strings = insertToPointerSingle (strings, data, pos);
  char_size += strlen (data);
  ++size;

  index ();
}

void
BigString::remove (unsigned int pos)
{
  NoPointerSingleLink *node_to_delete = strings;
  for (unsigned int i = 0; i < pos && node_to_delete != nullptr; i++)
    {
      node_to_delete = node_to_delete->next;
    }

  if (node_to_delete == nullptr)
    return;

  unsigned int removed = strlen (node_to_delete->name);
  strings = deleteFromPointerSingle (strings, pos);
  char_size -= removed;
  --size;

  index ();
}

void
BigString::index ()
{
  // Generate indicies for faster acess
  NoPointerSingleLink *cur{ strings };
  unsigned int acc{ 0 };

  if (size != indicies.size ())
    indicies.resize (size);

  unsigned int i{ 0 };
  while (cur)
    {
      indicies[i++] = std::make_pair (acc, cur);
      acc += strlen (cur->name);
      cur = cur->next;
    }
}
