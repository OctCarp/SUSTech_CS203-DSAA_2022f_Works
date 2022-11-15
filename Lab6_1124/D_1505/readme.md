## Problem D: Node Activation

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given a tree whose nodes are numbered from $1$ to $n$. Each node has a predefined value $p_i$. The task is to assign a non-negative value $e_i$ (i.e., $e_i≥0$) for each node to activate all nodes. A node $i$ is activated if and only if: (1) there exists two different nodes $j$ and $k$, and node $i$ is on the path between nodes $j$ and $k$ ($j≠k$, but node $i$ can be node $j$ or node $k$); (2) $\min(e_j,e_k)≥p_i$. Please find the minimum value of ($e_1+e_2+⋯+e_n$) to activate all nodes.

## Input

The first line contains an integer $n(2≤n≤2×10^5)$ which means the number of nodes.

Then $n−1$ lines follow. Each line contains two integers $u,v(1≤u,v≤n)$ which means an edge between node $u$ and node $v$.

Then one line contains $n$ integers $p_i(1≤p_i≤10^8)$.

## Output

Print the minimum value of $(e_1+e_2+⋯+e_n)$ to activate all nodes.

## Sample Input

```
4
1 2
2 3
2 4
2 3 1 1
```

## Sample Output

```
7
```

## HINT

Explanation for the example: one optimal assignment is $e_1=3,e_2=0,e_3=3,e_4=1$. Node $1$ is activated by nodes $1$ and $3$. Node $2$ is activated by nodes $1$ and $3$. Node $3$ is activated by nodes $3$ and $4$. Node $4$ is activated by nodes $4$ and $2$.

Tips: You can choose the node with the maximum $p_i$ value as the root.