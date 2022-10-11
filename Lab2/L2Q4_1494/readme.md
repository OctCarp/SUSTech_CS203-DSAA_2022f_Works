## Swapping

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

There are $n$ integers $a_1,a_2,…,a_n$ in an array $A$. Suppose you can swap two digits of $a_i$ in the array at most $m$ times. The cost of each swap is $k$. We define $S=∑A–x×k$, where $x$ is the times of swapping applied, $A$ is the corresponding integer array after $x$ times swapping actions. Please find the maximum value of $S$.

## Input

There will be two lines.

The first line will be three integers: $n,m,k$.

The second line will be n integers $a_1,a_2,…,a_n$.

For all test cases, $1≤n≤2∗10^5,0≤m≤2∗10^5,0≤k≤10^9,|a_i|≤10^9$.

## Output

There will be only one integer: the maximum value of S

## Sample Input

```
3 4 20
154 24 15
```

## Sample Output

```
556
```

## HINT

1. Leading zero is permitted after swapping.
2. The sample example only takes 3 swaps.