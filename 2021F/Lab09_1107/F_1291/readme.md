## Problem F: The Elves

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

To make the kingdom more prosperous, Pisces decides to ally with the elves living in the forest. However, the elven elders want to test Pisces, so they give him a simple question. Given a DAG with $n$ nodes and $m$ edges, the elven elders want to know the value of $\sum_{i=1}^{n}\sum_{j=1}^{n}{count(i,j)⋅a_i⋅b_j}$ mod $1e9+7$, where $count(x,y)$ is defined by the number of different paths from $x$ to $y$ and $count(x,x)$ = 0, and $a, b$ are 2 given arrays. It is too hard for Pisces to answer this question, so he turns to you for help.

## Input

The first line contains an integer $T(1≤T≤10)$, which denotes the number of test cases.

For each test case, the first line contains 2 integers $n$ and $m(1 ≤n,m ≤ 10^5)$ — the number of nodes and the number of edges, respectively. Each of the next $n$ lines contains 2 integers $a_i$ and $b_i$. And for the next $m$ lines, each line contains 2 integers $u$ and $v$ denoting a directed edge going from node $u$ to node $v(1≤u,v ≤ n)$.

## Output

For each test case, print the answer.

## Sample Input

```
3
3 3
1 1
1 1
1 1
1 2
1 3
2 3
2 2
1 0
0 2
1 2
1 2
2 1
500000000 0
0 500000000
1 2
```

## Sample Output

```
4
4
250000014
```
