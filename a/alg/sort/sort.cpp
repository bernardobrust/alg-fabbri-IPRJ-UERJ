/* Author Ricardo Fabbri rfabbri@iprj.uerj.br 2025 */
#include "sort.h"
#include <algorithm>
#include <cstring>
#include <vector>

// Comparison function for qsort
int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void simple_sort(char *list[], int n) {
    qsort(list, n, sizeof(char *), compare_strings);
}


// Radix sort implementation for strings
const int BITS_PER_BYTE = 8;
const int R = 1 << BITS_PER_BYTE;

int char_at(char* s, int d) {
    if (strlen(s) <= (size_t)d) return -1;
    return s[d];
}

void radix_sort_msd(char* a[], int n, int d, std::vector<char*>& aux) {
    if (n <= 1) return;

    std::vector<int> count(R + 2, 0);
    for (int i = 0; i < n; i++)
        count[char_at(a[i], d) + 2]++;

    for (int r = 0; r < R + 1; r++)
        count[r + 1] += count[r];

    for (int i = 0; i < n; i++)
        aux[count[char_at(a[i], d) + 1]++] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = aux[i];

    for (int r = 0; r < R; r++)
        radix_sort_msd(&a[count[r]], count[r+1] - count[r], d + 1, aux);
}

void fast_sort(char* list[], int n) {
    if (n <= 1) return;
    std::vector<char*> aux(n);
    radix_sort_msd(list, n, 0, aux);
}
