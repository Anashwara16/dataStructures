#ifndef QUEUE_H
#define QUEUE_H

#include "linkedlist.h"
#include <stdbool.h>

struct queue {
    nodeT *front;
    nodeT *rear;
    listT *l;
    int totalNodes;
    int maxNodes;
};

typedef struct queue queueT;

queueT *createQueue();
void enqueue(queueT *q, int value);
void displayQueue(queueT *q);
void dequeue(queueT *q);
bool isFull(queueT *q);
bool isEmpty(queueT *q);

#endif /* QUEUE_H */
