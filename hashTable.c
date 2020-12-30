#include "hashTable.h"

hashT *createHash(int capacity) {
    hashT *hash = malloc(sizeof(hashT));
    hash->arr = malloc(sizeof(listT *) * capacity);
    hash->maxCapacity = capacity;
    for (int i = 0; i < capacity; i++) {
        hash->arr[i] = createList();
    }
    return hash;
}

listT *createList() {
    listT *l = malloc(sizeof(listT));
    l->head = NULL;
    l->tail = NULL;
    l->totalNodes = 0;
    return l;
}

void append(listT *l, int key, int value) {
    nodeT *newNode = malloc(sizeof(nodeT));
    newNode->key = key;
    newNode->val = value;
    newNode->next = NULL;
    // If there are zero nodes
    if (l->head == NULL) {
        l->head = newNode;
        l->tail = newNode;
    } else {
        l->tail->next = newNode;
        l->tail = newNode;
    }
    l->totalNodes++;
}

int hashFunction(hashT *hash, int key) { return (key % (hash->maxCapacity)); }

void insertHash(hashT *hash, int key, int value) {
    int index = hashFunction(hash, key);
    append(hash->arr[index], key, value);
}

void search(hashT *hash, int key, int value) {
    int index = hashFunction(hash, key);
    searchList(hash->arr[index], key, value);
}

void searchList(listT *l, int key, int value) {
    nodeT *cur = l->head;
    while (cur != NULL) {
        if (cur->key == key && cur->val == value) {
            printf("Found \n");
            return;
        }
        cur = cur->next;
    }
    printf("Not found \n");
}

void display(listT *l) {
    nodeT *cur = l->head;
    while (cur != NULL) {
        printf("\t(%d, %d)", cur->key, cur->val);
    }
    cur = cur->next;
}

void displayHash(hashT *hash) {
    for (int i = 0; i < hash->maxCapacity; i++) {
        printf("%d -> \t", i);
        display(hash->arr[i]);
        printf("\n");
    }
}
