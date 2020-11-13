#include "linkedlist.h"

void createnode(int value) {
  node *head = NULL;
  node *tail = NULL;
  node *temp = new node;
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
  node *head = NULL;
  node *tail = NULL;
  node *temp = new node;
  temp = head;
  while (temp != NULL) {
    printf( "%d \t", temp->data );
    temp = temp->next;
  }
}

void insert_start(int value) {
  node *head = NULL;
  node *tail = NULL;
  node *temp = new node;
  temp->data = value;
  temp->next = head;
  head = temp;
}

void insert_position(int pos, int value) {
  node *head = NULL;
  node *tail = NULL;
  node *pre = new node;
  node *cur = new node;
  node *temp = new node;
  cur = head;
  for (int i = 1; i < pos; i++) {
    pre = cur;
    cur = cur->next;
  }
  temp->data = value;
  pre->next = temp;
  temp->next = cur;
}

void delete_first() {
  node *head = NULL;
  node *tail = NULL;
  node *temp = new node;
  temp = head;
  head = head->next;
  delete temp;
}

void delete_last() {
  node *head = NULL;
  node *tail = NULL;
  node *current = new node;
  node *previous = new node;
  current = head;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  tail = previous;
  previous->next = NULL;
  delete current;
}

void delete_position(int pos) {
  node *head = NULL;
  node *tail = NULL;
  node *current = new node;
  node *previous = new node;
  current = head;
  for (int i = 1; i < pos; i++) {
    previous = current;
    current = current->next;
  }
  previous->next = current->next;
}
