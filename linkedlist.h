#include <stdio.h>

struct node {
  int data;
  struct node *next;
};

struct list {
  struct node *head;
  struct node *tail;
  int count;
};

void createnode(int value);
