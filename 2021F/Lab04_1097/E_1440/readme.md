## Problem E: Non-decreasing sequence

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a sequence $\{a_i\}$ of length n, we define is a **decreasing number** if $a[i-1]>a[i](i-1 > 0 )$ or $a[i]>a[i+1] (i+1≤n)$. Please process the given sequence by deleting the decreasing numbers in it. In each turn you should delete **all the decreasing numbers** in the given sequence at the same time. The processing procedure will be terminated until the given sequence does no have decreasing number.

## Input

The first line of input contains an integer $T(1≤T≤10)$ which is the total number of test cases.
For each test case, there are two lines.
The first line contains a integer $n$, $n≤100000$.
The second line contains $n$ integers, representing the sequence $\{a[i]\} (1≤a_i≤100000)$

## Output

One line per test case, represents the final result

## Sample Input

```
2
10
1 4 4 3 2 8 9 4 5 7
5
1 8 6 2 4
```

## Sample Output

```
1 4 7
1 4
```
