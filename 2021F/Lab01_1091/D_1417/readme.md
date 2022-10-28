## Problem D: Minimizing $A_n−B_n$

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given two arrays $A$ and $B$ with the same length $n−1$. We want to insert two integers into $A_n$ and $B_n$ $(1≤A_n≤h,1≤B_n≤h)$ such that (i) the sum of array $A$ without its largest value and smallest value is **larger** than the sum of array $B$ without its largest value and smallest value; and (ii) $A_n−B_n$ is minimized.

## Input

The 1st line contains two integers: $n,h (2≤n≤10^5,1≤h≤10^9)$

The 2nd line contains $n−1$ integers: $A_1,A_2,...,A_{n−1}$,all element in AA is between $[1,h]$

The 3rd line contains $n−1$ integers, $B_1,B_2,...,B_{n−1}$,all element in BB is between $[1,h]$

## Output

Print the minimum value of $A_n−B_n$ if you can find a proper $(A_n,B_n)$ pair, otherwise print "`IMPOSSIBLE`".

## Sample Input

```
3 4
1 3
2 4
```

## Sample Output

```
1
```

## HINT

You can insert 3 into $A_n$, 2 into $B_n$, and the the sum of array $A$ without its largest value and smallest value is 3, the sum of array $B$ without its largest value and smallest value is 2, and $A_n−B_n$ is 1, it can be prove that the value is minimized.
