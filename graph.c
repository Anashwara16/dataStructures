#include "graph.h"

graphT *createGraph(int capacity) {
    graphT *graph = malloc(sizeof(graphT));
    graph->arr = malloc(capacity * (sizeof(listT)));
    graph->maxCapacity = capacity;
    for (int i = 0; i < capacity; i++) {
        graph->arr[i] = createList();
    }
    return graph;
}

listT *createList() {
    listT *l = malloc(sizeof(listT));
    l->head = NULL;
    l->totalNodes = 0;
    return l;
}

void insertInt(graphT *graph, int v1, int v2, int weight) {
    append(graph->arr[v1], v2, weight);
}

void insert(graphT *graph, char v1, char v2, int weight) {
    insertInt(graph, (int)v1 - 'A', (int)v2 - 'A', weight);
}

void append(listT *l, int v2, int weight) {
    nodeT *newNode = malloc(sizeof(nodeT));
    newNode->v2 = v2;
    newNode->weight = weight;
    newNode->next = NULL;
    nodeT *cur = l->head;

    if (l->head == NULL) {
        l->head = newNode;
        l->totalNodes++;
        return;
    }

    while (cur != NULL) {
        if (cur->next == NULL) {
            cur->next = newNode;
            l->totalNodes++;
            return;
        }
        cur = cur->next;
    }
}

void displayGraph(graphT *graph) {
    for (int i = 0; i < graph->maxCapacity; i++) {
        printf("%c ->", (i + 'A'));
        displayList(graph->arr[i]);
        printf("\n");
    }
}

void displayGraphInt(graphT *graph) {
    for (int i = 0; i < graph->maxCapacity; i++) {
        printf("%d -> ", i);
        displayListInt(graph->arr[i]);
        printf("\n");
    }
}

void displayList(listT *l) {
    nodeT *cur = l->head;
    while (cur != NULL) {
        printf("\t (%c, %d)", ((cur->v2) + 'A'), cur->weight);
        cur = cur->next;
    }
}

void displayListInt(listT *l) {
    nodeT *cur = l->head;
    while (cur != NULL) {
        printf("\t (%d, %d)", cur->v2, cur->weight);
        cur = cur->next;
    }
}

void displayDotGraph(graphT *graph) {
    FILE *fp = fopen("./bld/graph.dot", "a");

    for (int i = 0; i < (graph->maxCapacity); i++) {
        nodeT *cur = graph->arr[i]->head;
        while (cur != NULL) {
            fprintf(fp, "\t %c -> %c [label = %d, weight = %d]\n", (i + 'A'),
                    ((cur->v2) + 'A'), cur->weight, cur->weight);
            cur = cur->next;
            fprintf(fp, "\n");
        }
    }
    fprintf(fp, "\n ");
    fclose(fp);
}
/*
void displayDotList(listT *l) {
    nodeT *cur = l->head;
    while (cur != NULL) {
        printf("\t %c [label = %d, weight = %d}\n", ((cur->v2) + 'A'),
               cur->weight, cur->weight);
        cur = cur->next;
    }
}
*/
