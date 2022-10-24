## Problem A: Polynomial Summation

Time Limit: 2 Sec Memory Limit: 512 MB

## Description

Given two polynomials with **n** and **m** terms, please calculate the **sum** of the two polynomials.

**Inputs and outputs are exponentially smaller to larger**

**You must use your self-implemented linkedlist to solve this problem.**

## Input

The first line has two numbers: **n and m (0<n,m<1000000)**

The next **n** lines are the **coefficients** and **exponents** of the terms in the first polynomial.

After that, the next **m** lines, are the **coefficients** and **exponents** of the terms in the second polynomial.

The values of all **coefficients** and **exponents** are in the range **(-1e9,1e9)**

## Output

The first line is an integer **k**, it is the number of terms in the result.

The next **k** lines are the **coefficients** and **exponents** of the result.

If the coefficient of the item is 0, you should not count it as result.



## Sample Input

```
2 2
2 1
1 3
2 3
1 4
```

## Sample Output

```
3
2 1
3 3
1 4
```

## HINT

Please use fast I/O.