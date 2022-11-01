## Problem B: Queue operators

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Giving a queue and 2 kinds of operations: "`E x`" means add x to the rear of the queue, "`D x`" means pop the front `x` elements of the queue.

## Input

The first line contains an integer $n(1≤n≤10^5)$. Each of the following n lines is an operation: `E x` or `D x`. We guarantee operation `D` does not empty the queue.

## Output

Output the front element in queue **in a single line** for each "`D`" operation

## Sample Input

```
6
E 1
E 2
E 3
D 2
E 1
D 1
```

## Sample Output

```
3
1
```