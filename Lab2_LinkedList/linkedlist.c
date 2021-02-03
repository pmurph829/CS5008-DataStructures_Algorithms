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

typedef struct sLinkedList {
	node_t* head;
	node_t* tail;
}sLinkedList_t;

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

sLinkedList_t* create_list(){
	node_t* node1 = create_node(2018, 108);
	node_t* node2 = create_node(2017, 93);
	node_t* node3 = create_node(2016, 93);
	node_t* node4 = create_node(2015, 78);
	node_t* node5 = create_node(2014, 71);
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	
	sLinkedList_t* newList = 
		(sLinkedList_t*)malloc(sizeof(sLinkedList_t));
	newList->head = node1;
	newList->tail = node2;
	return newList;
}

void print_list(sLinkedList_t* list_p){
	node_t* itr = list_p->head;
	while(itr != NULL){
		printf("%d, wins: %d\n", itr->year, itr->wins);
		itr = itr->next;
	}
}

void free_list(sLinkedList_t* list_p){
	node_t* temp;
	node_t* itr = list_p->head;
	while(itr != NULL){
		temp = itr;
		itr = itr->next;
		free(temp);
	}
	free(list_p);
}

int main(){
	sLinkedList_t* newList_p;
	newList_p = create_list();	  
	print_list(newList_p);	
	free_list(newList_p);
	return 0;
}










