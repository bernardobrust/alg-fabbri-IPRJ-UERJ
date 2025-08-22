/* R. Fabbri, 2024 */
#include "sorted_merge_3way.h"
#include <algorithm>
#include <climits>

bool
sorted_merge_3way (const int *list_a, int na, const int *list_b, int nb,
                   const int *list_c, int nc, int *list_abc)
{
  int j{ 0 }, k{ 0 }, l{ 0 }, prev{ INT_MIN };
  const int new_size{ na + nb + nc };

  for (int i = 0; i < new_size; ++i)
    {
      int a{ list_a[j] }, b{ list_b[k] }, c{ list_c[l] };

      if (j == na)
        a = INT_MAX;
      if (k == nb)
        b = INT_MAX;
      if (l == nc)
        c = INT_MAX;

      const int to_add{ std::min ({ a, b, c }) };

      if (to_add < prev)
        return false;

      prev = to_add;
      list_abc[i] = to_add;

      if (to_add == a)
        ++j;
      if (to_add == b)
        ++k;
      if (to_add == c)
        ++l;
    }

  return true;
}
