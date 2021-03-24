# Lab 9 - Quickly Sorting

> "Empirical evidence is important" - Your instructor

<img align="right" width=400px src="https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif">

In today's lab you have been contracted by the famous music radio station **drum roll** *50.08 ALGS-Northeastern the best radio station in the land*. The problem the radio station has been running into is that the radio [DJ](https://en.wikipedia.org/wiki/Disc_jockey)'s have not been able to find and play songs fast enough when requests are made from fans. Simply put, their sorting algorithm for the song database is not organized, and the only current sorting algorithm the DJ knows is [Bogo Sort](https://en.wikipedia.org/wiki/Bogosort), which is way too slow.

In this lab we are going to implement and compare the performance of [quicksort](https://en.wikipedia.org/wiki/Quicksort) versus a brute force sort to see how much we can improve performance. We will also get a brief introduction to loading data from files, and sorting data that is alpha-numeric.

# Part 0 - SSH and git pull (Same directions as always!)

1. First open a terminal and ssh into the Khoury servers ``` ssh khoury_user_name_here@login.khoury.neu.edu ```
2. Navigate to your Monorepo directory(Use the `cd` command to change directory, `ls` to see files, and `pwd` to see your path)
3. When you are within your Monorepo, do a ```git pull```. This will add all of the files I have previously pushed into your repositories.

If for some reason you are having trouble, you can always create a new copy of your monorepo by running `git clone https://github.com/COURSENAME/monorepo-yourUserNameHere` in a separate directory.

# Part 1 - File I/O (i.e. File Input and Output)

The first task we need to perform is to acquire our data. The data that we are working with is 'song titles' and our goal is to sort the data so that the DJ's can quickly find songs (search remember can be done in log(n) time using binary search when data is sorted).

The function provided to us is `loadMusicFile` which opens a text file for reading. The [fopen](http://pubs.opengroup.org/onlinepubs/009695399/functions/fopen.html) command is shown below which opens a file, and the second parameter `r` ensures that we are 'reading' data from the file (and not modifying it).

```c
FILE *myFile = fopen(fileName,"r");
```

Once we have opened a file, our goal is then to read line by line each song name into an array called 'database'. Our array 'database' is a collection of [c-style strings](http://www.cs.kent.edu/~durand/CS2/Notes/01_Intro/c2_stringCstyle.html), thus its type is `char**`. This array is what we will return from our function which will contain all of the song titles.

```c
char** database = malloc(sizeof(char*)*size);
```

The following function below highlights one strategy for loading songs from a file one line at at time. This is provided for you.
```c
 char** loadMusicFile(const char* fileName, int size){
   FILE *myFile = fopen(fileName,"r");

   // Allocate memory for each character-string pointer
   char** database = malloc(sizeof(char*)*size);

   unsigned int song=0;
   for(song =0; song < size; song++){
       // Allocate memory for each individual character string
       database[song] = malloc(sizeof(char)*80);
       // Copy over string
       database[song] = fgets(database[song],sizeof(char)*80,myFile);
   }

   // Import to always remember to close any file we open.
   fclose(myFile);
   // Return the pointer to our database
   return database;
 }
```

# Part 2 - Swapping Strings and text data

From part 1 we have loaded our data into our array. Everytime we have written a 'sort' function, we have needed some way to swap data to move items into the correct position. So given our problem statement--*How can we sort data faster for 50.08 ALGS-Northeastern*--we are going to need some way to swap around unsorted elements in our dataset. Previously you have written a swapping function when working with integers.

```c
void swap(int* a, int* b){
 int temp = *a;
 *a = *b;
 *b = temp;
}
```

The data we are working with is 'text' data which consists of a song name. This means that we will need a 'swap' function for working with c-strings. The first question one may ask however, is how do I compare a string?

## ascii representation of numbers

<img width=700px src="./media/asciifull.gif">

<!--**With your partner:**--> **Take a moment** to observe the chart above. What do you notice about the alphabetical ordering of each letter and their values? They look sorted to me! But what about upper-case and lower-case letters?

In order to make our problem slightly easier we have 'cleaned' our data by making every song starts with a lower case letter to make sorting our data easier (Note however there are duplicates!).  The handy function [strcmp](http://www.cplusplus.com/reference/cstring/strcmp/) can be used to tell us which of the c-strings should come first.

```c
// @Name    swapStrings
// @Brief   Swaps two strings.
//          The lower string is put first
void swapStrings(char** s1, char** s2){
  if( strcmp(*s1,*s2)==0 ){
    // Strings are identical, do nothing
    return;
  }else if( strcmp(*s1,*s2) < 0 ){
    // Do nothing--we are already sorted
    return;
  }else{
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
  }
}
```

<!--**Answer the following with your partner:**--> **Answer the following here**: How do you think the strcmp function is implemented? i.e. What would your algorithm be in a sentence or two?

*edit your answer here*

# Part 3 - Quick sort

<img width=400px src="https://www.tutorialspoint.com/data_structures_algorithms/images/quick_sort_partition_animation.gif">

Okay, so we have a swap function now that works with c-style strings, and data in our database. We are now ready to implement the quicksort algorithm! Provided below is the pseudo-code for implementing quick sort. Quicksort is a recursive function, and uses one helper function 'partition' to sort data.

## quicksort pseudocode

The following is pseudo-code for the quicksort algorithm.

```c
quicksort(array[], unsigned int low, unsigned int high)
{
    if (low < high)
    {
        // pivot here is the partitioning index
	// This means array[pivot] is at the correct 
	// position and will not need to  move
        pivot = partition(arr, low, high);
	
	// Recurse on the left and right side of the pivot
	// Note: The offsets of -1 and +1 to avoid the pivot.
        quickSort(array, low, pivot - 1);  // Before pivot
        quickSort(array, pivot + 1, high); // After pivot
    }
}
```

Hmm, this partition function is still a bit of a mystery--let's take a look at that function next.


## quicksort partition pseudocode

```c
// This function partitions around the last element.
// That is, we decide which values go to the left or right
// of the last index (i.e. our 'high' value of the current array)
// The pivot itself will remain at the correct position.
partition (array[], low, high)
{
    // Choose the last element 'randomly' as the pivot.
    // Note: Our 'pivot' when working with strings is something like
    // char** pivot = &array[high];
    // Use printf("%s",*pivot); to see if you get a reasonable string.
    pivot = array[high];  
 
    i = (low - 1)  // Index of smaller element

    for (j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
	// Note: we need to do a'strcmp' here against our *pivot)
	
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap arr[i] and arr[j] // See the 'swapStrings' function for inspiration.
	    		           // Carefully think about how you pass the arrays in!
				   // This is just pseudo-code!
        }
    }
    swap (array[i + 1], array[high]) // Carefully think about how you pass the arrays in!
    return (i + 1)
}
```

# Part 4 - Timing our Functions (Empirical Evaluation)

We have previously studied the asymptotic complexity of several algorithms in this course. But the only way to be sure that an algorithm is faster, is to actually measure it for the given input size. What if there is more overhead in setting up the quicksort function (i.e. a big constant factor)? In order to be sure that our quicksort function is faster than the bruteforceSort, we can use [<time.h>](https://www.tutorialspoint.com/c_standard_library/time_h.htm) to measure.

## Elapsed time

In order to compute the elapsed time of an algorithm, we need a starting point and a stopping point. This is just like using a stop watch, when you press start and then press stop. The way most computer systems track time, is by keeping track of time since a particular event which represents '0'. Then that number increments indefinitely, similar to how each year we increment (2018, 2019, 2020, etc.). Subtracting the end time(a bigger number, i.e. more time has passed since the start)  from our start time, returns the total time.

```c
// ===========================================
// ===== Experiment 1 - Using Brute Force Sort ====
// Create a clock to measure the elapsed time
clock_t start1,end1;
start1 = clock();
// perform bruteForceSort after starting your timer
bruteForceSort(musicDatabase1,0,13610);
end1 = clock();
double experiment1 = ((double)(end1-start1)/CLOCKS_PER_SEC);
 // ===========================================
```

## Compiling and running the program.

Remember to save, compile, and test early and often!

* Compile the source code with: `clang radio.c -o radio`
* Run the source code with: `./radio`

# Deliverable

- Part 3 - Implement quicksort in [radio.c](./radio.c)
- Edit and answer questions <!-- with your partner--> throughout the lab.

# More resources to help

- [Quicksort Pseudo code](https://www.tutorialspoint.com/data_structures_algorithms/quick_sort_algorithm.htm)

# (Optional) Going Further Task:

(This is an ungraded task--only work on this if you finish the deliverable). You will have to do a little bit of work to figure out how to open and read from files for this task.

- Try sorting only 5 items. Is quicksort still faster?
- Try finding more songs on the web. Which algorithm is faster when there are 1,000,000 songs?

# Citations

- 1000 songs were provided in the music database by The Guardian through the article [1,000 songs to hear before you die
](https://www.theguardian.com/news/datablog/2009/mar/20/1)
- An additional 12000+ songs were provided from: [Database: All Billboard Hot 100 Hits 1955-2013](https://raywoodcockslatest.wordpress.com/2017/07/22/top-100-songs-database/)
- Ascii table from: http://www.asciitable.com/
