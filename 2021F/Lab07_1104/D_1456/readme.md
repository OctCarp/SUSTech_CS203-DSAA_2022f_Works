## Problem D: Tree Number

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given the order of a tree's pre-order traversal and post-order traversal, you are asked to find out how many distinct binary trees fit the given traversal orders.

## Input

The first line contains one integer $T$, which denotes the number of the test cases $(1≤T≤10000)$. The nodes of a binary tree are represented by capital letters, and no two distinct nodes are represented with the same letter.

In each case, the first line contains a string $S_{pre}$, denoting the access order of the pre-order traversal. The second line contains a string $S_{post}$, denoting the access order of the post-order traversal $(|S_{pre}|,|S_{post}|≤26)$.

## Output

Output the number of binary trees which meet the requirements.

## Sample Input

```
1
ABCD
DCBA
```

## Sample Output

```
8
```
