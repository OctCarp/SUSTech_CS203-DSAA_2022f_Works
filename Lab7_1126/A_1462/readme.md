## Problem A: We only want the smallest

Time Limit: 3 Sec Memory Limit: 128 MB

## Description

We construct an array $C$ out of two given array $A$ and $B$ such that each element in array $C$ is the product of an element in $A$ and an element in $B$. For example, we have $A=[1,2,1]$ and $B=[5,2]$ , then $C=[5,2,10,4,5,2]$

Now we only want to know the first $K$ smallest element of array $C$.

## Input

The first line contains three integers $N$, $M$ and $K$, denoting the length of array $A$, the length of array $B$ and $K$ smallest respectively. $(1≤N,M≤5×10^5),K≤\min(5×10^5,N×M)$

The second line contains $N$ integers $A_1,A_2,...A_N(1≤A_i≤10^9)$

The third line contains $M$ integers $B_1,B_2,...B_M(1≤B_i≤10^9)$

## Output

Output $K$ integers separated by spaces in ascending order, denoting the first $K$ smallest elements in $C$.

## Sample Input

```
3 2 6
1 2 1
5 2
```

## Sample Output

```
2 2 4 5 5 10
```

## HINT

**Do NOT use any STL related to Heap and BST!**

