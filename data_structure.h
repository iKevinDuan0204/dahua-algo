#ifndef TEST_LIB_DAHUA_ALGO_DATA_STRUCTURE_H
#define TEST_LIB_DAHUA_ALGO_DATA_STRUCTURE_H

#define TRUE 1
#define FALSE 0
typedef int flag;

#define MAXSIZE 1000
typedef int number;
typedef struct {
    number num[MAXSIZE + 1];
    int size;
}num_seq;

#endif
