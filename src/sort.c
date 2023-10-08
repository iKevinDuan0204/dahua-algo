#include "sort.h"

void num_swap(num_seq *seq, int i, int j) {
  number tmp = seq->num[i];
  seq->num[i] = seq->num[j];
  seq->num[j] = tmp;
}

void bubble_sort(num_seq *seq) {
  _Bool is_sorted = 0;
  for (int i = 1; !is_sorted && i < seq->size; ++i) {
    is_sorted = 1;
    for (int j = seq->size; j > i; --j) {
      if (seq->num[j - 1] > seq->num[j]) {
        num_swap(seq, j - 1, j);
        is_sorted = 0;
      }
    }
  }
}

void select_sort(num_seq *seq) {
  for (int i = 1; i < seq->size; ++i) {
    number min = i;
    for (int j = i + 1; j <= seq->size; ++j) {
      if (seq->num[min] > seq->num[j]) {
        min = j;
      }
    }
    if (min != i) {
      num_swap(seq, min, i);
    }
  }
}

void insert_sort(num_seq *seq) {
  for (int i = 2; i <= seq->size; ++i) {
    if (seq->num[i - 1] > seq->num[i]) {
      seq->num[0] = seq->num[i];
      int j;
      for (j = i - 1; seq->num[j] > seq->num[0]; --j) {
        seq->num[j + 1] = seq->num[j];
      }
      seq->num[j + 1] = seq->num[0];
    }
  }
}

void shell_sort(num_seq *seq) {
  int incre = seq->size;
  do {
    incre = incre / 3 + 1;
    for (int i = 1 + incre; i <= seq->size; ++i) {
      if (seq->num[i - incre] > seq->num[i]) {
        seq->num[0] = seq->num[i];
        int j;
        for (j = i - incre; j > 0 && seq->num[j] > seq->num[0]; j -= incre) {
          seq->num[j + incre] = seq->num[j];
        }
        seq->num[j + incre] = seq->num[0];
      }
    }
  } while (incre > 1);
}

void heap_adjust(num_seq *seq, int start, int end) {
  seq->num[0] = seq->num[start];
  for (int i = 2 * start; i <= end; i *= 2) {
    if (i < end && seq->num[i] < seq->num[i + 1]) {
      ++i;
    }
    if (seq->num[0] >= seq->num[i]) {
      break;
    }
    seq->num[start] = seq->num[i];
    start = i;
  }
  seq->num[start] = seq->num[0];
}

void heap_sort(num_seq *seq) {
  for (int i = seq->size / 2; i > 0; --i) {
    heap_adjust(seq, i, seq->size);
  }
  for (int i = seq->size; i > 1; --i) {
    num_swap(seq, 1, i);
    heap_adjust(seq, 1, i - 1);
  }
}

void merge(number tmp[], number res[], int start, int mid, int end) {
  int i, j, k;
  for (i = start, j = mid + 1, k = start; i <= mid && j <= end; ++k) {
    if (tmp[i] < tmp[j]) {
      res[k] = tmp[i++];
    } else {
      res[k] = tmp[j++];
    }
  }
  if (i <= mid) {
    for (; i <= mid; ++i) {
      res[k++] = tmp[i];
    }
  } else {
    for (; j <= end; ++j) {
      res[k++] = tmp[j];
    }
  }
}

void m_sort(number num[], number res[], int start, int end) {
  if (start == end) {
    res[start] = num[start];
  } else {
    number tmp[MAXSIZE + 1];
    int mid = (start + end) / 2;
    m_sort(num, tmp, start, mid);
    m_sort(num, tmp, mid + 1, end);
    merge(tmp, res, start, mid, end);
  }
}

void merge_sort(num_seq *seq) { m_sort(seq->num, seq->num, 1, seq->size); }

void merge_pass(number num[], number res[], int incre, int end) {
  int i;
  for (i = 1; i <= end - 2 * incre + 1; i += 2 * incre) {
    merge(num, res, i, i + incre - 1, i + 2 * incre - 1);
  }
  if (i < end - incre + 1) {
    merge(num, res, i, i + incre - 1, end);
  } else {
    for (; i <= end; ++i) {
      res[i] = num[i];
    }
  }
}

void merge_sort2(num_seq *seq) {
  number tmp[seq->size + 1];
  int incre = 1;
  while (incre < seq->size) {
    merge_pass(seq->num, tmp, incre, seq->size);
    incre *= 2;
    merge_pass(tmp, seq->num, incre, seq->size);
    incre *= 2;
  }
}

int partition(num_seq *seq, int low, int high) {
  int mid = low + (high - low) / 2;
  if (seq->num[low] > seq->num[high]) {
    num_swap(seq, low, high);
  }
  if (seq->num[mid] > seq->num[high]) {
    num_swap(seq, mid, high);
  }
  if (seq->num[mid] > seq->num[low]) {
    num_swap(seq, low, mid);
  }

  seq->num[0] = seq->num[low];
  while (low < high) {
    while (low < high && seq->num[high] >= seq->num[0]) {
      --high;
    }
    seq->num[low] = seq->num[high];
    while (low < high && seq->num[low] <= seq->num[0]) {
      ++low;
    }
    seq->num[high] = seq->num[low];
  }
  seq->num[low] = seq->num[0];
  return low;
}

void q_sort(num_seq *seq, int start, int end) {
  if (start < end) {
    int pivot = partition(seq, start, end);
    q_sort(seq, start, pivot - 1);
    q_sort(seq, pivot + 1, end);
  }
}

#define MAX_LENGTH_INSERT_SORT 7

void q_sort2(num_seq *seq, int start, int end) {
  if ((end - start) > MAX_LENGTH_INSERT_SORT) {
    while (start < end) {
      int pivot = partition(seq, start, end);
      q_sort2(seq, start, pivot - 1);
      start = pivot + 1;
    }
  } else {
    insert_sort(seq);
  }
}

void quick_sort(num_seq *seq) { q_sort(seq, 1, seq->size); }

void quick_sort2(num_seq *seq) { q_sort2(seq, 1, seq->size); }
