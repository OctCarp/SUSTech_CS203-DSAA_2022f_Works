## Simple Problem

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a non-decreasing array $A$, containing $N$ positive integers $a_1,a_2,...,a_n$. There are $Q$ queries. Each query gives $x,y$, you are asked to check how many integers in $A$ which are satisfying $x \textless a_i \textless y$.

## Input

The first line of the input contains two integers $N$ and $Q$ $(1≤N≤10^5,1≤Q≤10^5)$ −− the length of $A$ and the number of query.

The second line contains $N$ integers $a_i(1≤a_i≤10^9)$.

The ii-th of the next $Q$ lines contains two integers $x_i,y_i(1≤x≤y≤10^9)$.

## Output

For each query, print "NO" (without quote) if none of integers in $A$ satisfied the condition.
Otherwise, print "YES"(without quote) and the number of satisfied integers.

## Sample Input

```
5 3
1 2 3 4 5
3 5
1 6
5 5
```

## Sample Output

```
YES 1
YES 4
NO
```