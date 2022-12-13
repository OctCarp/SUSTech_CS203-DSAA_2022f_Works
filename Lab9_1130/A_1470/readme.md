## Problem A: Travel

Time Limit: 1 Sec Memory Limit: 1024 MB

## Description

There are $n$ cities and $m$ roads, and each road has a length. These n cities are numbered from $1$ to $n$. Please find the shortest path from city_1 to city_n.

## Input

The first line contains two integers $n, m (1≤n,m≤10^5)$, indicating that there are $n$ cities, $m$ roads.

The next $m$ lines, each line contains 3 integers, $u, v, w (1≤u,v≤n,1≤w≤10^9)$, indicating that there is a unidirectional road from $u$ to $v$, cost $w$.

## Output

Please output the minimum cost from city_1 to city_n in one line. If there is not exist a road from city_1 to city_n, please output `-1`.

## Sample Input

```
3 3
1 2 2
2 3 1
1 3 1
```

## Sample Output

```
1
```
