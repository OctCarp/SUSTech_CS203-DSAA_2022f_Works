## Problem F: Math Problem

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Let $S(X)$ be a function with variable $X$, it can be represented by the formula as $S(X)=\sum_{j=1}^{X}f(j)$, where $f(x)$ consists of one or more functions in function set $F=\{C,C/x,C\sin{x},C \cos{x},C/\sin{x},C/\cos{x},C^x,Cx\}$ with $C$ is a constant integer ranging from $0$ to $10^9$.

## Input

The 1st line of input contains a single integer $t (1≤t≤10^4)$, the number of test cases.

There is a string $s(1≤|s|≤100)$ in each line of the rest t lines.

String s indicates the formula of $f(x)$. Fraction is presented as a/b. $C^x$ is presented as C^x. Note that the constant $C$ will not be omitted when $C=1$. Two adjacent functions in $f(x)$ are connected by +.

## Output

For each test case, print "`yes`"(without quotes) in a line if $S(X)$ is convergent, otherwise print "`no`".

## Sample Input

```
2
2sinx+0cosx+4x+1/sinx+0
0
```

## Sample Output

```
no
yes
```

## HINT


we say $S(X)$ is convergent if $\lim_{X\rightarrow\infty}S(X)=A$
