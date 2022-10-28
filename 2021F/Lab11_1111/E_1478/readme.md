## Problem E: Pre-Order Traversal

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Give you the in-order and post-order traversal of a binary tree $T$. Please find the pre-order traversal of $T$.

## Input

First line is an integer $Q$, which is the number of test cases. $(1≤Q≤50)$

There are three lines in each test case.

The first line contains only one integer $N(1≤N≤1024)$, which is the number of nodes of tree $T$. Also, the nodes are numbered from 1 to $N$.

The second line is the in-order traversal of the tree $T$.

The third line is the post-order traversal of the tree $T$.

## Output

For each test case, output one line, representing the pre-order traversal of the tree.

## Sample Input

```
1
8
7 2 4 1 5 3 8 6
7 2 4 5 8 6 3 1
```

## Sample Output

```
1 4 2 7 3 5 6 8
```
