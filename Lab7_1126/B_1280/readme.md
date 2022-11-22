## Problem B: Cut the stick

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Lanran wants to cut one stick with length $L$ into exactly $N$ sticks with length $L_i(i=1,2...N)$, so $L=∑L_i$. However, the cost to cut one stick in to two pieces is the length of the stick, that means cutting a stick with length $x$ will cost $x$. Now he wants to know the minimal cost if he cuts stick optimally to get $N$ sticks.

## Input

The first line will be an integer $T(1≤T≤100)$, which is the number of test cases.
For each test data: 
The first line contains an integer $N (1≤N≤10^3)$ — the number of sticks Lanran needs to get.
Then the next one line contains $N$ integers, the $i$-th integer $L_i(1≤p_i≤10^5)$ indicates the length of $N$ sticks Lanran wants to get.

## Output

For each case, contains one line, print the minimal minimal cost.

## Sample Input

```
1
4
1 4 2 6
```

## Sample Output

```
23
```

## HINT

**Do NOT use any STL related to Heap and BST!**

