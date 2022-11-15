## Problem C: City Selection

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

There are $n$ cities numbered from $1$ to $n$, and $n−1$ roads connecting these $n$ cities, i.e., it is a tree with $n$ nodes. The task is to select as less cities as you can to satisfy some constraints. A constraint is represented by three numbers $A,B$ and $n_A$. This constraint means that if we cut the road between city $A$ and city $B$ (we ensure the two cities are connected by a road), the number of selected cities which can reach to city $A$ is no less than $n_A$. Please find the minimum number of cities you should select to satisfy all constraints. If it is impossible to satisfy all constraints, please print `-1`.

## Input

The first line contains an integer $n(2≤n≤200000)$ which means the number of cities.

Then $n−1$ lines follow. Each line contains two integers $u,v(1≤u,v≤n)$ which means a road between city $u$ and city $v$.

Then one line contains an integer $m(1≤m≤400000)$ which means the number of constrains. 

Then mm lines follow. Each line contains three integers $A,B$ and $n_A(0≤n_A≤400000)$ which describe the constraint (we ensure there is a road between city $A$ and city $B$).

## Output

Print the minimum number of cities you should select to satisfy all constraints. If it is impossible to satisfy all constraints, please print `-1`.

## Sample Input

```
7
1 2
1 3
2 4
2 5
3 6
3 7
2
1 2 3
1 3 3
```

## Sample Output

```
5
```