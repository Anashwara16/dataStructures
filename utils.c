#include <stdio.h>

void writeDotFile(char *filename, char *buffer) {

    FILE *fp = fopen(filename, "a");
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
