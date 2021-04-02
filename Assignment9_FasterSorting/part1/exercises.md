**Instructions** 

- Discuss and answer the following questions (Make sure to elaborate and justify your responses):
- If you would like to hand write or draw your answers, then scan or take a picture of a file called exercises.pdf or exercises.png and put it in this directory.


# Exercises

1. Explain: What do you think the Big-O (worst-case) complexity of the merge sort algorithm is and why? 

Merge sort is O(n * log(n)). This is because dividing the problem into subarrays is O(log(n)) and merging
the subarrays back together is O(n). Combined, these two operations make merge sort O(n * log(n)).

2. Explain: What do you think the best-case complexity of the merge sort algorithm is and why?

The best case complexity of merge sort is still O(n * log(n)). This is because the split and recombine action
is done even if the array is already sorted.

3. Does merge sort require any additional storage beyond the original array? If so how much and why?

Yes, merge sort has space complexity of O(n). This is due to the subarrays that are created after each split.

4. How much time in Big-O does it take to merge all of the subarrays together? Explain or draw why?

It takes O(n) time to merge the subarrays together. This is because the algorithm needs to traverse over each
subarray and compare the elements at the head of each list, so it can recombine the elements in order. This
results in "visiting" each element in the original array, thus O(n) for the merge portion of the algorithm.
Of course, the number of subarrays the problem is split into depends on the size of the initial array, and 
more splits means more merge operations. However, this will result in a constant coefficient which can be
dropped in the big-O notation.


## Interview Prep (Optional +1% Bonus on assignment)

> **Rules** 
> 
> This is for bonus--and you may not ask TA's, Professors, or anyone about the question until after the homework is due.
> 
> Stratigically, you should not attempt this problem until you complete the rest of the homework (1% is less than 100% :) )

A bit ago a student asked me about this course, CS 5800, and other courses and how they may prepare you for interviews. I was recently talking to a Google, now Microsoft Engineer who told me that the reality is having a lot of LeetCode practice will help. LeetCode is a website to practice solving algorithmic challenges.

Let's finish off this exercise with a small C programming sample.

###

Solve the following: https://leetcode.com/problems/merge-sorted-array/

**Copy and paste your code into** a file in this directory called [challenge.c](./challenge.c) that solves the following problem.

**Given:** Two sorted integer arrays `nums1` and `nums2`, merge nums2 into nums1 as one sorted array and return the sorted array as a new array.

The number of elements initialized in `nums1` and `nums2` are *m* and *n* respectively.

Example 1:

```
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

Example 2:

```
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

Constraints:

```
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[i] <= 109
```
