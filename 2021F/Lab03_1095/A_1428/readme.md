## Problem A: Reverse Pair

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

In DSAA, we define $(A[i],A[j])$ in array $A$ as a reverse pair if $A[i]>A[j]$ and $i＜j$ .

Given two non-descending arrays $A$ with size $n$ and $B$ with size $m$. 

Please return (i) the number of reverse pairs in array $C=\{A[1],A[2],...,A[n],B[1],B[2],...,B[m]\}$;and (ii) the non-descending array $C$.

If you do not have any idea, please refer to Page 22 (in lecture 3 slides) for inspiration.

## Input

The first line contains an integer $T(1 ≤ T ≤10)$, representing the number of test cases. 

In each test case:

1. The first line will be two integers $n$ and $m$ which are the lengths of the two non decreasing sequences.

2. The second line will be $n$ integers $A_1,A_2,...,A_n$

3. The third line will be $m$ integers $B_1,B_2,...,B_m$

For all cases, $1<=n,m<=10^5,0≤A_i,B_j≤10^9$

## Output

For each test case:

 The first line is the number of reverse pairs of $\{C\}$

 The second line is sequence $\{C\}: C_1,C_2,...,C_{n+m}$

## Sample Input

```
2
2 4
2 3
1 2 3 4
2 2
3 4
1 2
```

## Sample Output

```
3
1 2 2 3 3 4 
4
1 2 3 4 
```

## HINT

You may need this. Java Fast IO template: https://paste.ubuntu.com/p/6ybMcVXvz5/
