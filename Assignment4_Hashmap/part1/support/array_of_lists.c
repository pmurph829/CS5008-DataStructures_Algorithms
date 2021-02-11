// A few notes:
//  	This is support code, not a complete solution.
//      This is to aid in your understanding, not a
//      complete solution.
//      You're solving a slightly different problem,
//      but this may be helpful in your understanding.
// 
//      My recommendation is to read through the source
//      code, or rebuild it yourself from scratch
//      in order to understand the data structure at a
//      smaller level before diving in.
//
//      As always, save, compile, and run often!
//
// gcc -g -Wall array_of_lists.c -o array_of_lists 


#include <stdio.h>  // For Input/Ouput
#include <stdlib.h> // For malloc
#include <string.h> // Because we are going to
					// be working with strings

// Key as a string
// Value as an integer
typedef struct pair{
    char* key;
    int value;
}pair_t;

// Node in our linked list
typedef struct node{
    struct node* next;
    pair_t* kv;	// key/value pair
}node_t;

// Simple hash function that will put a key into a bucket 
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Create a function prototype to a function that takes
// in a char* and an int.
typedef int(*hashFunctionPointer)(char*,int) ; 

// main hashmap data structure
typedef struct hashmap{
	// Number of buckets in our hashmap
    int buckets;
	// Why 'two' stars?
	// Because we are going to allocate an
	// array of nodes.
    node_t** arrayOfLists;
	// Setup a function pointer to our hash function
	// This is a new concept where we can have pointers to
	// functions. Remember, functions themselves have
	// actual addresses.
	// The 'hashFunctionPointer' typedef has a signature
	// for a function pointer that returns an integer,
	// and takes a char* and int as two parameters.
	// The syntax is a little bit weird.
	hashFunctionPointer hashFunction;
}hashmap_t;


// Allocate a new hashmap
hashmap_t* hashmap_create(int _buckets){
	// Allocate for our main hashmap structure
    hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
	// Setup our buckets
    map->buckets = _buckets;
	// allocate memory for our array of lists
	map->arrayOfLists = (node_t**)malloc(sizeof(node_t*)*_buckets);
	// Iterate through all of our buckets and set them to NULL
	for(int i=0; i < _buckets; i++){
		map->arrayOfLists[i] = NULL;
	}
	// Set our function pointer to a hashing function 
	// that can hash strings into an integer which tells us
	// which 'bucket' to put in the hashmap arrayOfLists
	map->hashFunction = stringHash;

    return map;
}

void hashmap_insert(hashmap_t* in, char* key_in,int value){
	// Perhaps logic on handling if the key already exists
	// and just return...
	// and more error handling if the hashmap is NULL.

	pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
	newpair->key = (char*)malloc(strlen(key_in)*sizeof(char)+1);
	newpair->value = value;
	// Copy the string 
	strcpy(newpair->key,key_in);	
	// Create our new node
	node_t* newnode = (node_t*)malloc(sizeof(node_t));
	newnode->next = NULL;
	newnode->kv = newpair;

	// Now figure out where to put this key/value pair in
	// our hashmap
	unsigned int bucket = in->hashFunction(key_in,in->buckets);	

	// Create an iterator and set it to the bucket that we want
	// Then we'll iterate through this bucket to the end of the chain
	// (which remember, is just the end of the linked list)
	node_t* iter = in->arrayOfLists[bucket];
	if(iter==NULL){
		// If there is nothing in our bucket, then make this
		// the first node
		in->arrayOfLists[bucket] = newnode;
	}else{
		// Otherwise prepend to our list in the current bucket
		// We set our new nodes next to not be NULL, but instead
		// the head of the list
		newnode->next = in->arrayOfLists[bucket];
		// Then we set the first node in the bucket to
		// be our newly created node.
		in->arrayOfLists[bucket] = newnode;
	}
	
}

// Goal is to iterate through all of the keys and print
// them out
void hashmap_printkeyValues(hashmap_t* in){
	// Iterate through all of our buckets
	for(int i=0; i < in->buckets; i++){
		printf("Bucket# %d\n",i);
		// Iterate through all of the lists
		// starting at each bucket
		node_t* iter = in->arrayOfLists[i];
		while(iter !=NULL){
			// Remember a node consists of a key/value
			printf("\tKey=%s\tValues=%d\n",iter->kv->key,iter->kv->value);
			// Move our iterator in that particular bucket
			// forward one node until we reach the end
			// of our chain.
			iter = iter->next;			
		}
	}
}

int main(){

    // Create our hashmap
    hashmap_t* map = hashmap_create(8);
	// Insert some values
    hashmap_insert(map,"Mike",10);
    hashmap_insert(map,"Jacob",11);
    hashmap_insert(map,"Matt",12);
    hashmap_insert(map,"Nathan",13);
    hashmap_insert(map,"Carter",14);
    hashmap_insert(map,"Andrew",15);
    hashmap_insert(map,"Campbell",16);
    hashmap_insert(map,"Michael Jordan",23);
    hashmap_insert(map,"Lebron James",23);
    hashmap_insert(map,"Jeff Probst",40);
    hashmap_insert(map,"Dr. House",23);
	//
    hashmap_printkeyValues(map);

	// ... You should also write a function to iterate
	//     through hashmap and free it :)
	// Running this program through valgrind should reveal many memory leaks

    return 0;
}
