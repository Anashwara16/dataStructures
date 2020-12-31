#include "mergeSort.h"
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    listT *l = createList();
    append(l, 1);
    append(l, 4);
    append(l, 2);
    append(l, 5);
    append(l, 1);
    append(l, 4);
    append(l, 2);
    append(l, 5);
    display(l);
    mergeSort(l, 0, 7);
    display(l);
}
