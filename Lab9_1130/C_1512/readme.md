## Problem C: Naive Problem

Time Limit: 2 Sec Memory Limit: 256 MB

## Description

Tenshi is given a connected undirected graph with $n$ vertices $m$ edges (weight of every edge is $1$) by Justin_CaO, and a total of $k$ colors of stones, and **exactly one** stone (of one of $k$ colors) at each vertex, the cost of transporting a stone from $u$ to $v$ is the shortest path length from $u$ to $v$. 

Tenshi is busy with ICPC (International Carrot Placing Contest, prepared by FluffyBunny), so this graph is sent to you!

Your goal is to compute the **minimum cost** of transporting a stone of at least $c$ colors to $T$ for each vertex $T (T=1,2,…,n)$.

## Input

$1≤n≤10^5,0≤m≤10^5,1≤c≤k≤\min(n,100)$

$4$ integers $n,m,k,c$ in the first line of input

next line there are $n$ integers $a_1,a_2,…,a_n$, where $a_i$ is the color of $i$−th vertex's stone

In the next $m$ lines edges described, edge is described by two integers $u,v$

## Output

Print $n$ numbers

$T$-th of them is the minimum cost of vertex $T$

Separate numbers with spaces.

## Sample Input

```
10 10 3 2
2 2 2 3 2 3 2 2 1 2
9 7
6 5
2 3
2 5
6 4
1 10
9 10
8 5
5 1
9 6
```

## Sample Output

```
2 2 3 2 1 1 1 2 1 1
```
