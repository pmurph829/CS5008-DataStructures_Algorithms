### Part 2

Implement the following functions in your my_graph.h:

```c
// returns 1 if we can reach the destination from source
// returns 0 if it is not reachable
// returns -1 if the graph is NULL (using BFS)
int is_reachable(graph_t * g, int source, int dest){

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
```

## A hint on writing the traversal algorithms

As you have seen in class, there needs to be away to figure out if a node has already been visited when traversing a graph so we don't end up in an infinite loop. There are at least two approaches to go about this (though you are free to use other strategies):

1. Introduce a `int visited` field in our `graph_node_t` struct that is 1 if the node has been visited otherwise 0. If you choose to go this route you would need to reset all *visited* flags in each node to 0 before doing a new traversal.

2. You could have a single linked list, or a BST that stores all the nodes that you've already visited. Note that your single linked list or BST will store just the values of the nodes, not the nodes itself, which makes this more straight forward.  


