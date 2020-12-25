#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    stackT *s = createStack();
    push(s, 10);
    push(s, 9);
    push(s, 8);
    push(s, 7);
    push(s, 6);
    push(s, 5);
    push(s, 4);
    push(s, 3);
    push(s, 2);
    push(s, 1);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
    pop(s);
    displayStack(s);
}
