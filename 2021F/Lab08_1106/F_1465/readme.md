## Problem F: Girls and bunnies

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

Recently Satori opened a bunny store. Initially the store has no bunny at all. Yet at the $i$-th day of the next MM days, one of the following events will occur:

1. A girl with property $A_i$ enters the store, intending to adopt a bunny.
	
	- If there are bunnies available, she will adopt the $j$-th bunny with the minimum value of $|A_i−B_j|$ . If there are multiple bunnies with the same minimum $|A_i−B_j|$, she will choose the one whose $B_j$ is the smallest.
	
	- Otherwise, she will wait until one bunny chooses her.

2. A bunny with property $B_i$ enters the store, willing to be adopted.

	- If there are girls waiting to adopt, it will choose the $j$-th girl with the minimum value of $|B_i−A_j|$ as its owner. If there are multiple girls with the same minimum $|B_i−A_j|$, she will choose the one whose $A_j$ is the smallest.
	
	- Otherwise, it will stay at the store until one girl adopt her.

Each time when girl ii adopted a bunny $j$ successfully, Satori will earn $|A_i−B_j|$ coins.

Help Satori calculate the sum of coins she earns in total.

## Input

The first line contains a single integer $M(1≤M≤3×10^5)$

The next $M$ lines each follows one of the two formats below:

-  `1` $A_i$ Indicating a girl with property $A_i$ arrives $(1≤A_i≤10^9)$
-  `0` $B_i$ Indicating a bunny with property $B_i$ arrives $(1≤B_i≤10^9)$

It is guaranteed that all integers in $A$ and $B$ are distinct.

## Output

Output one single integer indicating the total money Satori earns.

## Sample Input

```
6
1 5
0 9
0 3
0 1
1 2
1 7
```

## Sample Output

```
9
```

## HINT

**Do NOT use any STL related to Heap and BST!**

