// Starting to look at pointers in C:

#include <stdio.h>

void update(int* argument){
	*argument = 15;
}

int main(){
	int value = 5;
	int* p_value = &value;
	printf("Value = %d\n", value);
	printf("p_value = %p\n", p_value);
	update(p_value);
	printf("Updated Value = %d\n", value);
}
