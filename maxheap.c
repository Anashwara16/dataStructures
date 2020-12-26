#include "maxheap.h"

maxheapT *createHeap(int capacity) {
    maxheapT *maxh = malloc(sizeof(maxheapT));
    maxh->arr = malloc((sizeof(int)) * capacity);
    maxh->maxCapacity = capacity;
    maxh->totalNodes = 0;
    return maxh;
}

int parent(int k) { return ((k - 1) / 2); }

int leftChild(int k) { return ((2 * k) + 1); }

int rightChild(int k) { return ((2 * k) + 2); }

void insert(maxheapT *maxh, int value) {
    printf("\n==============================\n");
    if (maxh->totalNodes == maxh->maxCapacity) {
        printf("Reached max. \n");
        return;
    }
    displayHeap(maxh);
    maxh->arr[maxh->totalNodes] = value;
    maxh->totalNodes++;
    int cur = maxh->totalNodes - 1;
    int par = parent(cur);
    while (cur > 0) {
        if ((maxh->arr[cur]) > (maxh->arr[par])) {
            maxh->arr[par];
            swapint(&maxh->arr[cur], &maxh->arr[par]);
            maxh->arr[par];
        }
        cur = par;
        par = parent(cur);
    }
}

void getMax(maxheapT *maxh) { printf("Max number: %d \n", maxh->arr[0]); }

void getMin(maxheapT *maxh) {
    /*
    for (int cur = 0; cur < (maxh->totalNodes / 2); cur++) {
        fprintf(fp, "\t%d -> { %d %d };\n", maxh->arr[cur],
                maxh->arr[leftChild(cur)], maxh->arr[rightChild(cur)]);
*/

    printf("Min number: %d \n", maxh->arr[maxh->totalNodes - 1]);
}

void heapify(maxheapT *maxh, int par) {
    int l = leftChild(par);
    int r = rightChild(par);

    int largest = par;

    if ((l > maxh->totalNodes) && (maxh->arr[largest]) > (maxh->arr[l])) {
        largest = l;
    }
    if ((r > maxh->totalNodes) && (maxh->arr[largest]) > (maxh->arr[r])) {
        largest = r;
    }
    if (largest != par) {
        swapint(&maxh->arr[par], &maxh->arr[largest]);
        heapify(maxh, largest);
    }
}

void extractMax(maxheapT *maxh) {

    if (maxh->totalNodes == 0) {
        printf("No elements in heap! \n");
        return;
    }
    if (maxh->totalNodes == 1) {
        printf("Extracted max node: %d \n", maxh->arr[0]);
        maxh->totalNodes--;
        return;
    }
    printf("Extracted max node: %d \n", maxh->arr[0]);
    maxh->arr[0] = maxh->arr[maxh->totalNodes - 1];
    maxh->totalNodes--;
    heapify(maxh, 0);
    return;
}

void displayDot(maxheapT *maxh) {
    FILE *fp = fopen("./bld/maxHeap.dot", "a");

    for (int cur = 0; cur < (maxh->totalNodes / 2); cur++) {
        fprintf(fp, "\t%d -> { %d %d };\n", maxh->arr[cur],
                maxh->arr[leftChild(cur)], maxh->arr[rightChild(cur)]);
    }
    fprintf(fp, "\n ");
    fclose(fp);
}

void displayHeap(maxheapT *maxh) {
    printf("\n");
    for (int cur = 0; cur < maxh->totalNodes; cur++) {
        printf("%d\t", maxh->arr[cur]);
    }
    printf("\n");
}
