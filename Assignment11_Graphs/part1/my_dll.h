// =================== Support Code =================
// Doubly Linked List ( DLL ).
//
//
//
// - Implement each of the functions to create a working DLL.
// - Do not change any of the function declarations
//   - (i.e. dll_t* create_dll() should not have additional arguments)
// - You should not have any 'printf' statements in your DLL functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
//   - (You may write helper functions to help you debug your code such as print_list etc)
// ==================================================
#ifndef MYDLL_H
#define MYDLL_H

#include <stdlib.h>
// Create a node data structure to store data within
// our DLL. In our case, we will stores 'integers'
typedef struct node{
    void* data;
    struct node* next;
    struct node* previous;
}node_t;

// Create a DLL data structure
// Our DLL holds a pointer to the first node in our DLL called head,
// and a pointer to the last node in our DLL called tail.
typedef struct DLL{
    int count;        // count keeps track of how many items are in the DLL.
    node_t* head;        // head points to the first node in our DLL.
    node_t * tail;          //tail points to the last node in our DLL.
}dll_t;

// Creates a DLL
// Returns a pointer to a newly created DLL.
// The DLL should be initialized with data on the heap.
// (Think about what the means in terms of memory allocation)
// The DLLs fields should also be initialized to default values.
// Returns NULL if we could not allocate memory.
dll_t* create_dll(){
    // Modify the body of this function as needed.
    dll_t* myDLL= malloc(sizeof(dll_t));
    if (myDLL == NULL) {
        return NULL;
    }
    myDLL->count =0;
    myDLL->head = NULL;
    myDLL->tail = NULL;
    return myDLL;
}

// Create a new node
// Returns a pointer to a new node
// Assigns the previous and next fields of the new node
node_t* create_node(void* data, node_t* previous, node_t* next) {
    node_t* newNode = malloc(sizeof(node_t));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->data = data;
    newNode->next = next;
    newNode->previous = previous;
    return newNode;
}

// DLL Empty
// Check if the DLL is empty
// Returns 1 if true (The DLL is completely empty)
// Returns 0 if false (the DLL has at least one element enqueued)
// Returns -1 if the dll is NULL.
int dll_empty(dll_t* l){
    if (l == NULL) {
        return -1;
    }
    if (l->count == 0) {
        return 1;
    }
    return 0;
}

// push a new item to the front of the DLL ( before the first node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_front(dll_t* l, void* item){
    if (l == NULL) {
        return -1;
    }
    // create a new node
    node_t* newNode = create_node(item, NULL, l->head);

    // make sure memory allocation worked
    if (newNode == NULL) {
        return 0;
    }

    // if this is the first node being added to the list, set tail to this node
    // otherwise, set old head's previous to this node
    if (l->count == 0) {
        l->tail = newNode;
    } else {
        l->head->previous = newNode;
    }
    
    // update current head of list and increase count
    l->head = newNode;
    l->count++;
    return 1;
}

// push a new item to the end of the DLL (after the last node in the list).
// Returns 1 on success
// Returns 0 on failure ( i.e. we couldn't allocate memory for the new node)
// Returns -1 if DLL is NULL.
// (i.e. the memory allocation for a new node failed).
int dll_push_back(dll_t* l, void* item){
    if (l == NULL) {
        return -1;
    }

    // create a new node
    node_t* newNode = create_node(item, l->tail, NULL);

    // check that memory allocation worked
    if (newNode == NULL) {
        return 0;
    }

    // if this is the first item being added to the list, set head to this node
    // otherwise, set the old tail's previous field to this node
    if (l->count == 0) {
        l->head = newNode;
    } else {
        l->tail->next = newNode;
    }

    // update the current tail and increase count
    l->tail = newNode;
    l->count++;
    return 1;
}

// Returns the first item in the DLL and also removes it from the list.
// Returns NULL on failure, i.e. there is noting to pop from the list.
// Returns NULL if the DLL is NULL.
// Assume no negative numbers in the list or the number zero.
void* dll_pop_front(dll_t* t){
    if (t == NULL) {
        return NULL;
    }
    if (t->count == 0) {
        return NULL;
    }
    
    // retrieve the first item in the list
    void* frontItem = t->head->data;

    // create a pointer to the current head node so we can free it later
    node_t* oldHead = t->head;

    // update the head node
    if (t->count == 1) {
        t->head = NULL;
        t->tail = NULL;
    } else {
        t->head->next->previous = NULL;
        t->head = t->head->next;
    }

    // Free memory allocated to the old head and reduce count.
    free(oldHead);
    t->count--;
    return frontItem;
}

// Returns the last item in the DLL, and also removes it from the list.
// Returns NULL on failure, i.e. there is noting to pop from the list.
// Returns NULL if the DLL is NULL.
// Assume no negative numbers in the list or the number zero.
void* dll_pop_back(dll_t* t){
    if (t == NULL){
        return NULL;
    }
    if (t->count == 0){
        return NULL;
    }
    
    // Retrieve the last item in the list
    void* backItem = t->tail->data;
    
    // Create a pointer to the current tail node so we can free it later.
    node_t* oldTail = t->tail;
    
    // Update the tail node
    if (t->count == 1){
        t->head = NULL;
        t->tail = NULL;
    } else {
        t->tail->previous->next = NULL;
        t->tail = t->tail->previous;
    }

    // Free memory allocated ot the old tail and reduce count.
    free(oldTail);
    t->count--;
	return backItem;
}

// Inserts a new node before the node at the specified position.
// Returns 1 on success
// Retruns 0 on failure:
//  * we couldn't allocate memory for the new node
//  * we tried to insert at a negative location.
//  * we tried to insert past the size of the list
//   (inserting at the size should be equivalent as calling push_back).
// Returns -1 if the list is NULL
int dll_insert(dll_t* l, int pos, void* item){
    if (l == NULL){
        return -1;
    }

    if (pos == 0){ // Inserting into positon 0 is the same as adding to the front
        return dll_push_front(l, item);
    }

    if (pos == l->count){ // Adding to the positon of the current count is adding to back
        return dll_push_back(l, item);
    }

    if (pos < 0 || pos > l->count){ // Can't have a negative position and can't be outside the list
        return 0;
    }
    
    // Find the next and previous nodes by traversing the list up to pos
    int i = 0;
    node_t* iter = l->head;
    for (; i < pos-1; i++){
        iter = iter->next;
    }

    // create a new node 
    node_t* newNode = create_node(item, iter, iter->next);
    
    // Set the previous and next node's pointers to the new node and increase count
    iter->next->previous = newNode;
    iter->next = newNode;
    l->count++;
    return 1;
}

// Returns the item at position pos starting at 0 ( 0 being the first item )
//  (does not remove the item)
// Retruns NULL on failure:
//  * we tried to get at a negative location.
//  * we tried to get past the size of the list
// Returns NULL if the list is NULL
// Assume no negative numbers in the list or the number zero.
void* dll_get(dll_t* l, int pos){
//TODO make sure to handle case where l = NULL
    if (l == NULL) {
        return NULL;
    }
    if (pos < 0 || pos >= l->count - 1){
        return NULL;
    }
    
    node_t* iter = l->head;
    int i = 0;
    for(; i<pos; i++){
        iter = iter->next;
    }
    return iter->data;
}

// Removes the item at position pos starting at 0 ( 0 being the first item )
// Retruns NULL on failure:
//  * we tried to remove at a negative location.
//  * we tried to remove get past the size of the list
// Returns NULL if the list is NULL
// Assume no negative numbers in the list or the number zero.
void* dll_remove(dll_t* l, int pos){
//TODO handle case with multiple nodes added to back
    if (l == NULL){
        return NULL;
    }
    if (pos < 0 || pos >= l-> count){
        return NULL;
    }
    
    // Check if pos is at front or back of list
    if (pos == l->count-1){
        return dll_pop_back(l);
    }
    if (pos == 0){
        return dll_pop_front(l);
    }
    
    // Find the node to remove
    node_t* iter = l->head;
    int i = 0;
    for(; i<pos; i++){
        iter = iter->next;
    }

    void* data = iter->data;

    // Connect the surrounding nodes
    iter->previous->next = iter->next;
    iter->next->previous = iter->previous;

    // Free the removed node and reduce count.
    free(iter);
    l->count--;
    return data;
}

// DLL Size
// Queries the current size of a DLL
// Returns -1 if the DLL is NULL.
int dll_size(dll_t* t){
    if (t == NULL){	
		return -1;
    }
    return t->count;
}

// Free DLL
// Removes a DLL and all of its elements from memory.
// This should be called before the proram terminates.
void free_dll(dll_t* t){
   if (dll_empty(t)){
        free(t);
        return;
   }
   node_t* iter = t->head;
   while (iter != NULL){
        node_t* temp = iter;
        iter = iter->next;
        free(temp);
   }
   free(t);
}

#endif

