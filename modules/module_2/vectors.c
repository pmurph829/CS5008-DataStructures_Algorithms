#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	int* data;
	int size;
	int capacity;
}vector_t;

/* Vector Constructor
 * Function that allocates memory for and makes a vector. 
 * Returns the pointer
*/
vector_t* makeVector(int initCapacity){
	vector_t* vector = (vector_t*)malloc(sizeof(vector_t));
	if ( vector == NULL ){
		return NULL;
	}
	// Allocate memory for data array.
	vector->data = (int*)malloc(sizeof(int) * initCapacity);
	vector->size = 0;
	vector->capacity = initCapacity;
	return vector;
}

/* Vector Destructor 
 * Function that frees memory previously allocated for a vector.
*/
void freeVector(vector_t* vector){
	if (vector == NULL){
		return;
	}
	// First delete data array, then delete vector struct.
	if (vector != NULL){
		free(vector->data);
	}
	free(vector);	
}

int resize(vector_t* vector){
	if (vector == NULL){
		return 0;
	}
	vector->capacity = vector->capacity * 2;
	int* newData = (int*)malloc(sizeof(int) * 
					vector->capacity);
	if (newData == NULL || vector->data == NULL) {
		return 0;
	}	

	//Copy data from old array into new array
	for(int i = 0; i<vector->size; i++){
		newData[i] = vector->data[i];
	}
	//Delete the old array
	free(vector->data);
	vector->data = newData;
	return 1;//Successful
}

int pushBack(vector_t* vector, int element){
	if (vector == NULL){
		return 0;
	}
	
	if (vector->data == NULL){
		return 0;
	}
	
	// do we need to resize array?
	if (vector->size == vector->capacity){
		int resizeSuccess = resize(vector);
		if (resizeSuccess == 0){
			return 0;
		}
	}
	//Add to the back of the array
	vector->data[vector->size] = element;
	vector->size += 1;
	return 1;//Successful
}

void print(vector_t* vector){
	if ( vector == NULL ){
		return;
	}	

	for ( int i=0; i < vector->size; i++ ){
		printf("%d ", vector->data[i]);
	}
	printf("\n");
}

int main(){
	//Construct Vector on the heap
	vector_t* vector = makeVector(2);
	pushBack(vector, 2);
	pushBack(vector, 4);
	pushBack(vector, 6);// Resize
	pushBack(vector, 8);
	pushBack(vector, 9);// Resize
	print(vector);	
	//Destroy vector and free up memory on the heap.
	freeVector(vector);	
	
	return 0;
}







