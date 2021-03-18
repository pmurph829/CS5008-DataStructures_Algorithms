# Exercises

1. What do you think the Big-O (worst-case) complexity of this algorithm is? 
2. What do you think the best-case complexity of this algorithm is? 
	- Note-- assume you do not have any information about if the array is already sorted or not.
3. Does selection sort require any additional storage beyond the original array? 
	- i.e. Did you have to allocate any extra memory to perform the sort?
5. Would the Big-O complexity change if we used a linked list instead of an array?

## Answers:

1. The worst-case complexity of selection sort is O(n^2).
2. The best-case complexity of selection sort is also O(n^2), since we would still need to traverse the list and do comparisons to find the minimum even if the minimum is the first element.
3. Selection sort does not require any extra storage.
4. No. Even though finding a node in a linked list is O(n), it is still less than O(n^2), so the time complexity of the sorting algorithm would not be different at a large n.
