#include "hashTable.h"

int main() {

    hashT *hash = createHash(10);

    insertHash(hash, 1, 2);
    insertHash(hash, 1, 2);
    insertHash(hash, 1, 3);
    insertHash(hash, 3, 4);
    insertHash(hash, 5, 6);
    insertHash(hash, 7, 8);
    insertHash(hash, 9, 10);
    insertHash(hash, 11, 12);
    insertHash(hash, 13, 14);
    insertHash(hash, 15, 16);
    insertHash(hash, 17, 18);
    insertHash(hash, 19, 20);
    insertHash(hash, 21, 22);
    insertHash(hash, 42, 56);
    insertHash(hash, 50, 54);
    insertHash(hash, 44, 6);
    insertHash(hash, 56, 8);
    insertHash(hash, 58, 10);
    displayHash(hash);
    search(hash, 1, 2);
}
