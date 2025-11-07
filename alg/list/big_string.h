#ifndef BIG_STRING_H
#define BIG_STRING_H

#include "linked_list_string.h"
#include <cassert>
#include <utility>
#include <vector>

class BigString
{
public:
  explicit BigString () = default;
  explicit BigString (char *data);

  // Operators
  char operator[] (unsigned int index) const;

  // Functions
  // Insert string at position
  void insert (unsigned int pos, char *data);
  // Appends big string to end
  void concat (BigString& S);
  // Inserts big string at a specific node
  void insert_big_string (BigString& S, unsigned int pos);
  // Inserts a big string at a specific char
  void insert_big_string_at (BigString& S, unsigned int pos);

  void remove (unsigned int pos);

  ~BigString ();

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

  inline NoPointerSingleLink*
  get_head () const
  {
    return strings;
  }

  inline NoPointerSingleLink*
  get_tail () const
  {
    return tail;
  }

private:
  std::pair<unsigned int, NoPointerSingleLink *> b_search(unsigned int index) const;
  void index ();

  // Data
  NoPointerSingleLink *strings = nullptr;
  NoPointerSingleLink *tail = nullptr;
  unsigned int char_size{ 0 };
  unsigned int size{ 0 };
  std::vector<std::pair<unsigned int, NoPointerSingleLink *> > indicies{
    size
  };
};

#endif