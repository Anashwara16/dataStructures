#include "tree.h"
#include "utils.h"
#include <stdlib.h>
#define TABSPACE 4

void add(treeT *t, int data) {
    nodeT *newNode = malloc(sizeof(nodeT));

    struct node *current;
    struct node *parent;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (t->root == NULL) {
        t->root = newNode;
        return;
    }

    parent = t->root;

    while (1) {
        if (data > parent->data) {
            // Check if the parent's right is empty
            if (parent->right == NULL) {
                // Insert here
                parent->right = newNode;
                t->totalNodes++;
                return;
            } else {
                parent = parent->right;
            }
        } else {
            if (parent->left == NULL) {
                parent->left = newNode;
                t->totalNodes++;
                return;
            }
            parent = parent->left;
        }
    }
}

void search(nodeT *newRoot, int data) {
    struct node *current = newRoot;
    printf("Search:");

    while (1) {
        if (!current) {
            printf("Value not present \n");
            return;
        }
        if (current->data == data) {
            printf("Value is present in tree \n");
            return;
        } else {
            if (current->data > data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
}

void displayTree(nodeT *newRoot, int space) {

    printf("\n ");
    for (int i = 0; i < space; i++) {
        printf("\t");
    }
    printf("%d ", newRoot->data);
    printf("\n ");
}

void displayDot(nodeT *newRoot, int space) {
    FILE *fp = fopen("./bld/treeDot.dot", "a");
    if (newRoot->left != NULL && newRoot->right != NULL) {
        fprintf(fp, "\t%d -> { %d %d };", newRoot->data, newRoot->left->data,
                newRoot->right->data);
    } else if (newRoot->left != NULL) {
        fprintf(fp, "\t%d -> %d;", newRoot->data, newRoot->left->data);
    } else if (newRoot->right != NULL) {
        fprintf(fp, "\t%d -> %d;", newRoot->data, newRoot->right->data);
    } else {
        return;
    }
    fprintf(fp, "\n ");
    fclose(fp);
}

void preorderTraversal(nodeT *newRoot, int space, displayFn func) {
    if (newRoot != NULL) {
        func(newRoot, space);
        space += 1;
        preorderTraversal(newRoot->left, space, func);
        preorderTraversal(newRoot->right, space, func);
    }
}

void inorderTraversal(nodeT *newRoot, int space) {

    if (newRoot != NULL) {
        printf("\n ");
        for (int i = 0; i < space; i++) {
            printf("\t");
        }
        space += 1;
        inorderTraversal(newRoot->left, space);
        printf("%d ", newRoot->data);
        printf("\n ");
        inorderTraversal(newRoot->right, space);
    }
}

void postorderTraversal(nodeT *newRoot, int space) {

    if (newRoot != NULL) {
        printf("\n ");
        for (int i = 0; i < space; i++) {
            printf("\t");
        }
        space += 1;
        postorderTraversal(newRoot->left, space);
        postorderTraversal(newRoot->right, space);
        printf("%d ", newRoot->data);
        printf("\n ");
    }
}
