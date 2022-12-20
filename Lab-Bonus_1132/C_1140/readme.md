## Problem C: Combine polynomials[Easy]

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Linked List is one of most simple and fundamental data structure, thus it has a very wide application. For example, linked list can be used to calculate the sum of two polynomials. Now, given two polynomials by the coefficient and exponent of each term, please output the sum of the two polynomials.

## Input

First line will be a positive integer $T(T≤100)$, which is the number of test cases.

The first line will be an integer $n$, which is the number of terms of the first polynomial. Then $n$ lines will be the coefficients and exponents of the terms.

After $n + 1$ lines, there will be an integer $m$ for the number of terms of the second polynomial. And $m$ lines of (coefficient, exponent) pairs.

($0≤n,m≤1000$, all exponents are in the range $[0, 10^9]$, all coefficients are in the range $[-10000, 10000]$)

## Output

For each test case, print the polynomial in ascending order of each exponents. Be attention to the format of the polynomial.

## Sample Input

```
2
2
1 2
2 3
2
2 2
1 4
2
2 0
-2 1
2
3 1
1 2
```

## Sample Output

```
3x^2+2x^3+x^4
2+x+x^2
```