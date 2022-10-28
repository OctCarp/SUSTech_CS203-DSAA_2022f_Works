## Problem F: M-th Smallest Element

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

Given a $N×N$ matrix $A$, whose element in the $i$-th row and $j$ th column $A[i][j]$ is a number that equals $i^2+12345×i+j^2−12345×j+i×j$.

Please find the M-th smallest element in the matrix.

## Input

The 1st line is a positive integer $T(1⩽ T ⩽ 10)$ which is the number of test case.

Then $T$ lines follow. Each line has two integers $N(1⩽ N ⩽ 50000)$ and $M(1⩽ M ⩽ N×N)$ for a test case.

## Output

Output $T$ lines. Each line has an integer $ans$, the $M$-th smallest element in the matrix.

## Sample Input

```
2
1 1
2 1
```

## Sample Output

```
3
-12338
```

## HINT

The correspond solutions to the sample is :

1.  $A[1][1]=12+12345×1+12−12345×1+1×1=3$

2. $A[1][2]=12+12345×1+22−12345×2+1×2=−12338$

   $A[2][1]=22+12345×2+12−12345×1+2×1=12352$
   
   $A[2][2]=22+12345×2+22−12345×2+2×2=12$

  So the smallest element is -12338
