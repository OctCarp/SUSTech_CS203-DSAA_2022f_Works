## Problem B: Search Problem II

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given two arrays $A$ with length $n$ and $B$ with length $T$. We want to know whether each element in array $B$ is in array $A$ or not.

## Input

The 1st line is a positive integer $n(1≤n≤10^5)$

The 2nd line contains $n$ integers: $a_1,a_2,...,a_n$. For each $a_i,0≤a_i≤10^9$.

The 3rd line contains $a$ positive integer $T(1≤T≤10^5)$

The 4th line contains $T$ integers $b_1,b_2,...,b_T$. For each $b_i,0≤b_i≤10^9$.

## Output

For each element in $B$, print "`yes`" (in a single line, without quotes) if it is in $A$, otherwise print "`no`"  

## Sample Input

```
4
2 3 999999 1
2
3 99
```

## Sample Output

```
yes
no
```