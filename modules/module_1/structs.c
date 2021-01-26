#include <stdio.h>

struct student{
	int id;
	int age;
	double creditHours;	
}; // Semicolon is needed after closing curly brace for structs.

struct student makeStudent(int id, int age, double creditHours){
	struct student tempStudent;
	tempStudent.id = id;
	tempStudent.age = age;
	tempStudent.creditHours = creditHours;

	return tempStudent;
}

void printStudent(struct student aStudent){
	printf("Student ID %d: %d %f\n",  aStudent.id, 
					aStudent.age, 
					aStudent.creditHours);
}

int main(){
	struct student s1; // declare the struct name (student) and variable name (s1)
	s1.id = 1001;
	s1.age = 23;
	s1.creditHours = 14.5;
	
	struct student s2 = makeStudent(1002, 24, 13);

	struct student s3 = makeStudent(1003, 25, 16.00);
	
	printStudent(s1);
	printStudent(s2);
	printStudent(s3);
	
	/*
	printf("Student 1: %d %d %f\n", s1.id, s1.age, s1.creditHours);
	printf("Student 2: %d %d %f\n", s2.id, s2.age, s2.creditHours);
	printf("Student 3: %d %d %f\n", s3.id, s3.age, s3.creditHours);
	*/

	return 0;
}
