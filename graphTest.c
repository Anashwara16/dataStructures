#include "graph.h"
#include "utils.h"

int main() {
    graphT *graph = createGraph(7);
    startDotFile("./bld/graph.dot");
    /*
    insertInt(graph, 0, 2, 20);
    insertInt(graph, 1, 3, 30);
    insertInt(graph, 2, 4, 40);
    insertInt(graph, 3, 5, 50);
    insertInt(graph, 3, 5, 50);
    displayGraphInt(graph);
    displayGraph(graph);
    */
    insert(graph, 'E', 'G', 10);
    insert(graph, 'E', 'B', 20);
    insert(graph, 'E', 'C', 30);
    insert(graph, 'F', 'A', 40);
    insert(graph, 'G', 'B', 50);
    //    displayGraph(graph);
    displayDotGraph(graph);
    endDotFile("./bld/graph.dot");
}
