## Problem C: Query maximum in a range

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given an array A of length n, an integer k, and q queries: $Q_1,Q_2,...,Q_q$, each query contains a single integer x.

For each query, you please print $max(A_x,A_{x+1},...,A_{x+k−1})$ in a single line

## Input

The first line of input contains three integers $n(1≤n≤100000),k(1≤k≤n),q(1≤q≤100000)$.

The second line of input contains n integers, $A_1,A_2,...,A_n$, each of them is between $1$ and $10^9$

The third line contains q integers, $Q_1,Q_2,...,Q_q$, it's guaranteed that for each $1≤i≤q,1≤Q_i≤n−k+1$

## Output

For each query $Q_i(1≤i≤q)$, print $max(A_x,A_{x+1},...,A_{x+k−1})$ in a single line

## Sample Input

```
5 2 2
1 2 3 2 1
1 3
```

## Sample Output

```
2
3
```