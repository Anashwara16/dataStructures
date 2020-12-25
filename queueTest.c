#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    queueT *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 9);
    enqueue(q, 8);
    enqueue(q, 7);
    enqueue(q, 6);
    enqueue(q, 5);
    enqueue(q, 4);
    enqueue(q, 3);
    enqueue(q, 2);
    displayQueue(q);
    enqueue(q, 1);
    displayQueue(q);
    dequeue(q);
    displayQueue(q);
}
