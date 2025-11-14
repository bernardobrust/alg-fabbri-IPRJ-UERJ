#ifndef BIG_STRING_ARRAY_H
#define BIG_STRING_ARRAY_H

#include "linked_list_string.h"
#include <cassert>
#include <utility>
#include <vector>

class BigStringArray
{
public:
  explicit BigStringArray () = default;
  explicit BigStringArray (char *data);

  // Operators
  char operator[] (unsigned int index) const;

  // Functions
  // Insert string at position
  void insert (unsigned int pos, char *data);
  // Appends big string to end
  void concat (BigStringArray& S);
  // Inserts big string at a specific node
  void insert_big_string (BigStringArray& S, unsigned int pos);
  // Inserts a big string at a specific char
  void insert_big_string_at (BigStringArray& S, unsigned int pos);

  void remove (unsigned int pos);

  ~BigStringArray ();

  inline unsigned int
  get_char_size () const
  {
    return char_size;
  }

  inline unsigned int
  get_size() const
  {
    return size;
  }

  inline NoArraySingleLink*
  get_head () const
  {
    return strings;
  }

  inline NoArraySingleLink*
  get_tail () const
  {
    return tail;
  }

private:
  std::pair<unsigned int, NoArraySingleLink *> b_search(unsigned int index) const;
  void index ();

  // Data
  NoArraySingleLink *strings = nullptr;
  NoArraySingleLink *tail = nullptr;
  unsigned int char_size{ 0 };
  unsigned int size{ 0 };
  std::vector<std::pair<unsigned int, NoArraySingleLink *> > indicies{
    size
  };
};

#endif
