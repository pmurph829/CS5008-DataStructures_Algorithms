// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Create a node with no children.
bstnode_t* create_node(int item) {
    bstnode_t* newNode = (bstnode_t*)malloc(sizeof(bstnode_t));
    newNode->data = item;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Modify the body of this function as needed.
    bst_t* myBST= (bst_t*)malloc(sizeof(bst_t));
    myBST->size = 0;
    myBST->root = NULL;

    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    if (t->root == NULL) {
        return 1;
    }
    return 0;
}

// Helper function for bst_add.
int add_help(bstnode_t* root, int item) {
    if (root == NULL) {
        return -1;
    }

    if (item <= root->data) {
        if (root->leftChild == NULL) {
            root->leftChild = create_node(item);
            if (root->leftChild != NULL) {
                return 1;
            } else {
                return -1;
            }
        }
        return add_help(root->leftChild, item);
    } else {
        if (root->rightChild == NULL) {
            root->rightChild = create_node(item);\
            if (root->rightChild != NULL) {
                return 1;
            } else {
                return -1;
            }
        }
        return add_help(root->rightChild, item);
    }
}

// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item){
    if (t == NULL) {
        return -1;
    }
    if (bst_empty(t) == 1) {
        t->root = create_node(item);
        t->size++;
        return 1;
    }
    t->size++;
    return add_help(t->root, item); 
}

// Print all elements of a bst in ascending order.
void print_ascending(bstnode_t* node) {
    if (node == NULL) {
        return;
    }
    print_ascending(node->leftChild);
    printf("%d ", node->data);
    print_ascending(node->rightChild);
}

// Print all elements of a bst in descending order.
void print_descending(bstnode_t* node) {
    if (node == NULL) {
        return;
    }
    print_descending(node->rightChild);
    printf("%d ", node->data);
    print_descending(node->leftChild);
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
    } else {
        if (order == 0) {
            print_ascending(t->root);
        } else {
            print_descending(t->root);
        }
        printf("\n");
    }
}

// Recursive helper function for sum that can calculate the sum of all
// descendents of an arbitrary node (root of tree is used to calculate whole sum).
int sum_help(bstnode_t* node) { //int lSum, int rSum) {
    // base case
    if (node == NULL) {
        return 0;
    }
    return node->data + sum_help(node->leftChild) + sum_help(node->rightChild);
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
    if (t == NULL){
        exit(0);
    }
    return sum_help(t->root);
}

// Recursive helper function for find that looks for a value in the descendents of a
// given node. Returns 1 if value is found, 0 if not. 
int find_help(bstnode_t* node, int value) {
    if (node == NULL) {
        return 0;
    }
    if (value == node->data) {
        return 1;
    } 

    if (value < node->data) {
        return find_help(node->leftChild, value);
    } else {
        return find_help(node->rightChild, value);
    }
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t * t, int value){
    if (t == NULL) {
        exit(0);
    }
    return find_help(t->root, value);
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    if (t == NULL) {
        exit(0);
    }
    return t->size;
}

// Helper function that frees all descendents of the given node, and the node itself.
void free_nodes(bstnode_t* node) {
    if (node == NULL) {
        return;
    }
    free_nodes(node->leftChild);
    free_nodes(node->rightChild);
    free(node);
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
    if (t == NULL) {
        exit(0);
    }
    free_nodes(t->root);
    free(t);
}

