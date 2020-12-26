#include "maxheap.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    maxheapT *maxh = createHeap(10);
    startDotFile("./bld/maxHeap.dot");
    insert(maxh, 7);
    insert(maxh, 0);
    insert(maxh, 3);
    insert(maxh, 2);
    insert(maxh, 5);
    insert(maxh, 1);
    insert(maxh, 8);
    insert(maxh, 9);
    displayHeap(maxh);
    displayDot(maxh);
    getMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    extractMax(maxh);
    endDotFile("./bld/maxHeap.dot");
}
