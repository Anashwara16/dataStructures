#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

struct maxheap {
    int *arr;
    int maxCapacity;
    int totalNodes;
};

typedef struct maxheap maxheapT;

maxheapT *createHeap(int capacity);
void insert(maxheapT *maxh, int value);
void displayDot(maxheapT *maxh);
void displayHeap(maxheapT *maxh);
void getMax(maxheapT *maxh);
void getMin(maxheapT *maxh);
void heapify(maxheapT *maxh, int par);
void extractMax(maxheapT *maxh);
/*
insert() 	− Inserts an element in a tree/create a tree.
delete() 	− Deletes an element in a tree/delete a tree.
search() 	− Searches an element in a tree.
preorder() 	− Traverses a tree in a pre-order manner.
inorder() 	− Traverses a tree in an in-order manner.
postorder() − Traverses a tree in a post-order manner.
height()    - Count of the longest path
*/
