## Problem F: String operations

Time Limit: 2 Sec Memory Limit: 128 MB

## Description

Given a string S and three operators:

1. **Insert(ch, p)**, inserting the char **ch** to position **p**.
2. **Find(p)**, finding the char at position **p** and print it to screen.
3. **Transform(l,r)**, **transforming** the characters from position l to position r (including l, r) (we define **transforming** as for each character c in l to r we apply ('a' + 'z' - c) to transform it)

## Input

The first line has a string S . The second line has an integer n, which is the number of operations. The next n lines are one operation per line. For each presentation, we use 1 for **Insert** , 2 for **Find**, 3 for **Transform**. ( len(S) ≤ 2000000, n ≤100000)

## Output

Follow the output definition of each operation.

## Sample Input

```
madamimadam
5
1 b 1
1 b 2
2 3
3 1 3
2 2
```

## Sample Output

```
m
y
```

## HINT

You are likely to encounter **TLE** in this question, which is quite normal

So you need to use a more efficient LinkedList for this problem
