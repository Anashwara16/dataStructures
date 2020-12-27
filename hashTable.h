#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int val;
    struct node *next;
};

typedef struct node nodeT;

struct list {
    nodeT *head;
    nodeT *tail;
    int totalNodes;
};

typedef struct list listT;

struct hashTable {
    listT **arr;
    int maxCapacity;
};

typedef struct hashTable hashT;

hashT *createHash(int capacity);
listT *createList();
void append(listT *l, int key, int value);
void display(listT *l);
void displayHash(hashT *hash);
int hashFunction(hashT *hash, int key);
void insertHash(hashT *hash, int key, int value);
void search(hashT *hash, int key, int value);
void searchList(listT *l, int key, int value);
