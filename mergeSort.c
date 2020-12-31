#include "mergeSort.h"

void mergeSort(listT *l, int first, int last) {
    if (first < last) {
        int mid = (first + last - 1) / 2;
        printf("%d \t", first);
        printf("%d \t", mid);
        printf("%d \n", last);

        display(l);
        mergeSort(l, first, mid);
        mergeSort(l, mid + 1, last);
        merge(l, first, mid, last);
        display(l);
        // printArray(l, (l->totalNodes));
    }
}

void merge(listT *l, int first, int mid, int last) {
    int n1 = mid - first + 1;
    int n2 = last - mid;
    listT *left = createList();
    listT *right = createList();
    printf("In merge\n");
    copyList(l, left, first, n1);
    copyList(l, right, (mid + 1), n2);

    printf("%d \t %d \t %d \n", first, mid, last);

    int i = 0, j = 0, k = first;
    int p = 0;

    nodeT *curLeft = left->head;
    nodeT *curRight = right->head;
    nodeT *curL = l->head;

    while (curL != NULL && p < k) {
        curL = curL->next;
        p++;
    }

    while (i < n1 && j < n2) {
        if (curLeft->data <= curRight->data) {
            curL->data = curLeft->data;
            i++;
            curLeft = curLeft->next;
        } else {
            curL->data = curRight->data;
            j++;
            curRight = curRight->next;
        }
        k++;
        curL = curL->next;
    }
    while (i < n1) {
        curL->data = curLeft->data;
        i++;
        k++;
        curLeft = curLeft->next;
        curL = curL->next;
    }
    while (j < n2) {
        curL->data = curRight->data;
        j++;
        k++;
        curRight = curRight->next;
        curL = curL->next;
    }
    printf("End merge\n");
}

void copyList(listT *src, listT *dest, int start, int count) {
    nodeT *srcCur = src->head;
    int i = 0;

    while (srcCur != NULL && i < start) {
        srcCur = srcCur->next;
        i++;
    }
    i = 0;

    while (srcCur != NULL && i < count) {
        int data = srcCur->data;
        append(dest, data);
        i++;
        srcCur = srcCur->next;
    }
}

void printArray(listT *l, int size) {
    nodeT *cur = l->head;
    for (int i = 0; i <= size; i++) {
        printf("%d \t", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
