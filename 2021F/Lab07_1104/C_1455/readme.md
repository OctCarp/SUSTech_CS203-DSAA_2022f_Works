## Problem C: Tree Height

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

There is a complete binary tree, and you will get the number of nodes in this tree. You are asked to find the height of the tree.

Notice that the height of a leaf node is $1$, and the height of any other nodes equals the maximum height among all subtrees plus one. And the height of a tree equals the height of the root node in the tree.

## Input

The first line contains one integer $T(1≤T≤100000)$, which denotes the number of the test cases.

Then $T$ lines follow. Each line contains an integer $num (1≤num≤10^{18})$, which denotes number of the nodes in this tree.

## Output

$T$ lines. Each line contains one integer denotes the height of the tree in that case.

## Sample Input

```
3
3
4
5
```

## Sample Output

```
2
3
3
```
