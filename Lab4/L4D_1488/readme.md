## Problem D: Longest positive segment

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

 There are $n(1≤n≤1000000)$ books in the table, from left to right. Each book has a magic value $a_i(−1000≤a_i≤1000,1≤i≤n)$,

 Please find the max length of a continuous  segment $[l,r]$ , which satisfies $ \sum_{i=l}^{r}{a_i}>0$.

## Input

The first line contains an integer $n(1≤n≤1000000)$. The second line contains n integers, $a_1,a_2...a_n$, each of them is between -1000 and 1000.

## Output

Print the max length of such segment.

## Sample Input

```
5
2 0 -1 -4 2
```

## Sample Output

```
3
```

## HINT


In the sample, the longest positive segment is $[1,3]$