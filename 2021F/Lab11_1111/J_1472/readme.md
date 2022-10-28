## Problem J: Courier

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Van is a courier who needs to deliver $n$ parcels numbered from $1$ to $n$. When a parcel is delivered for the $i$-th time, we define its delivery priority to be $i$.
There are two restrictions on the order of delivery of parcels.
A parcel numbered $i$ has a delivery priority less than $k_i$
There is some restriction $(i,j)$ that the $i$-th parcel must be delivered earlier than the $j$-th parcel
Please help us to calculate the minimum delivery priority of each parcel among all possible options

## Input

The first line contains two positive integers $n(n≤2000)$ and $m(m≤10000)$, where $n$ represents the number of packages, and $m$ represents the number of restrictions of the second type.

The second line contains n positive integers $k_1,k_2,…,k_n$ and the next $m$ lines, each line contains two positive integers $a$ and $b$, representing a pair of relative take-off order restrictions $(a, b)$, where $a,b(1≤a,b≤n)$, which means that package $a$ must start before package $b$.

## Output

Contains $n$ integers $t_1, t_2, …, t_n$ represents the smallest possible starting sequence number for package $i$, and two adjacent integers are separated by spaces.

## Sample Input

```
5 5
4 5 2 5 4
1 2
3 2
5 1
3 4
3 1
```

## Sample Output

```
3 4 1 2 1
```
