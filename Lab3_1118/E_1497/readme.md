## Problem E: Sequence Problem

Time Limit: 2 Sec Memory Limit: 1024 MB

## Description

You are given a sequence $a_1,a_2,…,a_n$. There are 3 kinds of operation.

Operation 1: I p v    insert a number v to position p

Operation 2: M p v   change the number of position p to v

Operation 3: Q l r k   find the k-th smallest number from position l to position r.

There are $m$ operations. For each operation 3, please print the answer

## Input

The first line contains two integers $n,m (n ≤ 40000, m ≤ 80000 )$, which is the initial sequence number and the total number of operations.

The second line contains $n$ integer $a_i$, which are the integers in the sequence.

The following $m$ lines, denoting each operation.

The data is guaranteed that for operation 3, 1 ≤ l ≤ r ≤ current sequence’s length, 1 ≤ k ≤ r-l+1, and final sequence’s length will not exceed 80000.

**All the numbers in the sequence $0 ≤ a_i ≤ 80000$ in every time.**

## Output

For each operation 3, print out the answer.

## Sample Input

```
5 3
1 2 3 4 5
I 1 2 
M 3 5
Q 1 6 4
```

## Sample Output

```
4
```

## HINT


After the first operation, the sequence will be $\{2,1,2,3,4,5\}$

After the second operation, the sequence will be $\{2,1,5,3,4,5\}$