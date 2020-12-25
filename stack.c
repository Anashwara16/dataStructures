#include "stack.h"
#include "linkedlist.h"
#include <stdbool.h>
#include <stdlib.h>

stackT *createStack() {
    stackT *s = malloc(sizeof(stackT));
    s->l = malloc(sizeof(listT));
    s->l->head = NULL;
    s->l->tail = NULL;
    s->l->totalNodes = 0;
    s->maxNodes = 5;
    return s;
}

void push(stackT *s, int value) {
    if (isFull(s)) {
        printf("Stack Full \n");
        return;
    }
    prepend(s->l, value);
    s->totalNodes = s->l->totalNodes;
    s->top = s->l->head;
}

bool isFull(stackT *s) { return (s->totalNodes == s->maxNodes) ? true : false; }

bool isEmpty(stackT *s) { return (s->totalNodes == 0) ? true : false; }

void pop(stackT *s) {
    if (isEmpty(s)) {
        printf("Stack Empty \n");
        return;
    }
    removeNode(s->l, 1);
    s->totalNodes = s->l->totalNodes;
    s->top = s->l->head;
}

void displayStack(stackT *s) { display(s->l); }
