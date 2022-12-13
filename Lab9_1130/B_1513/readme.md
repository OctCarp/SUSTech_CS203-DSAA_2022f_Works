## Problem B: Sign in Problem

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a connected undirected graph of $n$ vertices with $m$ edges (may with negative weights)(edge $i$ connects vertices $u_i,v_i$ and with weight $w_i$), you can perform edge deletion, where the gain from deleting an edge is the edge weight of that edge, but you need to ensure that the graph remains connected after performing the edge deletion operation.

Your goal is to **maximize the sum of the gains** from all operations.

## Input

$1≤n≤2×10^5$

$n−1≤m≤2×10^5$

$1≤u_i,v_i≤n$

$−10^9≤w_i≤10^9$

## Output

Print one number as your answer

## Sample Input

```
3 3
1 2 1
2 3 0
3 1 -1
```

## Sample Output

```
1
```

