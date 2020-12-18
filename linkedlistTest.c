#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    listT *l = malloc(sizeof(listT));
    l->head = NULL;
    l->tail = NULL;
    l->totalNodes = 0;

    insert(l, 1, 46);
    prepend(l, 3);
    append(l, 4);
    append(l, 5);
    append(l, 6);
    append(l, 7);
    append(l, 8);
    append(l, 9);
    insert(l, 5, 50);
    insert(l, 1, 2);
    insert(l, 1, 1);
    insert(l, 3, 51);
    insert(l, l->totalNodes + 1, 12);
    insert(l, 11, 11);
    insert(l, 21, 13);
    display(l);
}
