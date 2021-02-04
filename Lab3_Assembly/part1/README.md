# Lab x86-64 Assembly Cycle Count Tool

> "Nearing Machine Code Representation"

## Introduction

Recall that our compilers translate our C code to assembly which is the human readable version of binary(1's and 0's). You may be wondering how good are compilers (like gcc and clang) at generating assembly from our C code (Similar to the way you may have a good and bad translator when communicating in different languages)? How can we be sure that our compiler is generating efficient assembly? There are afterall, many different ways to write a program that generates the same output!

## Our Tool

Part of being a good programmer, is the ability to build tools that measure. In this case, you are going to write a small parser in C that counts the number of instructions and counts how many instructions are needed to run that program from top to bottom.

As an example, if an assembly program had the following code:

```asm
# assembly.s program

MOVQ a, %rax
MOVQ b, %rbx
ADDQ %rbx, %rax
IMULQ %rbx
MOVQ %rax, c
```

**Your goals**: Your [tool.c](./tool.c) will report a summary of the total Instructions(i.e. ADD, MOV, IMU, etc.) found given an input file. Additionally, you will estimate the total cycles needed for hardware to execute this code.

Below is an example of a correct output your program 
```asm
ADD 1
MOV 3
IMUL 1

Total Instructions = 5
Total Cycles = 6
```

## Specifications for tool.c

* Your tool should read in a file name through the command line arguments for what file is being analyzed 
  * You will run your program with: `./tool barbones.s` on the command line.
  * (hint, investigate what argc and argv are for how to read in `barebones.s` as input to your program).
* [barebones.s](./barebones.s) is provided to be used as an example input file for your tool.
* You will modify a file called [tool.c](./tool.c) which you will implement your tool in. 
  * At the very least, your program should output counts for: ADD, SUB, MUL, DIV, MOV, LEA, PUSH, POP, RET.
    * ADD counts as 1 cycle
    * SUB counts as 1 cycle
    * MUL counts as 2 cycles
    * DIV counts as 4 cycles
    * MOV counts as 1 cycle
    * LEA counts as 1 cycle
    * PUSH counts as 1 cycle
    * POP counts as 1 cycle
    * RET counts as 1 cycle
  * i.e. For your analysis (and for the sake of simplicity), consider ADDQ, ADDB, ADDL, etc. each as adding to the 'ADD' instruction and cycle counts. IMUL is equivalent to MUL, IDIV is equivalent to DIV.
    * You may ignore other assembly instructions (i.e. incq, decq that are not in the above list)

### Reading in arguments in C - argc and argv

Here's an example program for working with arguments in C.

```c
// Compile with: gcc -g -Wall args.c -o args
// Try running with:
//          - ./args
//          - ./args somefile.c
//          - ./args argv1 argv2
#include <stdio.h>

// The parameters to the main function are read in
// when you execute your program on the terminal.
// argc: is the argument count
// argv: is a 'variable' number of arguments provided
//
// This program shows how to iterate through all of the arguments
int main(int argc, char** argv){

    printf("argc is the argument count: %d\n",argc);
    
    // This loop will print out all of the arguments
    for(int i=0; i < argc; i++){
        printf("argv[%d] is %s\n",i,argv[i]);
    }

    // Then you can use the argv's as needed.
    // example: If argv[1] is suppose to be a particular (like the filename), 
    //          you can make use of it.
    // 		So your next step would be to use FILE* input = fopen(argv[1],"r");
    //		Then read every line in that file, and 'parse' the first few characters

    return 0;
}

```

### String processing

* You may find [https://fresh2refresh.com/c-programming/c-strings/c-strcat-function/](https://fresh2refresh.com/c-programming/c-strings/c-strcat-function/) helpful for learning some string processing in C or here: [https://www.programiz.com/c-programming/c-strings](https://www.programiz.com/c-programming/c-strings)
* The overall approach is to read one line at a time from the file you have loaded, read the first 3 characters, and then appropriately update your total instructions and total cycles.
* There are many helpful functions such as scanf, fscanf, fgets, fgetc, getc
 

# Deliverable

- A modified [tool.c](./tool.c) that reads in a file 'barebones.s' from the command line and:
	- reports the correct number of instructions
	- reports the correct number of cycles


# Resources to help

- [http://www.cplusplus.com/reference/cstring/](http://www.cplusplus.com/reference/cstring/)
- Matt Godbolt has written a great tool to help understand assembly generated from the compiler. 
  - https://godbolt.org/

# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

* (Optional for fun) You do not need to do anything with barebones.s in this lab, but you can investigate or answer the qeustions in the file for extra assembly practice.
* (Optional for fun) Try running barebones or another assembly program after compiling with -O0 and -O3 and see if the cycle count changes from your tool.
* (Optional) Use the Agner Fog's instruction table ([http://www.agner.org/optimize/instruction_tables.pdf](http://www.agner.org/optimize/instruction_tables.pdf)) to find more accurate cycle counts how many cycles the program will run. That is, take an instruction like MOV which typically takes 1 cycle, and sum them together and output the result.
  * You will use the **Nehalem** Intel architecture to find your values.
  * Note that this is again an estimate (MOV with different data types itself takes different number of cycles! So your answer will be an approximation. I am expecting there to be some variance, even within the class--attempt something reasonable).
