## Problem B: Are you my new friend?

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

You are given a complete binary tree and each node has a **distinct** key value. Now you are asked to determine whether the tree is a heap or not. If it is a heap, you are to determine if it is a Max-heap or a Min-heap.

## Input

The first line contains $N(2≤N≤10^6)$, denoting the number of nodes in the tree.

The second line contains $N$ integers $A_1,A_2...A_N(1≤A_i≤10^9)$, denoting the key value of node $i$. It is guaranteed that no two key values are the same.

To simplify the problem, the tree is constructed as follows:

\-  The root of the tree is node $1$

\-  For each $2≤i≤N$, There is an edge between $i$ and $⌊i/2⌋$

## Output

If the tree is a Max-heap, print "`Max`"

If the tree is a Min-heap, print "`Min`"

If the tree is not a heap, print "`Neither`" (without quotes)

## Sample Input

```
7
55 6 12 4 2 5 8
```

## Sample Output

```
Max
```

## HINT

**Do NOT use any STL related to Heap and BST!**
