# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: This is pushing the Stack Base Pointer Register to the base of the stack,
	pushq %rbp			# and pushing the Stack Pointer Register to the top of the stack. 
	movq  %rsp, %rbp		# Essentially, this is setting up an empty stack.

					# (2) What is going on here
					# Ans: This is moving the value 1 into an accumulator register,
	movq $1, %rax			# then moving the value 1 into a destination index register (the first argument to a function). 
	movq $1, %rdi			# Next the address of where the value  "hello" is stored is moved into a source index register (the second argument).
	leaq .hello.str,%rsi		#


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: A syscall is a request to the operating system to perform some task (ex: show text on the screen).
	syscall				# Which syscall is being run?
					# Ans:

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans:

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans:	
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	
