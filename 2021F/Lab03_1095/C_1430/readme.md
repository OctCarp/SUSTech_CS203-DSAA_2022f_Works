## Problem C: Insertion or Selection

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given an unsorted sequence, please sort it using insertion sort and selection sort respectively, and compare which algorithm is better.

We define the "swap two numbers" and "compare two numbers" are one operation. A sort algorithm is better means this algorithm can sort the target sequence with less operation. It's guaranteed that the numbers of operations of two algorithms are not the same in all test cases.

## Input

The first line contains an integer $T$, representing the number of test cases.

For each test case, the first line will be an integer $n$ showing the length of array. Then there are $n$ integers.

For all cases, $1≤T≤10,2≤n≤10^3$

## Output

For each test case, the first line you need to output the sorted array in the ascending order.

The second line, you need to output the better algorithm in this case.

if the insertion sort is better, print "`Insertion Sort wins!`" (without quotation marks)

if the selection sort is better, print "`Selection Sort wins!`" (without quotation marks)

## Sample Input

```
2
3
1 3 2
3
3 2 1
```

## Sample Output

```
1 2 3
Insertion Sort wins!
1 2 3
Selection Sort wins!
```
