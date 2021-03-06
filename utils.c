#include <stdio.h>

void writeDotFile(char *filename, char *buffer) {

    FILE *fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("FILE NOT OPENED \n");
    }
    fprintf(fp, "%s\n", buffer);

    fclose(fp);
}

void startDotFile(char *filename) {

    FILE *fp = fopen(filename, "a");
    fprintf(fp, "digraph { \n");
    fprintf(fp, "\trankdir=TB \n");
    fclose(fp);
}

void endDotFile(char *filename) {

    FILE *fp = fopen(filename, "a");
    fprintf(fp, "}");
    fclose(fp);
}

void swapint(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
