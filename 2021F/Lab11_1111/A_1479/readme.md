## Problem A: Split Sticks

Time Limit: 2 Sec Memory Limit: 512 MB

## Description

Alice has a bundle of sticks. She wants to select some sticks and split them into $k$ rows.
For beauty, the difference between the lengths of all sticks in the same row shall not exceed 1 and each row has the same number of sticks. The length of each stick is a positive integer from 1 to $n$.
For every possible length, you know the amount of stick with that length.
Please calculate the maximum number of sticks Alice can select.

## Input

The 1st line is a positive integer $T(1⩽T⩽10000)$ which is the number of test cases.
For each test case:
The first line contains two integers $n(1⩽n⩽30000)$ and $k(1⩽k⩽10^{12})$, representing the number of different length of sticks and the number of rows the stick needs to be divided into, respectively
The second line contains n integers $C_1,C_2...C_n(0⩽Ci⩽10^{12})$, representing the number of sticks in each length
Ensure that the sum of n of all cases does not exceed 30000

## Output

For each case, output the maximum number of sticks Alice can select.

## Sample Input

```
5
3 4
7 1 13
1 1
100
1 3
100
2 1
1000000000000 1000000000000
4 1
10 2 11 1
```

## Sample Output

```
16
100
99
2000000000000
13
```

## HINT

1. The arrangement is $[3,3,3,3], [1,2,1,1], [1,1,1,1], [3,3,3,3]$(each list represents a row)

2. All the sticks can be arranged in the same row

3. 33 sticks with length 1 in each 3 rows

4. All the sticks can be arranged in the same row

5. All sticks with lengths of 2 and 3 are arranged in the same row
