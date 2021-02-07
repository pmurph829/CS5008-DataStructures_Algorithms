#include <stdio.h>


int main(int argc, char** argv){
	/*
	int i;
	for(i=0; i<argc; i++){
		printf("%s\n", argv[i]);
	}
	*/
	
	FILE* fptr = fopen(argv[1], "r");
	
	while(!feof(fptr)){
		char line[1000];

		fgets(line, sizeof(line), fptr);
		printf("%s\n", line);

	}
	
	fclose(fptr);
	
}

