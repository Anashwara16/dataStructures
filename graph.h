#include <stdio.h>
#include <stdlib.h>

struct node {
    int v2;
    int weight;
    struct node *next;
};

typedef struct node nodeT;

struct list {
    nodeT *head;
    int totalNodes;
};

typedef struct list listT;

struct graph {
    listT **arr;
    int maxCapacity;
};

typedef struct graph graphT;

graphT *createGraph(int capacity);
listT *createList();
void insert(graphT *graph, char v1, char v2, int weight);
void insertInt(graphT *graph, int v1, int v2, int weight);
void append(listT *l, int v2, int weight);
void displayGraph(graphT *graph);
void displayList(listT *l);
void displayGraphInt(graphT *graph);
void displayListInt(listT *l);
void displayDotGraph(graphT *graph);
void displayDotList(listT *l);

/* Adjacency List Implementation
addVertex()
addEdge()
breadthFirstSearch()
depthFirstSearch()
cyclePresent()
void displayDot(graphT *graph);
*/
