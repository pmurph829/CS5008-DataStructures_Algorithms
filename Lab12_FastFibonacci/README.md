# Lab - Fast Fibonacci - Using Memoization

<img align="right" width=300px src="https://mocomi.com/wp-content/uploads/2016/11/MOC_GIFO_Fibonacci-Sequence.gif">

> "Memoization--sort of like a cache" - Your instructor

It is well known that solving the fibonacci sequence takes O(n!) time. Companies that have to perform similar computations sigh when they want to run an algorithm faster but are stuck to O(n!) complexity. But would they not be impressed if you could solve the problem faster? Today you are going to practice a technique called [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) to solve the fibonacci sequence in a much faster time!

In this lab you will implement functions to compute the n'th' fibonacci sequence two different ways and measure the performance difference.

# Part 0 - SSH and git pull

1. First open a terminal and ssh into the Khoury servers ``` ssh khoury_user_name_here@login.khoury.neu.edu ```
2. Navigate to your Monorepo directory(Use the `cd` command to change directory, `ls` to see files, and `pwd` to see your path)
3. When you are within your Monorepo, do a ```git pull```. This will add all of the files I have previously pushed into your repositories.

If for some reason you are having troubles, you can always create a new copy of your monorepo by running `git clone https://github.com/COURSENAME/monorepo-yourUserNameHere` in a separate directory.

# Part 1 - Fibonacci

## Refresher

The Fibonacci numbers form a sequence of numbers such that each number is the sum of the two preceding numbers. The recursive formula is given as:

```
F(0) = 0 // this is a given base case
F(1) = 1 // this is a given base case
F(n) = F(n-1) + F(n-2) // This is every other case for n >= 2
```

For further review of the fibonacci numbers you can review the [wiki here](https://en.wikipedia.org/wiki/Fibonacci_number).

## Implementation 1 - fibonacci

With the information given above, implement the `long fibonacci(int n)` function found in [fib.c](./fib.c). You should implement a recursive version of the function.

You may use this table to figure out if your fibonacci number is correct: http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibtable.html

## Implementation 2 - dyn_fibonacci

For the dynamic programming imlementation of the fibonacci numbers, we are going to be using a tecnique known as 'memoization'. The definition of memorization means to 'commit something to memory'

When using dynamic programming techniques, we memoize information that saves us from recomputing the information later on.

### Step 1 - Create a table

The `initialize` function provided initializes our storage for computed values in the fibonacci sequence. We create as much storage as we need in a static array for this program. By default, nothing has been computed, so we create some 'NIL' value that we know will never need to be stored (in this case a negative value of -1). 

```c
// Store our previous 'memoized' values
long memo[LARGEST_FIB_NUMBER];

void initialize(){
    int i;
    // Initialize our values to some negative
    // number to indicate they have not
    // previously been computed.
    for(i = 0; i < LARGEST_FIB_NUMBER; i++){
        memo[i] = -1;
    }
}
```

Note: Some programming langauges have a better way to store a 'NIL' value. In our case, if -1 could be a possible, then we would instead use something like MIN_INT which is the smallest possible integer (i.e. largest negative integer) as our throwaway value to indicate that no data has been stored yet.

### Step 2 - Our dyn_fiboanacci

Our fibonnaci algorithm now changes slightly, in that we are going to lookup values if they have been previously computed in a tatble. The pseduo-code changes as follow.

```c
long dyn_fibonacci(int n){
    if memo[n] == -1 then we need to compute fibonacci (We do not have the value anywhere)
        We have two base cases, and can store memo[0] = 0, and memo[1] = 1.
        If it is not a base case
            Then recursively call 
                memo[n] = dyn_fibonacci(n-2) + dyn_fibonacci(n-1)
     else 
        return memo[n];
}
```


# Part 2 - Timing our Functions (Empirical Evaluation)

Once again, as in the previous labs, you will do an empirical evaluation of each of the fibonacci functions. You will know if your implementation is correct, as for large enough fibonacci numbers, the difference should be quite dramatic. Even further, if you need to recompute a fibonacci number, the dynamic version will be much faster if that number of lesser has been previously computed.

## On correctness of timing

Note that any part of the dynamic programming involved in setting up the table should be included as part of the time in our experiment.

## Compiling and running the program.

Remember to save, compile, and test early and often!

* Compile the source code with: `clang fib.c -o fib`
* Run the source code with: `./fib`

### Sample output on my machine 

45th fibonacci number

```
-bash-4.2$ gcc fib.c -o fib
-bash-4.2$ ./fib                                             
        fib1 = 1134903170 
        fib2 = 1134903170 

Analysis of Time:
8.530000 Non-Dynamic Programming Fibonacci
0.000000 Dynamic Programming Fibonacci
```

# Deliverable

- Part 1 - Implement the two fibonacci functions in [fib.c](./fib.c)

# More resources to help

- [Wiki on memoization](https://en.wikipedia.org/wiki/Memoization)

# (Optional) Going Further Task:

(This is an ungraded task--only work on this if you finish the deliverable). You will have to do a little bit of work to figure out how to open and read from files for this task.

- Try implementing a non-recursive fibonacci number function (a third implementation) and compare the performance.
