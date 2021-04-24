// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
// Create a graph data structure
typedef struct graph{
    int numNodes;
    int numEdges;
    dll_t* nodes;     //an array of nodes storing all of our nodes.
}graph_t;

typedef struct graph_node{
    int data;
    bool visited;
    dll_t* inNeighbors;
    dll_t* outNeighbors;
}graph_node_t;

// Frees a graph node and both its neighbor lists
void free_node(graph_node_t* node) {
    if (node == NULL) {
        return;
    }
    free_dll(node->inNeighbors);
    free_dll(node->outNeighbors);
    free(node);
}

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t* create_graph(){
    // Modify the body of this function as needed.
    graph_t* myGraph= malloc(sizeof(graph_t));
    if (myGraph == NULL) {
        return NULL;
    }
    myGraph->nodes = create_dll();
    myGraph->numEdges = 0;
    myGraph->numNodes = 0;
    return myGraph;
}

// Returns the node pointer if the node exists.
// Returns NULL if the node doesn't exist or the graph is NULL
graph_node_t* find_node( graph_t * g, int value){
    if (g == NULL) {
       return NULL;
    }
    int i;
    for (i = 0; i < g->nodes->count; i++) {
        graph_node_t* gNode = dll_get(g->nodes, i);
        if (gNode != NULL) {
            if (gNode->data == value) {
                return gNode;
            }
        }
    }
    return NULL;
}

// Creates a graph node
// Note: This relies on your dll implementation.
graph_node_t * create_graph_node(int value){
    graph_node_t * graph_node = malloc(sizeof(graph_node_t));
    
    if ( graph_node == NULL ) return NULL;
    
    graph_node->data = value;
    graph_node->visited = false;
    graph_node->inNeighbors = create_dll();
    graph_node->outNeighbors = create_dll();
    
    return graph_node;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node already exists )
// Returns -1 if the graph is NULL.
int graph_add_node(graph_t* g, int value){
    if ( g == NULL ) return -1;
    
    if (find_node(g, value) != NULL) return 0;
    
    graph_node_t * newNode = create_graph_node(value);
    if ( newNode == NULL ) return -1;
    
    assert(g->nodes);
    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    
    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the node doesn't exist )
// Returns -1 if the graph is NULL.
int graph_remove_node(graph_t* g, int value){
    // The function removes the node from the graph along with any edges associated with it.
    // That is, this node would have to be removed from all the in and out neighbor's lists that countain it.
    if (g == NULL) {
        return -1;
    }
    graph_node_t* gNode = find_node(g, value);
    if (gNode == NULL) {
        return 0;
    }
    
    int i;
    int j;
    graph_node_t* in;
    graph_node_t* out;
    // remove this node from the out list of each in neighbor
    for (i=0; i < gNode->inNeighbors->count; i++) {
       in = dll_get(gNode->inNeighbors, i);
       for (j=0; j < in->outNeighbors->count; j++) {
            graph_node_t* current = dll_get(in->outNeighbors, j);
            if (current->data == value){
                dll_remove(in->outNeighbors, j);
            }
        }
    }

    // remove this node from the in list of each out neighbor
    for (i=0; i< gNode->outNeighbors->count; i++) {
        out = dll_get(gNode->outNeighbors, i);
        for (j=0; j < out->inNeighbors->count; j++) {
            graph_node_t* current = dll_get(out->inNeighbors, j);
            if (current->data == value) {
                dll_remove(out->inNeighbors, j);
            }
        }
    }
    // update the graph
    for (i=0; i<g->nodes->count; i++) {
        graph_node_t* n = dll_get(g->nodes, i);
        if (n->data == value) {
            dll_remove(g->nodes, i);
        }
    }
    g->numNodes--;
    // free this node
    free_node(gNode);
    return 1;
}
    
// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
// Returns -1 if the graph is NULL.
int graph_add_edge(graph_t * g, int source, int destination){
    // The function adds an edge from source to destination but not the other way.
    // Make sure you are not adding the same edge multiple times.
    // Make sure you modify the in and out neighbors appropriatelly. 
    // destination will be an out neighbor of source.
    // Source will be an in neighbor of destination.
    
    if (g == NULL) {
        return -1;
    }
    if (contains_edge(g, source, destination) == 1) {
        return 0;
    }
    graph_node_t* src = find_node(g, source);
    graph_node_t* dest = find_node(g, destination);

    if (src == NULL || dest == NULL) {
        return 0;
    }
    int result1 = dll_push_back(src->outNeighbors, dest);
    int result2 = dll_push_back(dest->inNeighbors, src);
    
    // update the graph
    g->numEdges++;
    return (result1 == 1) && (result2 == 1);
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
// Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t * g, int source, int destination){
    //The function removes an edge from source to destination but not the other way.
    //Make sure you remove destination from the out neighbors of source.
    //Make sure you remove source from the in neighbors of destination.
    if (g == NULL) {
        return -1;
    }
    if (contains_edge(g, source, destination) == 0) {
        return 0;
    }
    graph_node_t* src = find_node(g, source);
    graph_node_t* dest = find_node(g, destination);

    if (src == NULL || dest == NULL) {
        return 0;
    }
    int i;
    // remove dest from src outNeighbors
    for (i=0; i < src->outNeighbors->count; i++) {
        graph_node_t* n = dll_get(src->outNeighbors, i);
        if (n->data == destination) {
            dll_remove(src->outNeighbors, i);
        }
    }
    
    // remove src from dest inNeighbors
    for (i=0; i < dest->inNeighbors->count; i++) {
        graph_node_t* n = dll_get(dest->inNeighbors, i);
        if (n->data == source) {
            dll_remove(dest->inNeighbors, i);
        }
    }

    // update the graph
    g->numEdges--;
    return 1;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist )
// Returns -1 if the graph is NULL.
int contains_edge( graph_t * g, int source, int destination){
    if (g == NULL) {
        return -1;
    }
    graph_node_t* src = find_node(g, source);
    graph_node_t* dest = find_node(g, destination);
    if (src == NULL || dest == NULL) {
        return 0;
    }
    int i;
    int result1 = 0;
    int result2 = 0;
    for (i=0; i < src->outNeighbors->count; i++) {
        graph_node_t* n = dll_get(src->outNeighbors, i);
        if (n->data == destination) {
            result1 = 1;
        }
    }
    for (i=0; i < dest->inNeighbors->count; i++) {
        graph_node_t* n = dll_get(dest->inNeighbors, i);
        if (n->data == source) {
            result2 = 1;
        }
    }
    if (result1 == 1 && result2 == 1) {
        return 1;
    }
    return 0;
}

// Returns dll_t* of all the in neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getInNeighbors( graph_t * g, int value ){
    if (g == NULL) {
        return NULL;
    }
    graph_node_t* gNode = find_node(g, value);
    if (gNode == NULL) {
        return NULL;
    }
    return gNode->inNeighbors;
}

// Returns the number of in neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors( graph_t * g, int value){
    if (g == NULL) {
        return -1;
    }
    dll_t* in = getInNeighbors(g, value);
    if (in == NULL) {
        return -1;
    }
    return in->count;
}

// Returns dll_t* of all the out neighbors of this node.
// Returns NULL if thte node doesn't exist or if the graph is NULL.
dll_t* getOutNeighbors( graph_t * g, int value ){
    if (g == NULL) {
        return NULL;
    }
    graph_node_t* gNode = find_node(g, value);
    if (gNode == NULL) {
        return NULL;
    }
    return gNode->outNeighbors;
}

// Returns the number of out neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors( graph_t * g, int value){
    if (g == NULL) {
        return -1;
    }
    dll_t* out = getOutNeighbors(g, value);
    if (out == NULL) {
        return -1;
    }
    return out->count;
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t* g){
    if (g == NULL) {
        return -1;
    }
    return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t* g){
    if (g == NULL) {
        return -1;
    }
    return g->numEdges;
}
// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the program terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t* g){
    // free each node in the graph
    if (g == NULL) {
        return;
    }
    node_t* iter = g->nodes->head;
    while (iter != NULL) {
        node_t* tmp = iter;
        iter = iter->next;
        free_node(tmp->data);
        free(tmp);
    }
    // free the graph
    free(g->nodes);
    free(g);
}

// Resets all nodes visited status to false.
void reset_visited(graph_t* g) {
    int i;
    for (i = 0; i < g->nodes->count; i++) {
        graph_node_t* gNode = dll_get(g->nodes, i);
        gNode->visited = false;
    }
}

// returns 1 if we can reach the destination from source
// returns 0 if it is not reachable
// returns -1 if the graph is NULL (using BFS)
int is_reachable(graph_t * g, int source, int dest){
    if (g == NULL) {
        return -1;
    }
    if (source == dest) {
        return 1;
    }
    
    graph_node_t* root = find_node(g, source);
    

}

// returns 1 if there is a cycle in the graph
// returns 0 if no cycles exist in the graph
// returns -1 if the graph is NULL 
// You may use either BFS or DFS to complete this task.
int has_cycle(graph_t * g){
    
}

// prints any path from source to destination if there 
// exists a path from the source to the destination.
// Note: Consider using one of the other functions to help you
//       determine if a path exists first
// (Choose either BFS or DFS, typically DFS is much simpler)
//
// Returns 1 if there is a path from source to destination
// Returns 0 if there is not a path from a source to destination
// Returns -1 if the graph is NULL
int print_path(graph_t * g, int source, int dest){
    
}



#endif
