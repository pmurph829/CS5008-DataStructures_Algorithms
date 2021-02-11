#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
	/*
	int i;
	for(i=0; i<argc; i++){
		printf("%s\n", argv[i]);
	}

	printf("%d\n",argc);
	*/
	int addCount = 0;
	int subCount = 0;
	int mulCount = 0;
	int divCount = 0;
	int movCount = 0;
	int leaCount = 0;
	int pushCount = 0;
	int popCount = 0;
	int retCount = 0;
	int instructions = 0;
	int cycles = 0;

	FILE* fptr = fopen(argv[1], "r");
	
	while(!feof(fptr)){
		char line[1000];
		fscanf(fptr, "%s", &line);
		if(strstr(line, "add") != NULL ){
			addCount++;
			instructions++;
			cycles++;
		}

		if(strstr(line, "sub") != NULL){
			subCount++;
			instructions++;
			cycles++;
		}
		
		if(strstr(line, "mul") != NULL){
			mulCount++;
			instructions++;
			cycles += 2;
		}

		if(strstr(line, "div") != NULL){
			divCount++;
			instructions++;
			cycles += 4;
		}

		if(strstr(line, "mov") != NULL){
			movCount++;
			instructions++;
			cycles++; 
		}

		if(strstr(line, "lea") != NULL){
			leaCount++;
			instructions++;
			cycles++;
		}

		if(strstr(line, "push") != NULL){
			pushCount++;
			instructions++;
			cycles++;
		}

		if(strstr(line, "pop") != NULL){
			popCount++;
			instructions++;
			cycles++;
		}

		if(strstr(line, "ret") != NULL){
			retCount++;
			instructions++;
			cycles++;
		}

	}
	
	fclose(fptr);

	printf("ADD: %d\n", addCount);
	printf("SUB: %d\n", subCount);
	printf("MUL: %d\n", mulCount);
	printf("DIV: %d\n", divCount);
	printf("MOV: %d\n", movCount);
	printf("LEA: %d\n", leaCount);
	printf("PUSH: %d\n", pushCount);
	printf("POP: %d\n", popCount);
	printf("RET: %d\n", retCount);
	printf("Total Instructions: %d\nTotal Cycles: %d\n",instructions, cycles);

}








