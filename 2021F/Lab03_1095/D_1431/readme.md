## Problem D: No average

Time Limit: 1 Sec Memory Limit: 128 MB Special Judge

## Description

Given a sequence $\{a\}$ with $n$ different numbers (n is even). Please permutate this sequence to form a circle, so that each element on this circle is not equal to the average of two neighbors.

More formally, find an permutation $\{b\}$ of sequence $\{a\}$, such that:

- $∀i∈\{2,3,...,n−1\},b_i≠\frac{b_{i−1}+b_{i+1}}{2}$

- $b_1≠\frac{b_2+b_n}{2}$

- $b_n≠\frac{b_{n−1}+b_1}{2}$

There may be more than one answer, you just need to print one of them.

We guarantee that there is at least one solution for each test case.

## Input

 The first line will be a integers $n$ as we mentioned before.

 The second line will be $n$ integers in sequence, $a_1,a_2,...,a_n$

 For all test cases, $n$ is even and $3<=n<=10^6,0≤a_i≤10^9$

## Output

The only line will be $n$ integers, $b_1,b_2,...,b_n$

## Sample Input

```
6
3 2 1 4 5 6
```

## Sample Output

```
1 2 4 3 5 6
```

## HINT

You may need this. Java Fast IO template: https://paste.ubuntu.com/p/6ybMcVXvz5/
