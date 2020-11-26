#include "linkedlist.h"

#include <stdlib.h>

void append(listT *l, int value)
{
    nodeT *temp = malloc(sizeof(nodeT));
    temp->data = value;
    temp->next = NULL;
    if (l->head == NULL)
    {
        l->head = temp;
        l->tail = temp;
        temp = NULL;
    }
    else
    {
        l->tail->next = temp;
        l->tail = temp;
    }
    l->totalNodes++;
}

void display(listT *l)
{
    nodeT *temp = malloc(sizeof(nodeT));
    temp = l->head;
    while (temp != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
}

void insert(listT *l, int pos, int value)
{
    nodeT *pre = malloc(sizeof(nodeT));
    nodeT *cur = malloc(sizeof(nodeT));
    nodeT *temp = malloc(sizeof(nodeT));
    cur = l->head;
    for (int i = 1; i < pos; i++)
    {
        pre = cur;
        cur = cur->next;
    }
    temp->data = value;
    pre->next = temp;
    temp->next = cur;
}

void removeNode(listT *l, int pos)
{
    nodeT *previous = l->head;
    nodeT *current = l->head->next;
    current = l->head;
    for (int i = 1; i < pos; i++)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
}

void clear(listT *l)
{
    for (int i = 1; i <= l->totalNodes; i++)
    {
        removeNode(l, i);
    }
}

unsigned int count(listT *l)
{
    return l->totalNodes;
}

void extend(listT *l1, listT *l2)
{
    unsigned int l2NodeCnt = count(l2);
    l1->tail->next = l2->head;
    l1->totalNodes += l2NodeCnt;
}

void reverse(listT *l)
{
    nodeT *prev = NULL;
    nodeT *next = NULL;
    nodeT *current = l->head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
}

void bubbleSort(listT *l)
{
    int i, j, swapped = 0;
    nodeT *tmp = NULL;
    nodeT *p1 = NULL;
    nodeT *p2 = NULL;
    nodeT *h = NULL;
    for (i = 0; i <= l->totalNodes; i++)
    {
        h = l->head;
        swapped = 0;
        for (j = 0; j < l->totalNodes - i - 1; j++)
        {
            p1 = l->head;
            p2 = p1->next;
            if (p1->data > p2->data)
            {
                /* update the link after swapping */
                p2->next = p1;
                p1->next = tmp;
                swapped = 1;
            }
            h = h->next;
        }
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

void splitList(nodeT *head, nodeT *left, nodeT *right)
{
    nodeT *p1;
    nodeT *p2;
    p2 = head;
    p1 = head->next;

    while (p1 != NULL)
    {
        p1 = p1->next;
        if (p1 != NULL)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
    }
    left = head;
    right = p2->next;
    p2->next = NULL;
}

nodeT *mergeSortedList(nodeT *l1, nodeT *l2)
{
    nodeT *result = NULL;
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    if (l1->data <= l2->data)
    {
        result = l1;
        result->next = mergeSortedList(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = mergeSortedList(l1, l2->next);
    }
    return result;
}

void mergeSort(nodeT *node)
{
    nodeT *left;
    nodeT *right;

    if ((node == NULL) || (node->next == NULL))
    {
        return;
    }

    splitList(node, left, right);

    /* Recursively sort the sublists */
    mergeSort(left);
    mergeSort(right);

    /* answer = merge the two sorted lists together */
    node = mergeSortedList(left, right);
}
