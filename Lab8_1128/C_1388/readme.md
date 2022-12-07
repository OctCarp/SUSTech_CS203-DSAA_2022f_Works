## Problem C: Cycles are Bad

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a graph with $n$ nodes and $m$ edges, we define cycles as paths which start from and end at the same point. One day, a student thinks that graphs with cycles are very "bad" and graphs without cycles are really "good". But he does not know how to distinguish them. Can you help him?

## Input

Line 1: Two integers $n(1≤n≤10^5)$ and $m(1≤m≤10^5)$, which means the graph has $n$ nodes and $m$ edges.
There are $m$ lines following:
Line 2~(m+1): Two integers $u, v$ which means there is an undirected edge between node $u$ and node $v$. Node indices are integers in range $[1,n]$.

## Output

Print whether the given graph is bad or not. Use "`Bad`" to indicate that the graph is bad and "`Good`" otherwise.

## Sample Input

```
3 3
1 2
2 3
1 3
```

## Sample Output

```
Bad
```
