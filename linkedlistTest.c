#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    listT *l = malloc(sizeof(listT));
    l->head = NULL;
    l->tail = NULL;
    l->totalNodes = 0;

    //    insert(l, 1, 46);
    //  prepend(l, 3);

    append(l, 1);
    append(l, 2);
    append(l, 4);
    append(l, 3);
    append(l, 6);
    append(l, 5);
    /*   insert(l, 5, 50);
   insert(l, 1, 2);
   insert(l, 1, 1);
   insert(l, 3, 51);
   insert(l, l->totalNodes + 1, 12);
   insert(l, 11, 11);
   insert(l, 21, 13);

// removeNode(l, 3);
//  display(l);
// reverse(l);
// display(l);

// bubble(l);
// display(l);
*/
    append(l, 1);
    append(l, 2);
    append(l, 4);
    append(l, 3);
    // append(l, 1);
    append(l, 5);
    display(l);
    printf("======================\n");
    bubble(l);
    display(l);
}
