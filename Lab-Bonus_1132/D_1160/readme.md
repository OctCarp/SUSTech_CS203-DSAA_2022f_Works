## Problem D: Brackets Matching

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

There are n brackets, and you want to know whether they are matched. The brackets will only contain {, }, (, ), [, ]. Here is the matching rules. For example, {{[}]} is not matching, but [{{}}()] is matching. Please write a program to check whether the given string is matched or not. 

## Input

The ﬁrst line will be an integer $T$, which is the number of test cases. $(1≤T≤10)$
For each test case, the ﬁrst line will be an integer $n(1≤n≤30000)$
Then there is a line with $n$ brackets. 

## Output

For each test case, print `YES` if the test case is a matching case. Otherwise, print `NO`. 

## Sample Input

```
7
1
(
2
()
2
{]
6
[(){}]
4
(])[
8
[[{{}}]]
6
[][{]]
```

## Sample Output

```
NO
YES
NO
YES
NO
YES
NO
```