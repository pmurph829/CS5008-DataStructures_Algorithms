// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// Create your node_t type here
typedef struct node {
	int year;
	int wins;
	struct node* next;
}node_t;

// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.
node_t* create_node(int year, int wins){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	
	newNode->year = year;
	newNode->wins = wins;
	newNode->next = NULL;
	return newNode;
}

void create_list(){
	node_t* node1 = create_node(2018, 108);
	node_t* node2 = create_node(2017, 93);
	node_t* node3 = create_node(2016, 93);
	node_t* node4 = create_node(2015, 78);
	node_t* node5 = create_node(2014, 71);
}


int main(){
  
 
    return 0;
}
