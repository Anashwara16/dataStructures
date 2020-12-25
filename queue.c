#include "queue.h"
#include "linkedlist.h"
#include <stdbool.h>
#include <stdlib.h>

queueT *createQueue() {
    queueT *q = malloc(sizeof(queueT));
    q->l = malloc(sizeof(listT));
    q->l->head = NULL;
    q->l->tail = NULL;
    q->l->totalNodes = 0;
    q->maxNodes = 10;
    return q;
}

void enqueue(queueT *q, int value) {

    if (isFull(q)) {
        printf("Queue Full \n");
        return;
    }

    append(q->l, value);
    q->totalNodes = q->l->totalNodes;
    q->front = q->l->head;
    q->rear = q->l->tail;
}

bool isFull(queueT *q) { return (q->totalNodes == q->maxNodes) ? true : false; }

bool isEmpty(queueT *q) { return (q->totalNodes == 0) ? true : false; }

void dequeue(queueT *q) {
    if (isEmpty(q)) {
        printf("Queue Empty \n");
        return;
    }
    removeNode(q->l, 1);
    q->totalNodes = q->l->totalNodes;
    q->front = q->l->head;
    q->rear = q->l->tail;
}

void displayQueue(queueT *q) { display(q->l); }
