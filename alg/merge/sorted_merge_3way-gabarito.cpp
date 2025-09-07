/* R. Fabbri, 2024 */
#include "sorted_merge_3way.h"
#include <climits>

bool
sorted_merge_3way(
    const int *list_a, int na,
    const int *list_b, int nb,
    const int *list_c, int nc,
    int *list_abc)
{
  const int *end_a = list_a + na, 
      *end_b = list_b + nb,
      *end_c = list_c + nc,
      *end_abc = list_abc + na + nb + nc;
  int a_prev = INT_MIN;

  // Qualquer solucao com resultados corretos foi considerada,
  // sendo a maior nota considerada se a complexidade for O(na+nb+nc),
  // independente dos detalhes de implementacao.
  while(list_abc != end_abc)
  {
    if (list_a != end_a && (list_b == end_b || *list_a < *list_b)) {
      if (list_c == end_c || *list_a < *list_c)
        *list_abc = *(list_a++);
      else
        *list_abc = *(list_c++);
    } else { 
      if (list_b != end_b && (list_c == end_c || *list_b < *list_c))
        *list_abc = *(list_b++);
      else if (list_c != end_c)
        *list_abc = *(list_c++);
      else
        break; // Should not be reached if sizes are correct
    }
    if (*list_abc < a_prev)
      return false;
    a_prev = *(list_abc++);
  }

  return true;
}
