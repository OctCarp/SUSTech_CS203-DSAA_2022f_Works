## Problem B: Double Median

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a sequence $\{a_1,a_2,...,a_n\}$ with $n$ numbers.

Please output the **double** of the median of $\{a\}$.

The definition of the median: Assume mm is the median of $\{a\}$:

- if $n$ is odd, then $2m=2a_{\frac {n+1}{2}}$;
- if $n$ is even, then $2m=a_{\frac {n}{2}}+a_{\frac {n}{2}+1}$

## Input

The first line is an integer $n$

The second line will be $n$ integers: $a_1,a_2,...,a_n$

For all cases, $1≤n≤5∗10^6$, $0≤a_i≤2147483647$

## Output

Output one integer indicates the double of the median.

## Sample Input

```
6
3 2 1 4 5 6
```

## Sample Output

```
7
```

## HINT

In the sample case, the median is 3.5, so the answer is 3.5 * 2 = 7
