## Problem E: Dateri's visit

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

There is a tree with $n$ nodes and numbered from 1 to $n$, connected by $n−1$ edges. The root of the tree is node 1. Now Dateri is on the root node and wants to visit each node in the tree and return the root. Also, he wants to pass each edge exactly twice and visit the leaves in a specific order. Your task is to find whether there exists such a route satisfying Dateri's request.

## Input

The first line contains an integer $n(3 ≤ n ≤ 5000)$, the number of nodes in the tree.

Then next $n − 1$ lines describe edges. Each edge is described with two integers — indexes of nodes which it connects.

Then the next line contains $k$ integers (here $k$ is the number of leaves in the tree), which describes the order in which the leaves should be visited. Guaranteed that each leaf node appears in this order exactly once.

## Output

If the route does not exist, output $−1$.

Otherwise, output $2n−1$ indexes of the tree, describing the route. Multiple integers in one line must be separated by exactly one space.

## Sample Input

```
6
1 2
1 3
2 4
4 5
4 6
5 6 3
```

## Sample Output

```
1 2 4 5 4 6 4 2 1 3 1 
```
