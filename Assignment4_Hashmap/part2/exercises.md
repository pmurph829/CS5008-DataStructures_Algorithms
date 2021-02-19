# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap?
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity?
4. What is 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. The provided hash function uses strlen, which works by traversing a given null-terminated string until it encounters a terminator ('\0') character.
   Since this operation needs to traverse the entire string, the time complexity of this function is closer to O(n) where n represents the number of 
   characters in the string. If a very long string is passed as a key, it will take the hash function longer to determine which bucket to place
   it in.

2. Another possible example of a hash function is to take the ASCII number of the first character in the given key, and place it in a bucket
   using the mod operator similar to how the hash function was implemented in this assignment. For example, the char 'A' has ASCII number 64. so the
   key "Apple" going into a hashmap with 5 buckets would be placed in bucket # 4 (64 % 5 = 4).

3. The Big-O complexity of resizing a hashmap would be O(n), because you would need to iterate over every element (node) in the current map, and copy them into
   a new hashmap of the desired size one by one. n in this case represents the number of nodes in the hashmap.

4. Open addressing refers to storing all entries in the hashmap into the bucket array itself. Each key is found by "probing" the bucket array until the desired
   key is found. There are different methods of probing the bucket array that have trade-offs in terms of chache performance and "clustering" which is when 
   key/value pairs are stored in contiguous blocks of memory in the bucket array. This is a disadvantage because it can lead to collision of entries as 
   more data is added and memory allocated to a particular bucket encroaches on the memory allocated for the next bucket.
