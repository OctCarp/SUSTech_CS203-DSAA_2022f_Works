## Problem E: Pay to swap

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a random sequence $\{a\}$ with $n$ distinct elements. You can swap two adjacent elements each time, and the cost is the smaller one. You want to know the minimum cost to sort the sequence to a ascending sequence.

For example, if you swap $(a_i,a_{i+1})$, then the cost of this operation is $min(a_i,a_{i+1})$

## Input

The first line of the input contains one integer $n$.

The second line contains $n$ integers $a_1,a_2,...,a_n$.

For all cases, $1≤n≤10^5,0≤a_i≤10^9$

## Output

Output one integer indicates the minimum cost.

## Sample Input

```
5
1 3 2 4 5
```

## Sample Output

```
2
```
