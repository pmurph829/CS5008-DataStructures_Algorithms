#include <stdio.h>
#include "my_hashmap.h"


int unitTest1(){
    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5); 
    // Insert a first key/value pair
    
    hashmap_insert(myHashmap,"pig", "a farm animal");
    hashmap_insert(myHashmap, "pig", "shouldn't add");
    // Does hashmap contain key?
    printf("pig was added, should be 1: %d\n",hashmap_hasKey(myHashmap,"pig"));
    printf("bear was not added, should be 0: %d\n", hashmap_hasKey(myHashmap, "bear"));
    // Print out the keys
    hashmap_printKeyValues(myHashmap);
    // Retrieve pig's value 
    printf("pig's value is %s\n",hashmap_getValue(myHashmap, "pig"));
    hashmap_update(myHashmap,"pig","a really cool farm animal");    
    printf("pig's value is updated to: %s\n",hashmap_getValue(myHashmap, "pig"));
    // Remove a key
    hashmap_removeKey(myHashmap,"pig");
    // Does hashmap contain key?
    printf("pig was removed should be 0: %d\n",hashmap_hasKey(myHashmap,"pig"));
    // Finally terminate our hashmap
    hashmap_delete(myHashmap);
    return 0;
}

int unitTest2(){
    // Create our hashmap
    hashmap_t* myHashmap = hashmap_create(5); 
    // Insert a first key/value pair
    hashmap_insert(myHashmap,"pig", "a farm animal");
    hashmap_insert(myHashmap,"bat", "a farm creature");
    hashmap_insert(myHashmap,"cat", "a funny farm animal");
    hashmap_insert(myHashmap,"dog", "a fun farm animal");
    hashmap_insert(myHashmap,"bear", "a wild farm animal");
    hashmap_insert(myHashmap,"ox", "another farm animal");
    hashmap_insert(myHashmap,"cow", "a favorite farm animal");
    hashmap_insert(myHashmap,"hippo", "a farm animal?");
    hashmap_insert(myHashmap,"elephant", "not a farm animal");
    hashmap_insert(myHashmap,"human", "an animal that farms");
    // Print the keys
    hashmap_printKeyValues(myHashmap);
    // Remove some keys
    hashmap_removeKey(myHashmap, "dog");
    hashmap_removeKey(myHashmap, "human");
    hashmap_removeKey(myHashmap, "ox");
    hashmap_removeKey(myHashmap, "bear");
    printf("Remove Result: %d, %d, %d, %d\n(should all be 0)\n"
                        , hashmap_hasKey(myHashmap, "dog")
                        , hashmap_hasKey(myHashmap, "human")
                        , hashmap_hasKey(myHashmap, "ox")
                        , hashmap_hasKey(myHashmap, "bear")
    );
    hashmap_printKeyValues(myHashmap);
    // Finally terminate our hashmap
    hashmap_delete(myHashmap);
    return 0;
}

int main(){

    printf("============ unitTest1() ================\n");
    unitTest1();
    printf("============ unitTest2() ================\n");
    unitTest2();
    
    return 0;
}
