#ifndef DAHUA_ALGO_SORT_H
#define DAHUA_ALGO_SORT_H

#include "data_structure.h"

void num_swap(num_seq *seq, int i, int j);

void bubble_sort(num_seq *seq);

void select_sort(num_seq *seq);

void insert_sort(num_seq *seq);

void shell_sort(num_seq *seq);

void heap_sort(num_seq *seq);

void merge_sort(num_seq *seq);

void merge_sort2(num_seq *seq);

void quick_sort(num_seq *seq);

void quick_sort2(num_seq *seq);

#endif
