
# Task 1 - Merge sort

For this assignment, you are going to implement in 'C' [merge sort](https://en.wikipedia.org/wiki/Merge_sort). A skeleton file has been provided called [sort.c](./sort.c). You will know your sorting algorithm works correctly, if the data in the resulting array is sorted in ascending order after calling your merge sort function.

## Mergesort at a high level

<img align="right" src="./media/mergesort.gif" alt="Merge sort picture">

Merge sort is a [divide and conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) that was invented by [John von Neumann](https://en.wikipedia.org/wiki/John_von_Neumann) way back in 1945. Merge sort has a worst-case time complexity being Ο(n * log(n)). Of our sorting algorithms that we have seen, this is the best overall time complexity thus far. 

Merge sort works as follows:

1. Repeatedly divide the unsorted array into *n* subarrays(a subarray being 'a smaller part' of the original array) until each subarray contains one element (Note: an array of one element is already sorted).
2. Then, repeatedly merge subarrays to produce new sorted subarrays until there is only one subarray remaining. The result will be the sorted array.

Here is a diagram showing the two steps above in the picture (As they say a picture is worth a thousand words!):

<img align="center" width="400px" src="./media/Merge_sort_algorithm_diagram.svg" alt="Merge sort picture">

A more detailed pseudo-code follows:

```cpp
mergeSort(arr[], l,  r)
If r > l
     1. Find the middle point 'm' to divide the array into two halves:  
             m = (l+r)/2
     2. Call mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
 ```  
           
Note: Merge sort is not an [in-place algorithm](https://en.wikipedia.org/wiki/In-place_algorithm) because it creates new subarrays everytime a merge is performed. However even with the array creation, the worse-case complexity is more efficient than Selection, Insertion, or Bubble sort. 

You can watch [this](https://www.youtube.com/watch?time_continue=1&v=JSceec-wEyw) to visually see how merge sort works.

## Designing the merge sort algorithm

An algorithm itself does not need to be contained in a single function. Sometimes it is helpful to have some 'helper functions' to make the code easier to understand. For merge sort, you will likely need at least two functions: 

1. mergeSort -- the main sort function which will be called from sortIntegers.
     - It's signature is likely `void mergeSort(int array[], int l, int r)`
2. merge -- the main chunk of the algorithm. 
     - mergeSort will use this function to merge the subarrays.

## Compiling and running the program.

When you have made an attempt at the sorting algorithm, go ahead and try to run it. Remember to save, compile, and test early and often!

* Compile the source code with: `clang sort.c -o sort`
* Run the source code with: `./sort`

# Task 2 - Merge Sort Complexity Q & A.

Discuss and answer the following questions in [exercises.md](./exercises.md)

# Deliverable

- Modify the file called [sort.c](./sort.c) and implement a version of merge sort that sorts numbers in ascending order.
- Answer the questions in Task 2 in the [exercises.md](./exercises.md) file.

# More resources to help

- [Merge sort video](https://www.youtube.com/watch?time_continue=1&v=JSceec-wEyw)
- [Khan Academy Sorting, pseudocode, analysis, and exercise](https://www.khanacademy.org/computing/computer-science/algorithms/merge-sort/a/divide-and-conquer-algorithms)
     - Helpful series of exercises to understand implementation and analysis of merge sort.

# (Optional) Going Further Task:

(This is an ungraded task--only work on this if you finish the deliverable). You will have to do a little bit of work to figure out how to open and read from files for this task.

- Implement merge sort, but this time, use a linked list as the storage data structure instead of an array.


