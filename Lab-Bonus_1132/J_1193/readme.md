## Problem J: Construction

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Yuki is a wise girl and she rules a country named Blossom.

Blossom is a big country with $n$ cities, and there are mm roads determined to be constructed. Due to many reasons during construction, different roads might have different costs to be built. The roads are **bidirectional**, that is a road from $u$ to $v$ **can** be passed from $v$ to $u$.

Since Yuki wants to make the construction more economical, she decides to choose some of the roads to construct and wants to spend the least money. However, to make the traffic in Blossom convenient, all the cities in Blossom are needed to be connected after construction. Your task is to determine the **minimum** cost of construction.

## Input

The first line contains two integers: $n$ and $m(1≤n≤1000,1≤m≤10000)$ — the number of cities and roads to be constructed in Blossom.

Each of the next mm lines contains three space-separated integers: $u,v$ and $w(1≤u,v≤n,1≤w≤10^6)$, meaning that there is a bidirectional road from city $u$ to city $v$ considered to be built. And the cost of this edge is $w$. Cities are numbered from $1$ to $n$.

It is guaranteed that there is at least one plan to connect all cities.

## Output

Print one line with an integer — the minimum cost of the construction.

## Sample Input

```
4 4
1 2 2
2 3 2
3 4 2
4 1 2
```

## Sample Output

```
6
```