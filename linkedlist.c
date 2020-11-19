#include "linkedlist.h"
#include <stdlib.h>

void append(int value) {
  nodeT *head = NULL;
  nodeT *tail = NULL;
  nodeT *temp = malloc( sizeof( nodeT ) );
  temp->data = value;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
    tail = temp;
    temp = NULL;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void display() {
  nodeT *head = NULL;
  nodeT *tail = NULL;
  nodeT *temp = malloc( sizeof( nodeT ) );
  temp = head;
  while (temp != NULL) {
    printf( "%d \t", temp->data );
    temp = temp->next;
  }
}

void insert(int pos, int value) {
  nodeT *head = NULL;
  nodeT *tail = NULL;
  nodeT *pre = malloc( sizeof( nodeT ) );
  nodeT *cur = malloc( sizeof( nodeT ) );
  nodeT *temp = malloc( sizeof( nodeT ) );
  cur = head;
  for (int i = 1; i < pos; i++) {
    pre = cur;
    cur = cur->next;
  }
  temp->data = value;
  pre->next = temp;
  temp->next = cur;
}

void removeNode(listT l, int pos) {
  nodeT *head = NULL;
  nodeT *tail = NULL;
  nodeT *current = malloc( sizeof( nodeT ) );
  nodeT *previous = malloc( sizeof( nodeT ) );
  current = head;
  for (int i = 1; i < pos; i++) {
    previous = current;
    current = current->next;
  }
  previous->next = current->next;
}
