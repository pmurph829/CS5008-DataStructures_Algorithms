// Compile this assignment with: gcc -g -Wall main.c -o main
//
// Include parts of the C Standard Library
// These have been written by some other really
// smart engineers.
#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

// Our library that we have written.
// Also, by a really smart engineer!
#include "my_dll.h"
// Note that we are locating this file
// within the same directory, so we use quotations
// and provide the path to this file which is within
// our current directory.
int print_list(dll_t* l){
    if (l == NULL){
        printf("List was NULL");
        return 0;
    }
    node_t* iter = l->head;
    
    printf("Count: %d\n", l->count);
    printf("Empty?: %d\n", dll_empty(l));
    if (dll_empty(l)){
        return 0;
    }
    printf("Head: %d, Tail: %d\n", l->head->data, l->tail->data);
    printf("Items:\n");
    printf("HEAD -- ");
    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter->next;
    };
    printf(" -- TAIL\n\n");
    return 1;
}

void fillFront(dll_t* l, int length){
    int i = 0;
    for (; i < length; i++){
        dll_push_front(l, i);
    }
}

void fillBack(dll_t* l, int length){
    int i = 0;
    for (; i < length; i++){
        dll_push_back(l, i);
    }
}

void emptyFront(dll_t* l){
    printf("Attempting to empty the following list (front):\n");
    print_list(l);
    node_t* iter = l->head;
    int data = 0;
    while (iter != NULL){
        iter = iter->next;
        data = dll_pop_front(l);
        printf("Removed: %d\n", data);
    };
    printf("\nResult:\n");
    print_list(l);
}

void emptyBack(dll_t* l){
    printf("Attempting to empty the following list (back):\n");
    print_list(l);
    node_t* iter = l->tail;
    int data = 0;
    while (iter != NULL){
        iter = iter->previous;
        data = dll_pop_back(l);
        printf("Removed: %d\n", data);
    };
    printf("\nResult:\n");
    print_list(l);
}

void unitTest1(dll_t* l){
    printf("UNIT TEST 1\n");
    fillFront(l, 10);
    emptyFront(l);
    free_dll(l);
}

void unitTest2(dll_t* l){
    printf("\nUNIT TEST 2\n");
    fillBack(l, 10);
    emptyBack(l);
    free_dll(l);
}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    dll_t * dll = create_dll();
    unitTest1(dll);
    
    dll_t* dll2 = create_dll();
    unitTest2(dll2);
    return 0;
}















