/* R. Fabbri, 2024 */
#include <iostream>

// Hardcoded sizes based on original jl.c test cases
#define NA_SIZE 3
#define NB_SIZE 4
#define NC_SIZE 2
#define TOTAL_SIZE (NA_SIZE + NB_SIZE + NC_SIZE)

#include "sorted_merge_3way.h"

int
main ()
{
  int list_a[NA_SIZE];
  int list_b[NB_SIZE];
  int list_c[NC_SIZE];
  int list_abc[TOTAL_SIZE];

  // Read elements directly from stdin
  for (int i = 0; i < NA_SIZE; ++i)
    std::cin >> list_a[i];
  for (int i = 0; i < NB_SIZE; ++i)
    std::cin >> list_b[i];
  for (int i = 0; i < NC_SIZE; ++i)
    std::cin >> list_c[i];

  // Check for input errors (e.g., non-numeric input, EOF)
  if (std::cin.fail ())
    {
      std::cerr << "Error: Invalid input or premature end of input."
                << std::endl;
      return 1;
    }

  bool res = sorted_merge_3way (list_a, NA_SIZE, list_b, NB_SIZE, list_c,
                                NC_SIZE, list_abc);

  if (!res)
    {
      std::cerr << "Error: An input list was not sorted." << std::endl;
      return 1;
    }

  for (int i = 0; i < TOTAL_SIZE; ++i)
    std::cout << list_abc[i] << " ";
  std::cout << std::endl;

  return 0;
}
