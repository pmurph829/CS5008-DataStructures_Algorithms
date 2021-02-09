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
void print_list(dll_t* l){
    node_t* iter = l->head;
    
    printf("Count: %d\n", l->count);
    printf("Empty?: %d\n", dll_empty(l));
    printf("Head: %d, Tail: %d\n", l->head->data, l->tail->data);
    printf("Items:\n");

    while(iter != NULL){
        printf("%d\n", iter->data);
        iter = iter->next;
    };
}


// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
    dll_t * dll = create_dll();
    dll_push_front(dll, 0);
    dll_push_front(dll, 1);
    dll_push_front(dll, 2);
    print_list(dll);
    
    return 0;
}
