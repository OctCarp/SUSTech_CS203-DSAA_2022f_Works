## Problem F: Fencing Hall

Time Limit: 4 Sec Memory Limit: 128 MB

## Description

Dateri has a magic sequence and LowbieH is interested in it. Dateri promises that if LowbieH can answer his question, then he will play fencing with LowbieH. We denote the magic sequence by $\{a_n\}$ and Dateri will choose a lucky number $k$. He asks LowbieH to find length of the longest **consecutive subsequence** such that the absolute difference between any two number in the subsequence will not exceed $k$. Can you help LowbieH?

## Input

The first line contains two integers $k(0≤k≤2∗10^9)$ and $n(1≤n≤3∗10^6)$.

The second line contains $n$ integers $a_1,⋯,a_n(1≤a_i≤2∗10^9, 1≤i≤n)$.

## Output

One line contains the answer, i.e. the length of the longest available consecutive subsequence.

## Sample Input

```
3 9
5 1 3 5 8 6 6 9 10
```

## Sample Output

```
4
```

## HINT


There are two available consecutive subsequences : $\{5,8,6,6\}$ and $\{8,6,6,9\}$.
