// =================== Support Code =================
// Hashmap 
//
// - Implement each of the functions to create a working hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other 
//   than functions that explicitly ask for printf  output. 
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// - You may add any helper functions that you think you need (if any, or otherwise for debugging)
// ==================================================
#ifndef MY_HASHMAP_T
#define MY_HASHMAP_T

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// A key value pair
// This is specifically for a (char*, char*) key value pair
typedef struct pair{
    char* key;
    char* value;
}pair_t;

// Each node holds a key and a value
typedef struct node{
    struct node* next;
    pair_t* kv;          // 'kv' stands for key/value pair
}node_t;


// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Create a function pointer to a function that takes
// in a char* and an int.
typedef int(*hashFunctionPointer)(char*,int) ; 

// Chained implementation of a hashmap
typedef struct hashmap{
    unsigned int buckets;   // i.e. size of the hashmap
    node_t** arrayOfLists;  // An array of linked lists for our buckets
                            // Read another way
                            //      - an array of node_t*

    // A function pointer to a hash function
    // The hash_function must take in a 'char*' as a key, and have a
    // second parameter specifying the number of buckets.
    hashFunctionPointer hashFunction;
}hashmap_t;

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t* hashmap_create(unsigned int _buckets){
    // Allocate memory for our hashmap
	hashmap_t* hashMap = (hashmap_t*)malloc(sizeof(hashmap_t));

    // Set the number of buckets
	hashMap->buckets = _buckets;

    // Initialize our array of lists for each bucket
	hashMap->arrayOfLists = (node_t**)malloc(sizeof(node_t*) * _buckets);
    int i=0;
    for (; i<_buckets; i++){
        hashMap->arrayOfLists[i] = NULL;
    }

    // Setup our hashFunction to point to our stringHash function.
	hashMap->hashFunction = stringHash;
    
    // Return the new map that we have created
    return hashMap;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap){
    if(_hashmap != NULL){
	    int i = 0;
        for (; i<_hashmap->buckets; i++){
            node_t* iter = _hashmap->arrayOfLists[i];
            while (iter != NULL){
                node_t* tmp = iter;
                iter = iter->next;
                free(tmp->kv->key); 
                free(tmp->kv);
                free(tmp);
            }
        }
        free(_hashmap->arrayOfLists);
        free(_hashmap);
    }
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key){
	//TODO
    return 0;
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){
    pair_t* pair = (pair_t*)malloc(sizeof(pair_t));
    pair->key = (char*)malloc(strlen(key) * sizeof(char)+1);
    pair->value = value;
    strcpy(pair->key, key);

    node_t* newNode = (node_t*)malloc(sizeof(node_t));

    newNode->next = NULL;
    newNode->kv = pair;

    unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets);

    if (_hashmap->arrayOfLists[bucket] == NULL){
        _hashmap->arrayOfLists[bucket] = newNode;
    }else{
        newNode->next = _hashmap->arrayOfLists[bucket];
        _hashmap->arrayOfLists[bucket] = newNode;
    }

}

// Return a value from a key 
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
/*
char* hashmap_getValue(hashmap_t* _hashmap, char* key){
	//TODO
}
*/

// TODO NOTE THAT I DID NOT FINISH REMOVE KEY BECAUSE...
// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key){
	//TODO
}

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
	//TODO
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){
	if (_hashmap != NULL){
        int i=0;
        for (; i<_hashmap->buckets; i++){
            printf("Keys in bucket %d:\n", i);
            node_t* iter = _hashmap->arrayOfLists[i];
            while (iter != NULL){
                printf("\t%s\n", iter->kv->key);
                iter = iter->next;
            }
        }
    }
}

// Print all key : value pairs in a hashmap
void hashmap_printKeyValues(hashmap_t* _hashmap){
    if (_hashmap != NULL){
        int i = 0;
        for (; i<_hashmap->buckets; i++){
            printf("Pairs in bucket %d:\n", i);
            node_t* iter = _hashmap->arrayOfLists[i];
            while (iter != NULL){
                printf("\t%s : %s\n", iter->kv->key, iter->kv->value);
                iter = iter->next;
            }
        }
    }
}

#endif
