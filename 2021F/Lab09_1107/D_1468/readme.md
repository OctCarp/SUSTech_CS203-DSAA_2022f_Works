## Problem D: Sum

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

An N × M matrix of non-negative integers, please take out several numbers from it such that the summation of these numbers is maximized. You should guarantee that any two taken out numbers are not adjacent, we say $a$ is adjacent to $b$ if $b$ is one of $a$'s 8-connected neighborhoods in the matrix

## Input

The first row has a positive integer $T(1≤T≤20)$, which indicates that there are $T$ groups of data.
For each set of data, the first row has two positive integers $N,M(1≤N,M≤6)$ , which describe the number matrix as $N$ rows and $M$ columns.
The next $N$ rows, with $M$ non-negative integers in each row, describe this numerical matrix.

## Output

A total of $T$ rows, one non-negative integer per row, and the output of the resulting answer

## Sample Input

```
3
4 4
67 75 63 10
29 29 92 14
21 68 71 56
8 67 91 25
2 3
87 70 85
10 3 17
3 3
1 1 1
1 99 1
1 1 1
```

## Sample Output

```
271
172
99
```
