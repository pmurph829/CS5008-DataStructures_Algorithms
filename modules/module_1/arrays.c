#include <stdio.h>

int main(){
	int array[3] = {1, 2, 3}; // Must specifiy array type and size in C.
	double array2[3] = {1.5, 2.3, 4.5};
	char array3[6] = {'h', 'e', 'l', 'l', 'o', '\0'}; // need '\0' to end strings
	char array4[] = "Hello World!";
	
	printf("%s %s\n", array3, array4);
	
	for(int i=0; i<3; i++){
		array[i] = i*100;
	} 
	
	for(int i=0; i<3; i++){
		printf("%d\n", array[i]);
	}
	return 0;

}
