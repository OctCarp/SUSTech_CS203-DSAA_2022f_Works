## Problem E: Portal

Time Limit: 2 Sec Memory Limit: 256 MB

## Description

Yuki is a magical girl and she has the ability to activate portals.

The country Yuki lives in has $n$ cities and mm roads at certain distances. The cities are numbered from $1$ to $n$ and all the roads are **unidirectional**, that is a road from $u$ to $v$ **cannot** be passed from $v$ to $u$. Also, there are $p$ portals in the country, each of them connects two cities **unidirectional** with **no** distance. Since Yuki doesn't grasp magic thoroughly, she can activate **at most** $k$ portals.

Now Yuki is curious about what is the **minimum** distance between $S$ and $T$ if she activates at most $k$ portals.

## Input

The first line contains four integers: $n, m, p$ and $k(1≤n,m,p≤50 000,0≤k≤10)$ --- the number of cities, roads, portals and the number of portals Yuki can activate at most.

Each of the next mm lines contains three integers: $u, v$ and $w(1≤u,v≤n,1≤w≤1000000)$, meaning that there is a unidirectional road from city $u$ to city $v$ at distance $w$.

Each of the next pp lines contains two integer: $u$ and $v(1≤u, v≤n)$, meaning that there is an inactive portal from city $u$ to city $v$. Please note that when it is **active**, Yuki can **only be** teleported from city $u$ to $v$ unidirectionally.

The last line contains two integers: $S$ and $T(1≤S,T≤n)$ --- the origin and destination.

## Output

Print one line with the result --- the minimum distance between city $S$ and $T$.

It is guaranteed that Yuki can move from city $S$ to $T$ by activating at most $k$ portals.

## Sample Input

```
5 6 3 1
1 3 4
1 2 2
3 5 6
2 4 3
3 4 1
4 5 2
2 3
1 4
1 2
1 5
```

## Sample Output

```
2
```
