#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node nodeT;

struct tree {
    struct node *root;
    struct node *parent;
    struct node *current;
    int totalNodes;
};

typedef struct tree treeT;

void add(treeT *t, int data);
typedef void (*displayFn)(nodeT *newRoot, int space);
void preorderTraversal(nodeT *newRoot, int space, displayFn func);
void postorderTraversal(nodeT *newRoot, int space);
void inorderTraversal(nodeT *newRoot, int space);
void search(nodeT *newRoot, int data);
void displayTree(nodeT *newRoot, int space);
void displayDot(nodeT *newRoot, int space);

/*
insert() 	− Inserts an element in a tree/create a tree.
delete() 	− Deletes an element in a tree/delete a tree.
search() 	− Searches an element in a tree.
preorder() 	− Traverses a tree in a pre-order manner.
inorder() 	− Traverses a tree in an in-order manner.
postorder() − Traverses a tree in a post-order manner.
height()    - Count of the longest path
*/
