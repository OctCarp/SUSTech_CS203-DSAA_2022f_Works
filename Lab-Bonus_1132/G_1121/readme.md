## Problem G: Complete binary tree [Easy I]

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Lanran has a binary tree with $n$ nodes, she does not know whether this tree is a complete binary tree or not. She turns to you for help. We guarantee that the input is a binary tree.

## Input

The first line will be an integer $T$, which is the number of the test cases $(1≤T≤14)$. For each test case, the first line will be an integer $n(1≤n≤150000)$. Then followed by $n$ lines, each line will be two integers $x$ and $y$, the $i$-th line means the left child of node $i$ is $x$, the right child of node $i$ is $y$. If node $i$ has no left child, then $x$ will be $0$. If node $i$ has no right child, then $y$ will be $0$.

## Output

For each test output `Yes` or `No` in one line.

## Sample Input

```
1
5
2 3 
4 0
5 0
0 0
0 0
```

## Sample Output

```
No
```