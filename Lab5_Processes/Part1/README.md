# Process API

In today's lab, we are going to explore the C process API to get familiar with launching processes from within our program. Provided in this lab are several code examples showcasing several ways to launch and control processses with the commands: fork, wait, and exec. Today's lab will also introduce you to the idea of 'multiprocessing' (i.e. executing multiple processes) as well as some of challenges in correctly executing multiple programs.

## Fork and Exec Motivation and Use

[Fork](https://man7.org/linux/man-pages/man2/fork.2.html) serves as a simple way to create new processes. We are making an almost exact duplicate copy of the current running process (i.e. you can make an analogy to the biological process of cell division when we are forking a process). The fork command creates a parent-child relationship. 

<img align="center" width="350px" src="./media/fork.jpg">

At this point we have two separate programs that are executing. 

But you might wonder, how do we get a 'new' application that can do something different? This is where the [exec](https://man7.org/linux/man-pages/man3/exec.3.html) function is used. We can call a function (really a system call) [exec](https://man7.org/linux/man-pages/man3/exec.3.html) from our child process and the 'exec' function replaces that current program by loading up (or overlaying) a new process (thus we no longer have a duplicate process--but a totally new program running).

<img align="center" width="350px" src="./media/exec.png">

(Notice after the 'exec' call the boxes change size, because 'exec' is allocating a new program)

When thinking about this from the perspective of an operating system, [fork](https://man7.org/linux/man-pages/man2/fork.2.html) is a quick way to create a new process, and [exec](https://man7.org/linux/man-pages/man3/exec.3.html) allows us to execute a totally new program in a separate address space safely (thus, not effecting our original parent process in case the child crashes).

# Part 1 - fork

Remember that when we use [fork](http://man7.org/linux/man-pages/man2/fork.2.html), we are creating a child process that is identical to the parent process. The child process gets a copy of (almost) everything that the parent had, but the memory is distinct, such that modificiations in either the parent or child do not effect each other.

Let us go ahead and try a simple example with fork.

### example1.c

The following program is our version of a "hello world" to the fork command you may enter in [example1.c](./example1.c).

```c
#include <stdio.h>
#include <sys/types.h>	// Includes some new data types (e.g. pid_t)
#include <unistd.h>	// This is a new library that includes various unix system calls.

int main(){

	// Variable to store the process id
	pid_t pid;
	// Variable 'x' allocated on the stack
	int x = 1;

	// pid returns the child process id.
	// 0 if it is the child
	// >0 is the process id of the child which the parent recieves
	pid = fork();

	if(pid==0){
		printf("child: x=%d\n",++x);
		return 0;	
	}

	// Parent process executing
	printf("parent: x=%d\n", --x);

	return 0;
}

```

* Save and compile the code: `gcc example1.c -o example1`
* **Before running:** Predict what the result will be.
* Run the following program with: `./example1`

### example2.c

Let's try another example this time, type the following in [example2.c](./example2.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	// Variable to store the process id
	pid_t pid;
	// Variable 'x' allocated on the stack
	int x = 1;

	// pid returns the child process id.
	// 0 if it is the child
	// >0 is the process id of the child which the parent recieves
	pid = fork();

	if(pid==0){
		printf("Terminating Child, PID= x=%d\n",getpid());
		exit(0);	
	}else{
    	    // Run the parent
	    printf("Running parent forever(pretend I am a server): pid=%d\n",getpid());
    	    while(1){
    	    }
  	}

	return 0;
}
```

* Save and compile the code: `gcc example2.c -o example2`
* Run the following program: `./example2 &` (Notice that the ampersand here is used)
* **Before running:** Predict what the result will be. What happens when you compile and run this code? 
	* (When running with `./example2 &` the ampersand returns control back to shell and your process runs in the background until completion).

#### What happened??

Type `ps -ef | grep your_khoury_username` into the terminal (or try `ps -ef | grep defunct` if your username is longer than 7 characters). You will notice that one of the processes is labeled `<defunct>`, and that id will actually match our childs pid. 

What happened here, is that we have not reclaimed (or reaped) our children. Our child is said to be a [zombie process](https://en.wikipedia.org/wiki/Zombie_process), in that it is occupying and using resources, but not doing any useful work.

Let us get rid of our processes now. Type `kill somenumber` where *somenumber* is the pid (process id) of your parent and child process (Note: that killing the parent process should kill the child process as well. See the [kill](http://man7.org/linux/man-pages/man2/kill.2.html) system call. Kill sends a signal to terminate a process.).
  
*Now what if we flip the scenario where our child runs forever?*

### example3.c

Type the following in [example3.c](./example3.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

    // Variable to store the process id
    pid_t pid;
    // Variable 'x' allocated on the stack
    int x = 1;

    // pid returns the child process id.
    // 0 if it is the child
    // >0 is the process id of the child which the parent recieves
    pid = fork();

    if(pid==0){
    	printf("Running child forever now pid=%d\n",getpid());
    	while(1){
    	}
    }else{
	// Run the parrent
		printf("Terminating parent pid=%d\n",getpid());
		exit(0);
    }

	return 0;
}
```

* Save and compile the code: `gcc example3.c -o example3`
* Run the following program: `./example3 &`

We will have the same problem, and we need to run the `ps` command again(to see which processes are running), and then the `kill some_pid_number` command.

## Synchronization

There is a sometimes subtle problem you may have noticed in the previous example if you ran it enough times. We did not properly enforce the order in which each process executed. So what is one potential solution to fix this problem to ensure that the child process finishes before the parent?

The answer is to use a synchronization function called [wait](https://man7.org/linux/man-pages/man2/waitid.2.html). `int wait(int *child_status)` will make the parent process wait to execute after one or more child process(es) has finished.

<img src="./media/wait.png" width="600px">

### example4.c - Introducing wait

Type the following in [example4.c](./example4.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h> // Library with the 'wait' system call.
#include <unistd.h>

int main(){

    // Store the status here
    int child_status;

    // Another way to 'fork()' a child process without storing the pid
    // The parent process will begin executing from the else block.
    if(fork()==0){
        printf("Child runs!\n");
        exit(0); // and exits properly
    }else{
        printf("Hello from parent\n");
        wait(&child_status);

        // If we want to do something with the child_status here is an example.
        // Typically we can wait(NULL), but within our parent we may want
        // to capture how the child exited(maybe it exited with some error code).
        // e.g. change 'exit(0)' to 'exit(5)' in the block of code executed by
        // the child.
        if(WEXITSTATUS(child_status)>=0){
            printf("Child exited with the following child_status %d\n",WEXITSTATUS(child_status));
        }
        printf("Child always is terminated by this point--parent resuming\n");
    }

    printf("This always prints last\n");

    // It is important to note that our parent should always wait for all
    // of its child processes to exit before proceeding.
    // If the parent ends first(i.e. forgetting to call wait), the
    // child process is 'orphaned' and becomes a zombie process that
    // cannot be otherwise terminated.

    return 0;
}
```

* Save and compile the code: `gcc example4.c -o example4`
* Run the following program: `./example4`
* Take a moment to read about orphan and zombie processes here: 
	* http://linuxg.net/what-are-zombie-and-orphan-processes-and-how-to-kill-them/
	* Understand what we saw in example 2 and 3 we created a zombie and orphan.
	* Understand also how to find and kill any zombie and orphan processes.
	
### example5.c - Introducing exec

#### execve

Sometimes we will want to not just launch a new piece of code, but rather execute an entire program as a separate process from within our process. We have been previously doing this using our terminal. In order to execute other programs (i.e. a more specific process), we have the [execve](http://man7.org/linux/man-pages/man2/execve.2.html) command.

- The execve command: `int execve(char* filename, char* argv[], char*envp[])`
- filename: This is the script or file we are going to execute (i.e. this is equivalent to typing it in the shell)
- argv: This is our argument list (which we are familiar with). 
	- As an example: argv[0] = filename of the program we want to execute
- envp: These are any specific environment variables we want to set.
  - More information can be found here: [https://en.wikipedia.org/wiki/Environment_variable]

Let's try a simple example using execve to launch the 'ls' program from within our program.

Type the following in [example5.c](./example5.c)

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

	char* myargv[16];	// We can store up to 16 arguments.
	myargv[0]="/bin/ls";	// Our first argument is the program we want to launch.
	myargv[1]="-F";		// Any additional arguments (i.e. flags) we want to make use of.
	myargv[2]=NULL; 	// Terminate the argument list--similar to how we would terminate a character string.
				// (i.e. Set the last argument to NULL if we have no more flags.)
	if(fork()==0){
		// Executes command from child then terminates our process
		// Note: There are other 'exec' functions that may be helpful.
		execve(myargv[0],myargv,NULL);
		printf("Child: Should never get here\n");
		exit(1);
	}else{
		wait(NULL); // handy synchronization function again!
		printf("This always prints last\n");
	}
	
	return 0;
}
```

* Save and compile the code: `gcc example5.c -o example5`
* Run the following program: `./example5`
* Go ahead and modify the above code and try to run some other processes like 'cat'.
* * **Before running:** Predict what the result will be. What happens when you compile and run this code? 
	*  Will the code work if I change `myargv[0]="ls"`. Why do you think this is? What did you discover?
	* Some hints to the previous question
		* https://phoenixts.com/blog/environment-variables-in-linux/ 
		* https://www.cyberciti.biz/faq/linux-list-all-environment-variables-env-command/

### example6.c - Interprocess Communication

Sometimes it can be handy to get multiple processes to talk to each other. [example6.c](./example6.c) has been provided for you to help your understanding of commands like pipe, dup2, exec, waitpid, and close.

You will also learn about file descriptors by reading through [example6.c](./example6.c).

**Understanding** [example6.c](./example6.c) and [example5.c](./example5.c) will be **very useful** if you wanted to implement your own a shell.

# Your task - myprogram.c

Now that you have learned how to use fork(), exec(), and wait() you will write your own program utilizing these system calls.

### Task

- Write a program in [myprogram.c](./myprogram.c) using fork and/or execve to execute a series of at least 3 other commands/programs.
	- As an example, your program would run: `ls`, followed by `echo "testing"`, and then `nl example1.c`
	- [example5.c](./example5.c) is a program that executes exactly 1 command, and you may expand on this example in your [myprogram.c](./myprogram.c)
	- You are welcome to launch a different set of programs and be as creative as you like!
	- It may be useful to use [waitpid](https://linux.die.net/man/2/waitpid) if you'd like to wait on a specific process to execute (think about if the order matters however!)

# Part 2 - Terminal Programs

To get some practice with understanding processes, run the following commands: 

- `ls proc/` (Why ls here? What if you just type `/proc`)
- [top](http://man7.org/linux/man-pages/man1/top.1.html)
- [ps](http://man7.org/linux/man-pages/man1/top.1.html)
- [kill](http://man7.org/linux/man-pages/man2/kill.2.html) (yes, I know it is a rather aggressive command name--yikes!)

It will be further useful to read the `man` pages for each of the commands.

# Lab Deliverable

- Commit the source code for the 5 examples (example1.c example2.c example3.c example4.c example5.c).
- Commit your source code for [myprogram.c](./myprogram.c)

# More resources to help

- https://www.networkworld.com/article/2693548/unix-viewing-your-processes-through-the-eyes-of-proc.html
- Stack overflow post on `kill` system call.
	- https://unix.stackexchange.com/questions/8916/when-should-i-not-kill-9-a-process
- On Interprocess Communication (i.e. pipe)
	- https://www.usna.edu/Users/cs/aviv/classes/ic221/s16/lec/18/lec.html
- Another useful tutorial on pipe, fork, etc.
	- http://www.rozmichelle.com/pipes-forks-dups/
	
# Going Further

- Investigate the different command shells: https://en.wikipedia.org/wiki/Comparison_of_command_shells

# F.A.Q.

## Difference between Zombie Process, Orphaned Process and Daemon Process

* Zombie Process - a zombie process (same as <defunct>) is a process that has completed execution but still has an entry in the process table and this happens when the termination of the process has not been collected by the parent (example2.c)
* Orphaned Process - process whose parent process has finished or terminated, though it remains running itself. (example3.c)
* Daemon Process - Daemon is a computer program that runs as a background process, every daemon process is an orphaned process.
