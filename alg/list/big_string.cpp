#include "big_string.h"
#include <cstdlib>
#include <cstring>
#include <utility>

BigString::BigString (char *data)
{
  insert (0, data);
}

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
BigString::operator[] (unsigned int index) const
{
  if (char_size == 0) return '\0';
  assert (index < char_size);

  auto t = b_search(index);
  return t.second->name[index - t.first];
}

void
BigString::insert (unsigned int pos, char *data)
{
  assert(pos <= size);
  assert(data != nullptr);
  strings = insertToPointerSingle (strings, data, pos);
  
  if (pos == size)
    tail = getFromPointerSingle(strings, pos);

  char_size += strlen (data);
  ++size;

  index ();
}

void
BigString::insert_big_string (BigString& S, unsigned int pos)
{
    if (S.get_size() == 0) return;
    assert(pos <= size);

    if (size == 0) {
        strings = S.get_head();
        tail = S.get_tail();
    } else if (pos == 0) {
        S.get_tail()->next = strings;
        strings = S.get_head();
    } else {
        NoPointerSingleLink *cur = strings;
        for (unsigned int i = 0; i < pos - 1; ++i) {
            cur = cur->next;
        }
        S.get_tail()->next = cur->next;
        cur->next = S.get_head();
        if (pos == size) {
            tail = S.get_tail();
        }
    }

    size += S.get_size();
    char_size += S.get_char_size();

    S.strings = nullptr;
    S.tail = nullptr;
    S.size = 0;
    S.char_size = 0;

    index();
}

void
BigString::insert_big_string_at(BigString& S, unsigned int pos)
{
    if (S.get_size() == 0) return;
    assert(pos <= char_size);

    if (pos == 0) {
        insert_big_string(S, 0);
        return;
    }
    if (pos == char_size) {
        concat(S);
        return;
    }

    // Find the node to cut
    std::pair<unsigned int, NoPointerSingleLink*> node_to_cut_info = b_search(pos);
    NoPointerSingleLink* node_to_cut = node_to_cut_info.second;
    unsigned int pos_to_cut = pos - node_to_cut_info.first;

    unsigned int node_pos = 0;
    for(unsigned int i{0}; i < indicies.size(); ++i)
    {
        if(indicies[i].second == node_to_cut)
        {
            node_pos = i;
            break;
        }
    }

    if (pos_to_cut == 0)
    {
        insert_big_string(S, node_pos);
        return;
    }

    char* str_to_cut = node_to_cut->name;
    if (pos_to_cut == strlen(str_to_cut))
    {
        insert_big_string(S, node_pos + 1);
        return;
    }

    char* keep = strndup(str_to_cut, pos_to_cut);
    char* move = strdup(str_to_cut + pos_to_cut);

    // Update the original node
    free(node_to_cut->name);
    node_to_cut->name = keep;

    // Create a new node for the second half of the string
    NoPointerSingleLink* move_node = (NoPointerSingleLink*)malloc(sizeof(NoPointerSingleLink));
    move_node->name = move;

    // Insert S and the new node
    move_node->next = node_to_cut->next;
    NoPointerSingleLink* S_tail = S.get_tail();
    node_to_cut->next = S.get_head();
    if (S_tail) S_tail->next = move_node;


    // Update sizes
    size += S.get_size() + 1;
    char_size += S.get_char_size();

    // Update tail if needed
    if (node_to_cut == tail)
        tail = move_node;

    // Clear S
    S.strings = nullptr;
    S.tail = nullptr;
    S.size = 0;
    S.char_size = 0;

    index();
}

void
BigString::remove (unsigned int pos)
{
  if (size == 0) return;
  assert(pos < size);

  if (pos == size - 1)
    {
      if (size == 1)
        tail = nullptr;
      else
        tail = getFromPointerSingle(strings, pos - 1);
    }

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
BigString::concat (BigString& S)
{
    insert_big_string(S, size);
}

std::pair<unsigned int, NoPointerSingleLink *>
BigString::b_search(unsigned int index) const
{
  if (size == 0) return std::make_pair(0, nullptr);

  unsigned int low{ 0 };
  unsigned int high{ size - 1 };

  while (low <= high)
    {
      unsigned int mid{ (high + low) >> 1 };
      unsigned int start = indicies[mid].first;
      unsigned int end
          = (mid + 1 < size) ? indicies[mid + 1].first : char_size;

      if (start <= index && index < end)
          return indicies[mid];
      else if (indicies[mid].first < index)
          low = mid + 1;
      else
          high = mid - 1;
    }

  // Should never happen
  return indicies[0];
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