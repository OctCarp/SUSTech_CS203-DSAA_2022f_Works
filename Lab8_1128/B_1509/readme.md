## Problem B: Simple Graph Problem

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a directed graph with $m$ edges, whose nodes are indexed from $1$ to $n$.
Satori wants to know for each node $i$, the maximum index node it can reach.

## Input

The first line contains three integers $n,m(1≤n,m≤100000)$, i.e. the number of nodes and the number of edges.
Then $m$ lines follow. Each line contains two integers $u,v(u≠v,1≤u,v,≤n)$ which means a directed edge from $u$ to $v$

## Output

For each node $i$, print an integer with the maximum index of the node it can reach.

## Sample Input

```
6 6
2 6
6 5
3 2
6 3
2 1
4 5
```

## Sample Output

```
1 6 6 5 5 6
```

## HINT

There is no guarantee that there are no multiple edges and self-loops.

