#ifndef STACK_H
#define STACK_H

#include "linkedlist.h"
#include <stdbool.h>
struct stack {
    nodeT *top;
    listT *l;
    int totalNodes;
    int maxNodes;
};

typedef struct stack stackT;

stackT *createStack();
void push(stackT *s, int value);
void pop(stackT *s);
bool isFull(stackT *s);
bool isEmpty(stackT *s);

void displayStack(stackT *s);

/*
push( int );
pop( int );
peek();
display();
isFull();
isEmpty();
*/
#endif /* STACK_H */
