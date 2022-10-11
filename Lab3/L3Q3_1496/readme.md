## Matrix Swapping

Time Limit: 2 Sec Memory Limit: 512 MB

## Description

You are given a $n×m$ size matrix $A$. The matrix has $n$ rows and $m$ columns. The element at the $i$-th row and $j$-th column is $A_{i,j}$. Consider two sub-matrices in it, these two sub-matrices are defined by (i) the coordinates of the top left elements of these two sub-matrices are $(x_1, y_1)$ and $(x_2, y_2)$, respectively, and (ii) the size of each sub-matrix is $l_1×l_2$. The matrix swapping operation is swapping every elements pair in these two sub-matrices. For example, for all $i (0 ≤ i < l_1)$ and $j (0 ≤ j < l_2)$, swap $A_{x_1+i,y_1+j}$ and $A_{x_2+i,y_2+j}$. 

**We guarantee these two swapping sub-matrices are not adjacent or overlapping**.

What the result matrix is after applied q times matrix swapping operations?

## Input

The first line contains three integers $n, m, q (2 ≤ n , m ≤ 1000, q ≤10000)$, denotes the size of matrix $A$ and the total times of swapping operation.

It follows $n$ rows, each of row includes $m$ integers, which denotes the $n×m$ matrix $A$.

Then it follows $q$ lines, each line includes six integers $x_1, y_1, x_2, y_2, l_1, l_2$.

## Output

The result matrix $A$ with $n$ rows, m columns after $q$ times swapping operations.

## Sample Input

```
4 2 1
1 1
1 1
2 2
2 2
2 1 4 1 1 2
```

## Sample Output

```
1 1 
2 2 
2 2 
1 1
```