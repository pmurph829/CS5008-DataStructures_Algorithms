# Exercises

Discuss and answer the following questions (Please make sure to elaborate and justify your responses):

1. Explain what do you think the Big-Oh (worst-case) complexity of this algorithm is? Why?
2. What do you think the best-case complexity of this algorithm is?
   - Provide an example of an array of elements that fit the best-case.
3. Does insertion sort require any additional storage beyond the original array? Explain why or why not.
4. What is a 'stable sorting' algorithm? Is insertion sort a 'stable' algorithm, why or why not?

## Answers:

1. The worst case time complexity for insertion sort is O(n^2). If the list is in reverse order, the algorithm
    must traverse the entire array, and compare each element to each sorted element to sort the list.
2. The best case time complexity for insertion sort is actually O(n). If the list is already sorted, the
    algorithm only needs to traverse the array once without swapping any elements.
3. Insertion sort does not require any additional storage, because it is done in place.
4. Stable sorting occurs if two adjacent, equal elements in an array remain in the same order after sorting
    (as opposed to being interchanged, which would still be sorted). Insertion sort is a stable algorithm
    because if two elements are equal, the algorithm just moves on to the next comparison without swapping
    anything.
