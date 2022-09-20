## Arrange Seats in a Round Table

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

Suppose there are n students in CS203 DSAA, the height of each student is $a_i(1≤i≤n)$. You are asked to arrange these students to the seats (i.e., $b_1,b_2,…,b_n$) in a round table such that the minimum value, denoted by $k$, of the medium height of every three students in consecutive seats (i.e., $b_i, b_{(i+1)mod(n+1)}, b_{(i+2)mod(n+1)}$) is maximized.



Please print $k$ and the height of the student in seats $b_1,b_2,…,b_n$.

If it has more than one possible solution, print the height of the student in seats $b_1,b_2,…,b_n$ with smallest lexicographical order. 



## Input

There will be two lines.

The first line will be an integer $n$.

The second line will be $n$ integers $a_1,a_2,...,a_n$.

For all test cases, $3≤n≤10^6,0≤a_i≤10^9$.

## Output

There will be two lines.

The first line prints the value of $k$

The second line prints the height of the student in seats $b_1,b_2,…,b_n$.

## Sample Input

```
6
6 5 4 3 2 1
```

## Sample Output

```
3
1 3 4 2 5 6 
```

## HINT

You can find the definition of lexicographical order at https://en.wikipedia.org/wiki/Lexicographic_order