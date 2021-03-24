Please edit this document below with your responses. Each question is worth 1/8 of your lab.

# Exercise 1

1. Record here how long it took you to run bubblesort and csort (Note: If you want to run several trials, say '10' and take an average that is an even better result!).

The bubblesort algorithm took 0.355 seconds on average. csort took 0.007 seconds to complete on average.

# Exercise 2

What is the Big-O complexity of bubblesort?

The Big-O complexity of bubblesort is O(n^2) (average-case and worst-case).

# Exercise 3

Do a little research and discover what algorithm qsort is in the C standard library. What is the algorithm? https://en.wikipedia.org/wiki/Qsort

Qsort in the C standard library uses a variation of the "quicksort" sorting algorithm. Quicksort works by
selecting a pivot value in the array to be sorted, then partitioning the array by arranging values to the left
or right of the pivot. Each partition is then sorted in the same way. Due to this partitioning, quicksort can
be done recursively.

# Exercise 4

What is the Big-O complexity of 'qsort' that we use in the csort program?

The average-case complexity of quicksort is O(n logn), which is much faster than O(n^2). While the worst-case
complexity of quicksort is O(n^2), this case is actually very rare.

# Exercise 5

Is qsort's Big-O complexity better or worse than bubblesort? (Anser: Yes it is better/ No it is worse/ It is equal)

qsort's Big-O complexity is the same as bubblesort, since Big-O only looks at worst-case performance. However, 
qsort is faster in practice due to it's average-case performance being faster than bubblesort.

# Exercise 6

List the following functions in terms of their Big-O complexity from **smallest** to **largest**.
<img src="./media/bigo.jpg"/>

LogN, N, N^2, N^3, 2^N, N!

# Exercise 7

- Given: f(n) = 3n^3 + n^2 + 27
- What is the O(n) of f(n)?

O(n^3), because the term with the fastest growth is the only one that is taken into account, and constants are
ignored.

# Exercise 8

- Given: f(n) = 3n^3 + n^2 + 27
- What are two constants c and k that prove your answer in exercise 7.

 3n^3 + n^2 + 27 <= cn^3
        n^2 + 27 <= cn^3 - 3n^3
        n^2 + 27 <= n^3(c - 3)
  (n^2 + 27)/n^3 <= c - 3
    1/n + 27/n^3 <= c - 3
1/n + 27/n^3 + 3 <= c

let n = k = 1:
1/(1) + 27/(1) + 3 <= c
1 + 27 + 3 <= c
31 <= c

k = 1
c >= 28.

