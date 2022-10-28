## Problem E: Valentine's Day

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Today is Valentine’s day, and Pisces is going to date with the beautiful princess in the neighboring kingdom. There are $n$ cities numbered from $1$ to $n$ on the mainland, with Pisces in city $1$ and the princess in city $n$. There are $m$ unidirectional roads among these $n$ cities. Usually, it takes Pisces $1$ unit of time to travel from one city to another, but due to the probable existence of thorns, rivers or even robbers, some of the roads will take $2$ units of time to travel. In other words, the cost of traveling from one city to another is either $1$ unit or $2$ units of time. Pisces wants to know the minimum time that he can meet the princess.

## Input

The first line contains 2 integers $n(2≤n≤2∗10^5)$ and $m(1≤m≤4∗10^5)$.

In each of the next mm lines, there are 3 integers $u,v(1≤u,v≤n)$ and $w (1≤w≤2)$, which means there is a road from $u$ to $v$, and it takes $w$ unit(s) of time for Pisces to go through.

## Output

Print the minimum time in one line. Or, if he cannot reach the destination, print "`-1`" (without quotes).

## Sample Input

```
4 5
1 2 1
2 4 1
2 3 2
3 4 1
1 3 1
```

## Sample Output

```
2
```
