## Problem D: Minimum Difference

Time Limit: 4 Sec Memory Limit: 256 MB

## Description

Given a sequence $A$ with $n$ items, the weights of each item are $a_i$. We define **the minimum weight difference** of $a_i$ as $h_i=min_{j>i}|a_j−a_i|$. Please compute **the minimum weight difference** of each item.

## Input

The first line has a integer $n(2≤n≤2×10^6)$. 

The second line has n space-separated integers: $a_1,a_2,…,a_n$  all the elements of the array $A (1≤a_i≤10^9$).

## Output

Print space-separated integers: 
$h_1,h_2,…,h_{n−1}$.

## Sample Input

```
5
1 2 3 4 5
```

## Sample Output

```
1 1 1 1
```

## HINT


It can be solved in a simple and efficient way by using **sorting algorithm** and **linked list** elegantly, . Please note that the size of input might be really large, so you might want to use an efficient way to read the input data.
