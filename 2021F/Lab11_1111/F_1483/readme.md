## Problem F: Mex Problem

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Here are $t(1≤t≤10^5)$ tests, each test contains two integers $a(0≤a≤10^9)$ and $b(0≤b≤10^9)$, you should find the Mex of the sequence $a⊕0, a⊕1... a⊕b$, here $⊕$ mean the bitwise xor operation. The Mex of the sequence of non-negative integers is the smallest non-negative integer that doesn't appear in this sequence. For example, Mex(1,2,3)=0,Mex(0,1,2,4,5)=3

## Input

The first line contains a single integer $t(1≤t≤10^5)$, indicates the number of test cases.
The first and only line of each test case contains two integers $a$ and $b(0≤a,b≤10^9)$.

## Output

For each test case, print a line contains a single integer — the answer to the problem.

## Sample Input

```
3
0 9
8 6
9 9
```

## Sample Output

```
10
0
2
```
