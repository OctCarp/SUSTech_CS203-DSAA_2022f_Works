## Problem B: Sport Meeting[Medium]

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Annual Sport meeting in S University starts again. This year, the rule of relay running is modified by president of sports department. The rule after modification is as follows:

The total length of the relay running is $L(1≤L≤10^9)$. There are $n(0≤n≤500000)$ possible places to place a new racer (there is a race in the start line). Every racer runs to the next racer in front of him and the final racer runs to the finish line. But the number of racers is limited to a number $m(1≤m≤n+1)$. Now the team of class 1788 want to know if they try to average the distance of every racer, how many meters one athlete should at most to run.

## Input

The input contains several test cases. The first line of each case contains three positive integer $L$, $n$, and $m$. 
Then $n$ lines follow. Each stands for the distance from the start line to the $n$-th possible place to place new racer, two places will not be the same.

## Output

For each case, output an integer standing for the meters one athlete should at most to run.

## Sample Input

```
6 1 2
2
25 3 3
11 
2
18
```

## Sample Output

```
4
11
```