// Compile this assignment with: gcc main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_graph.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.

int main(int argc, const char * argv[]) {
    graph_t * graph = create_graph();
    graph_add_node(graph, 1);
    graph_add_node(graph, 1);
    graph_add_node(graph, 2);
    graph_add_node(graph, 3);
    graph_add_node(graph, 0);
    graph_add_node(graph, 4);

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 1, 2);
    graph_add_edge(graph, 2, 3);
    graph_add_edge(graph, 3, 3);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 2, 0);

    graph_add_edge(graph, 3, 1);
    graph_remove_edge(graph, 3, 1);

    graph_node_t* fNode = find_node(graph, 4);
    printf("Found node %d\n", fNode->data);
    graph_remove_node(graph, 4);
    if (find_node(graph, 4) == NULL) {
        printf("Successfully removed node 4\n");
    }
    printf("total nodes: %d\n", graph_num_nodes(graph));
    printf("total edges: %d\n", graph_num_edges(graph));
    return 0;
}
