# Exercises

In order to start thinking a bit algorithmically, modify this file and answer the following questions. Be sure to add/commit/push any changes made to this file to our repository.

1. In the worst case in our guessing game--how many guesses could it take to get the right number if we had no hint at all? Explain.
2. In the worst case in our guessing game--how many guesses does it take to get the right number if we get a hint of 'higher or lower' when guessing numbers 1-10? *Hint* In your answer show this mathematically with the [log function](https://www.mathsisfun.com/algebra/logarithms.html).

## Answers

1. It would take the user at most 10 guesses to guess the correct number. That is, assuming the user did not simply enter the same number over and over again, and entered a different guess each time. This is because there are only 10 possible values the number could be.
2. Assume the user is playing the game rationally and starting in the middle of the range (5) as their first guess. The hint would divide their possible range in half. If the user continues this process, they will eventually reach the answer in the most efficient way. In the worst case scenario, this would take 4 guesses. This method is known as binary search, which is O(log(n)). This has to do with dividing the range in two. If n represents the size of the range of possible answers (10 in this case), the number of guesses needed to reach the answer can be represented with log2(n) = #guesses. log2(10) = 3.322... which, rounded up to the nearest whole number is 4 guesses.
