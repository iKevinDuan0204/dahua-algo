#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

num_seq *generate_num_seq(num_seq seqs[], int size) {
    srand((unsigned int) time(NULL));
    for (int i = 1; i <= seqs[0].size; ++i) {
        seqs[0].num[i] = rand() % (10000);
    }
    for (int i = 1; i < size; ++i) {
        seqs[i] = seqs[0];
    }
    return seqs;
}

#define SUCCESS 1
#define FAIL 0
typedef int status;

status is_sorted(num_seq *seq) {
    for (int i = 1; i < seq->size; ++i) {
        if (seq->num[i] > seq->num[i + 1]) {
            return FAIL;
        }
    }
    return SUCCESS;
}

#define SIZE 9

typedef void (*sort)(num_seq *seq);

sort sort_algo[SIZE] = {bubble_sort, select_sort, insert_sort, shell_sort, heap_sort, merge_sort, merge_sort2,
                        quick_sort, quick_sort2};
num_seq seqs[SIZE];

int main() {
    int cnt;
    scanf("%d", &cnt);

    if (cnt <= 0 || cnt > 1000) {
        exit(EXIT_FAILURE);
    }
    seqs[0].size = cnt;

    generate_num_seq(seqs, SIZE);
    for (int i = 0; i <= cnt; ++i) {
        printf("%d ", seqs[0].num[i]);
    }
    printf("\n");

    for (int i = 0; i < SIZE; ++i) {
        sort_algo[i](&seqs[i]);
//        printf("%d\n", i);
//        for (int j = 0; j <= cnt; ++j) {
//            printf("%d ", seqs[i].num[j]);
//        }
        printf("\n%d\n", is_sorted(&seqs[i]));
    }

    exit(EXIT_SUCCESS);
}
