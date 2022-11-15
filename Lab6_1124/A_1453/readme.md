## Problem A: Paths

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a rooted tree numbered from 11 to $n$, each edge has a weight $w$. The root node of the tree is node $1$. You are asked to calculate the number of paths that start from the root, terminate in a leaf node, and satisfy the sum of edge weights in the path equals to $num$.

## Input

The first line contains two integers $n$ and $num$ $(1≤n≤5×10^5,1≤num≤2×10^9)$, indicating the number of tree nodes and the target number.

Then $n−1$ lines follow. Each line contains three integers $u,v,w(1≤u,v≤n,1≤w≤100)$ describing an edge. The first two integers are the indices of nodes that form an edge and the last integer indicates the weight of the edge.

## Output

Output an integer which means how many paths satisfying the sum of edge weights in the path equals to $num$.

## Sample Input

```
6 6
1 2 2
1 3 3
3 4 4
3 5 3
2 6 4
```

## Sample Output

```
2
```