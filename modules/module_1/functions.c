#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void foo(int arg1){
	printf("From Foo(): %d\n", arg1);
}

int sum(int a, int b){
	return a + b;
}

void bar(); // Function must be declared before it is called.

int countEven(int array[], int size){
	int evens = 0;
	int odds = 0;
	
	for (int i=0; i<size; i++){
		if (array[i] % 2 == 0){
			evens++;
		}
		else{
			odds++;
		}
	}
	printf("%d evens, %d odds. \n", evens, odds);
	return evens;
}

int main(){
	int array[] = {1, 2, 3, 4, 5, 6};
	int numEven = countEven(array, 6);
	printf("Number of even elements is: %d\n", numEven);
	
	foo(23);
	bar();
	return 0;
}

void bar(){
	int num1 = 5;
	int num2 = 6;
	int sum = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, sum);
}


