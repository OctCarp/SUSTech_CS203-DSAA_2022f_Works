## Problem H: Skiing (Easy-15)

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Yuki is an outgoing girl and she enjoys all the sports, especially snow sports like skiing.

Now she is skiing in a world-famous ski resort — Super Ultra Ski Training Center (SUSTC). The map of SUSTC can be considered as a grid map with $n$ rows and $m$ columns. Since the ski facility is uneven, each grid $(i,j)$ has its own height $h_{i,j}$.

Yuki starts her skiing at the grid $(1,1)$ — the top left grid, and her destination is at the grid $(n,m)$ — the bottom right grid. Each time she can only ski to one of the adjacent grids — the left, the right, the above, or the below grid. Obviously, the minimum distance for Yuki to ski to the destination is $n+m−2$ if she chooses an arbitrary Manhattan path.

However, with the elevation change during her skiing, Yuki’s speed will also change remarkably. Specifically, suppose that the velocity of Yuki at grid $(x,y)$ is $v$, then it takes $\frac1v$ time units for Yuki to move to $(x,y+1)$, and the velocity at grid $(x,y+1)$ will be changed to $v⋅2^{h_{x,y}−h_{x,y+1}}$. Suppose that the initial velocity when Yuki at grid $(1,1)$ is $v_0=1$, could you please tell Yuki the minimum time for her to arrive at the destination.

## Input

The first line contains two integers: $n$ and $m(1≤n,m≤300)$ — size of the grid map.

Each of the next $n$ lines contains $m$ integers. The $j$-th number in the ii-th line denotes $h_{i,j}(1≤h_{i,j}≤15)$.

## Output

Print one line with the value — the minimum time for Yuki to arrive at the destination.

The value should be accurated to exactly **2** decimal places.

## Sample Input

```
2 3
1 2 3
4 5 6
```

## Sample Output

```
7.00
```
