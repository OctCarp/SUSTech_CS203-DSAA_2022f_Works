## Problem D: Huffman

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

Given $N$ integers, you are required to merge them into one single integer using $N−1$ operations. During each operation, you can choose two integers $x$ and $y$ and replace the two integers with one single integer $x+y$, which costs $x+y$ power.

Now you wonder the minimum sum of power possible to complete the mission.

## Input

The first line contains one integer $N(1≤N≤5×10^5)$

The second line contains $N$ integers $A_1,A_2,...A_N(1≤A_i≤10^7)$, denoting the $N$ integers you are required to merge.

## Output

Output one single integer indicating the minimum power to complete the mission.

## Sample Input

```
4
5 1 9 2
```

## Sample Output

```
28
```

## HINT

**Do NOT use any STL related to Heap and BST!**
