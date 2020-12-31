#include "linkedlist.h"

listT *createList() {
    listT *l = malloc(sizeof(listT));
    l->head = NULL;
    l->tail = NULL;
    l->totalNodes = 0;
    return l;
}

void append(listT *l, int value) {
    nodeT *newNode = malloc(sizeof(nodeT));
    newNode->data = value;
    newNode->next = NULL;

    // If there are zero nodes
    if (l->head == NULL) {
        l->head = newNode;
        l->tail = newNode;
    }

    else {
        l->tail->next = newNode;
        l->tail = newNode;
    }

    l->totalNodes++;
}

void prepend(listT *l, int value) {
    nodeT *newNode = malloc(sizeof(nodeT));
    newNode->data = value;
    newNode->next = NULL;

    // If there are no nodes
    if (l->head == NULL) {
        l->head = newNode;
        l->tail = newNode;
    }

    else {
        newNode->next = l->head;
        l->head = newNode;
    }

    l->totalNodes++;
}

void display(listT *l) {
    printf("\n");
    nodeT *cur = l->head;
    while (cur != NULL) {
        if (cur->next == NULL) {
            printf("%d \t", cur->data);
        } else {
            printf("%d -> \t", cur->data);
        }
        cur = cur->next;
    }
    printf("\n");
}

void insert(listT *l, int pos, int value) {
    if (pos == 1) {
        prepend(l, value);
        return;
    }
    if (pos >= l->totalNodes) {
        append(l, value);
        return;
    }
    nodeT *newNode = malloc(sizeof(nodeT));
    newNode->data = value;
    newNode->next = NULL;
    int i = 0;
    int number = 0;

    nodeT *prev = l->head;
    nodeT *cur = l->head->next;

    while (i < (pos - 2)) {
        prev = prev->next;
        cur = cur->next;
        i++;
    }

    prev->next = newNode;
    newNode->next = cur;

    l->totalNodes++;
}

void removeNode(listT *l, int pos) {
    nodeT *previous = NULL;
    nodeT *current = l->head;
    int i = 1;
    if (pos == 1) {
        free(current);
        l->totalNodes--;
        l->head = current->next;
        return;
    }
    while (i < pos) {
        previous = current;
        current = current->next;
        i++;
    }
    previous->next = current->next;
    free(current);

    if (pos == l->totalNodes) {
        l->tail = previous;
    }
    l->totalNodes--;
}

void clear(listT *l) {
    for (int i = 1; i <= l->totalNodes; i++) {
        removeNode(l, i);
    }
}

unsigned int count(listT *l) { return l->totalNodes; }

void extend(listT *l1, listT *l2) {
    unsigned int l2NodeCnt = count(l2);
    l1->tail->next = l2->head;
    l1->totalNodes += l2NodeCnt;
}

void reverse(listT *l) {

    nodeT *previous = NULL;
    nodeT *current = l->head;
    nodeT *temp = NULL;
    l->tail = l->head;

    while (current != NULL) {

        temp = current->next;
        current->next = previous;
        previous = current;
        current = temp;
    }

    l->head = previous;
}

/*
void swap(nodeT **a, nodeT **b) {
    nodeT *temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void swapint(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
*/

void bubble(listT *l) {
    nodeT *previous;
    nodeT *current;
    int temp;

    for (int i = 0; i <= l->totalNodes; i++) {
        previous = l->head;
        current = l->head->next;
        while (current != NULL) {

            if (previous->data > current->data) {
                swapint(&previous->data, &current->data);
            }

            previous = previous->next;
            current = current->next;
        }
    }
}

void bubbleSort(listT *l) {
    int i, j, swapped = 0;
    nodeT *tmp = NULL;
    nodeT *p1 = NULL;
    nodeT *p2 = NULL;
    nodeT *h = NULL;
    for (i = 0; i <= l->totalNodes; i++) {
        h = l->head;
        swapped = 0;
        for (j = 0; j < l->totalNodes - i - 1; j++) {
            p1 = l->head;
            p2 = p1->next;
            if (p1->data > p2->data) {
                /* update the link after swapping */
                p2->next = p1;
                p1->next = tmp;
                swapped = 1;
            }
            h = h->next;
        }
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

void splitList(nodeT *head, nodeT *left, nodeT *right) {
    nodeT *p1;
    nodeT *p2;
    p2 = head;
    p1 = head->next;

    while (p1 != NULL) {
        p1 = p1->next;
        if (p1 != NULL) {
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    left = head;
    right = p2->next;
    p2->next = NULL;
}
/*
nodeT *mergeSortedList(nodeT *l1, nodeT *l2) {
    nodeT *result = NULL;
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeSortedList(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSortedList(l1, l2->next);
    }
    return result;
}

void mergeSort(nodeT *node) {
    nodeT *left;
    nodeT *right;

    if ((node == NULL) || (node->next == NULL)) {
        return;
    }

    splitList(node, left, right);

    / Recursively sort the sublists /
    mergeSort(left);
    mergeSort(right);

    / answer = merge the two sorted lists together /
    node = mergeSortedList(left, right);
}*/
