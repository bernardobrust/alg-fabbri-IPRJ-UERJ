#include "big_string_array.h"
#include <cstdlib>
#include <cstring>
#include <utility>

BigStringArray::BigStringArray (char *data)
{
  insert (0, data);
}

BigStringArray::~BigStringArray ()
{
  NoArraySingleLink *current{ strings };
  while (current != nullptr)
    {
      NoArraySingleLink *next{ current->next };
      free (current);
      current = next;
    }
}

char
BigStringArray::operator[] (unsigned int index) const
{
  if (char_size == 0) return '\0';
  assert (index < char_size);

  auto t = b_search(index);
  return t.second->name[index - t.first];
}

void
BigStringArray::insert (unsigned int pos, char *data)
{
  assert(pos <= size);
  assert(data != nullptr);
  
  size_t data_len = strlen(data);
  if (data_len == 0) return;

  NoArraySingleLink* insert_after_node = nullptr;
  if (pos > 0) {
      NoArraySingleLink* current = strings;
      for(unsigned i=0; i < pos - 1; ++i) current = current->next;
      insert_after_node = current;
  }

  const size_t capacity = MAX_SZA - 1;
  size_t data_offset = 0;
  unsigned int nodes_created = 0;

  NoArraySingleLink* last_new_node = nullptr;

  while (data_offset < data_len) {
      NoArraySingleLink *new_node = (NoArraySingleLink*) malloc(sizeof(NoArraySingleLink));
      if (!new_node) { return; }
      
      size_t to_copy = data_len - data_offset;
      if (to_copy > capacity) {
          to_copy = capacity;
      }
      
      strncpy(new_node->name, data + data_offset, to_copy);
      new_node->name[to_copy] = '\0';
      new_node->next = nullptr;

      if (nodes_created == 0) {
          if (insert_after_node) {
              new_node->next = insert_after_node->next;
              insert_after_node->next = new_node;
          } else {
              new_node->next = strings;
              strings = new_node;
          }
      } else {
          last_new_node->next = new_node;
      }
      
      last_new_node = new_node;
      data_offset += to_copy;
      char_size += to_copy;
      nodes_created++;
  }

  size += nodes_created;

  if (last_new_node && last_new_node->next == nullptr) {
      tail = last_new_node;
  } else if (size == nodes_created) {
      tail = last_new_node;
  }

  index ();
}

void
BigStringArray::insert_big_string (BigStringArray& S, unsigned int pos)
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
        NoArraySingleLink *cur = strings;
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
BigStringArray::insert_big_string_at(BigStringArray& S, unsigned int pos)
{
    if (S.get_size() == 0) return;
    assert(pos <= char_size);

    if (size == 0) {
        strings = S.get_head();
        tail = S.get_tail();
        size = S.get_size();
        char_size = S.get_char_size();
        S.strings = S.tail = nullptr; S.size = S.char_size = 0;
        index();
        return;
    }

    if (pos == 0) {
        insert_big_string(S, 0);
        return;
    }
    if (pos == char_size) {
        concat(S);
        return;
    }

    std::pair<unsigned int, NoArraySingleLink*> node_info = b_search(pos);
    NoArraySingleLink* target_node = node_info.second;
    unsigned int offset_in_node = pos - node_info.first;
    
    unsigned int node_pos = 0;
    for(unsigned int i{0}; i < indicies.size(); ++i) {
        if(indicies[i].second == target_node) {
            node_pos = i;
            break;
        }
    }

    if (offset_in_node == 0) {
        insert_big_string(S, node_pos);
        return;
    }
    
    size_t target_len = strlen(target_node->name);
    if (offset_in_node == target_len) {
        insert_big_string(S, node_pos + 1);
        return;
    }

    char move_str[MAX_SZA];
    strcpy(move_str, target_node->name + offset_in_node);
    target_node->name[offset_in_node] = '\0';
    size_t part1_len = strlen(target_node->name);
    size_t part2_len = strlen(move_str);

    if (S.get_size() == 1) {
        NoArraySingleLink* s_head = S.get_head();
        size_t s_len = strlen(s_head->name);
        if (part1_len + s_len + part2_len <= MAX_SZA - 1) {
            strcat(target_node->name, s_head->name);
            strcat(target_node->name, move_str);

            free(s_head);
            char_size += s_len;
            
            S.strings = nullptr; S.tail = nullptr; S.size = 0; S.char_size = 0;
            
            index();
            return;
        }
    }

    NoArraySingleLink* move_node = (NoArraySingleLink*)malloc(sizeof(NoArraySingleLink));
    strcpy(move_node->name, move_str);
    move_node->next = target_node->next;

    unsigned int s_size = S.get_size();
    unsigned int s_char_size = S.get_char_size();

    target_node->next = S.get_head();
    S.get_tail()->next = move_node;

    if (tail == target_node) {
        tail = move_node;
    }

    size += s_size + 1;
    char_size += s_char_size;

    S.strings = nullptr;
    S.tail = nullptr;
    S.size = 0;
    S.char_size = 0;

    index();
}

void
BigStringArray::remove (unsigned int pos)
{
  if (size == 0) return;
  assert(pos < size);

  NoArraySingleLink *node_to_delete = strings;
  NoArraySingleLink *prev = nullptr;
  for (unsigned int i = 0; i < pos; i++)
  {
    prev = node_to_delete;
    node_to_delete = node_to_delete->next;
  }

  unsigned int removed = strlen (node_to_delete->name);
  
  if (prev) {
      prev->next = node_to_delete->next;
  } else {
      strings = node_to_delete->next;
  }

  if (node_to_delete == tail) {
      tail = prev;
  }

  free(node_to_delete);

  char_size -= removed;
  --size;

  if (size == 0) {
      tail = nullptr;
  }

  index ();
}

void
BigStringArray::concat (BigStringArray& S)
{
    insert_big_string(S, size);
}

std::pair<unsigned int, NoArraySingleLink *>
BigStringArray::b_search(unsigned int index) const
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

  return indicies[0];
}

void
BigStringArray::index ()
{
  if (size != indicies.size ())
    indicies.resize (size);

  if(size == 0) return;

  NoArraySingleLink *cur{ strings };
  unsigned int acc{ 0 };
  unsigned int i{ 0 };
  while (cur)
    {
      indicies[i++] = std::make_pair (acc, cur);
      acc += strlen (cur->name);
      cur = cur->next;
    }
}
