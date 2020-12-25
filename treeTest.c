#include "tree.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    treeT *t = malloc(sizeof(treeT));
    t->root = NULL;
    t->totalNodes = 0;

    startDotFile("./bld/treeDot.dot");

    add(t, 7);
    add(t, 0);
    add(t, 3);
    add(t, 2);
    add(t, 5);
    add(t, 1);
    add(t, 8);
    add(t, 9);
    preorderTraversal(t->root, 0, displayDot);
    preorderTraversal(t->root, 0, displayTree);
    /*
     postorderTraversal(t->root, 0);
     inorderTraversal(t->root, 0);
     search(t->root, 3);
     search(t->root, 9);
     */
    endDotFile("./bld/treeDot.dot");
}
