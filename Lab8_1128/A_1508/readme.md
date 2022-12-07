## Problem A: Easy Graph Problem

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given an undirected graph with $m$ edges, whose nodes are indexed from $1$ to $n$.
You are given $q$ queries in the form of two integers $x$ and $y$. You have to check if there is an edge connected $x$ and $y$.

## Input

The first line contains three integers $n,m,q(n≤1000,m,q≤100000)$, i.e. the number of nodes, the number of edges, and the number of queries.
Then $m$ lines follow. Each line contains two integers $u,v(u≠v,1≤u,v≤n)$ which means an undirected edge connected $u$ and $v$.
Then $q$ lines follow. Each line contains two integers $x,y(x≠y,1≤x,y≤n)$ which means an undirected edge connected $x$ and $y$.

## Output

For each query $x,y$, output "`Yes`" (without quotes) if there is an edge connected $x$ and $y$, and "`No`"(without quotes) otherwise.

## Sample Input

```
5 5 5
1 2
2 3
3 4
4 5
2 4
1 3
4 2 
2 1
5 4
5 2
```

## Sample Output

```
No
Yes
Yes
Yes
No
```

## HINT

There is no guarantee that there are no multiple edges.
