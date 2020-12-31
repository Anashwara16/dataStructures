#ifndef MERGESORT_H
#define MERGESORT_H
#include "linkedlist.h"
#include "utils.h"

void mergeSort(listT *l, int first, int last);
void merge(listT *l, int first, int m, int last);
void printArray(listT *l, int size);
void copyList(listT *src, listT *dest, int start, int end);
#endif /* MERGESORT_H */
