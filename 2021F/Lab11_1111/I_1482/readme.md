## Problem I: Minimum pearls

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

There are two kinds of pearls: black and white. When a black pearl is the left of a white pearl and they are adjacent to each other, then they will disappear. 
Now, there are $n$ strings of pearls, each string with $a_i$ white pearls on the left and $b_i$ black pearls on the right. Calculate the minimum number of the rest pearls when connecting these $n$ strings.

## Input

The first line contains an integer $T$, indicating the number of test cases. For each test case:
The first line contains an integer $n(1≤n≤100000)$, indicating the number of the string of beads.
Each of the next (n) lines contains two integers $a_i,b_i(a_i≥0,b_i≥0,1≤a_i+b_i≤10000)$.
It is guaranteed that $∑(a_i+b_i)≤500000$.

## Output

Output one integer, indicating the minimum number of the rest pearls.

## Sample Input

```
2
2
1 2
2 1
2
1 3
2 1
```

## Sample Output

```
2
3
```
