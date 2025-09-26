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
  char operator[] (unsigned int index);

  // Functions
  void insert (unsigned int pos, char *data);
  void remove (unsigned int pos);

  // Destructor
  ~BigString ();

  inline unsigned int
  get_char_size () const
  {
    return char_size;
  }

  inline unsigned int
  get_size () const
  {
    return size;
  }

private:
  /*
   * @brief Internal usage function
   */
  void index ();
  // Data
  NoPointerSingleLink *strings = nullptr;
  unsigned int char_size{ 0 };
  unsigned int size{ 0 };
  std::vector<std::pair<unsigned int, NoPointerSingleLink *> > indicies{
    size
  };
};

#endif
