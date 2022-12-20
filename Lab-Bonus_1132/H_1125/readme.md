## Problem H: Connected group

Time Limit: 3 Sec Memory Limit: 128 MB

## Description

Carol has a matrix of $n$ rows and $m$ columns. Every grid (the coordinate are from $1$) in the matrix has a number representing its color. If you stand in one grid, you can move to an adjacent grid if you satisfy these two requirements:

1. If you stand on $(x,y)$, then $(x+1,y),(x-1,y),(x,y-1),(x,y+1)$ are adjacent to you.
2. The color in your position are the same as the grid you are going to.

If you can reach one grid from another grid, then they are in the same group.

Now, you need to calculate how many groups the matrix has.

The most important thing is the first column are adjacent to the last column.

## Input

The first line will be an integer $T$, which is the number of the test cases $(1≤T≤10)$. For each test case, the first line will be two integers $n$ and $m(1≤n≤1000,1≤m≤1000)$. The following are $n$ lines, and each line will be $m$ integers. The $j$-th integer in the $i$-th line means the color of the grid$(i, j)$ (1≤ color≤ 5).

## Output

For each test, output the number of groups.

## Sample Input

```
1
3 4
1 2 3 5
1 2 3 1
1 3 3 5
```

## Sample Output

```
5
```