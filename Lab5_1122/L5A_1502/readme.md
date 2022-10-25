## Problem A: Color the String

Time Limit: 1 Sec Memory Limit: 128 MB Special Judge

## Description

Given a text $t$ and $n$ strings $s_1,s_2,⋯,s_n$. In each operation, you can choose a string $s_i$ and color one of the $s_i$ in $t$ to blue. The coloring can intersect arbitrarily.

Determine the minimum number of operations you need to color the whole text t into blue. If it is impossible to color the whole text, print out -1.

## Input

The first line contains an integer $T(1≤T≤100)$, i.e., the number of test cases.

For each test case, the first line contains the text string $t(1≤|t|≤100)$, which only has lower English letters.

The second line contains an integer $n(1≤n≤10)$, i.e., the number of strings.

Then $n$ lines followed, each is a string $s_i(1≤|s_i|≤10)$, which also only has lower English letters.

## Output

For each test case, if it is impossible to color the whole text, print -1 in a single line. Otherwise, print the minimum number of operations $m$ in the first line. Then for the next $m$ lines, print two integers $w$ and $p$, which is the index of $s_i$ and the starting index of $t$ in this operation. You can print the operations in any order.

If there are multiple solutions, you can print any of them.

## Sample Input

```
2
ababab
2
aba
ab
abcdef
3
abcd
bc
cdefg
```

## Sample Output

```
3
1 3
2 1
2 5
-1
```

## HINT

For the first sample, the origin text $t$ is ababab.
After the first operation, the text $t$ becomes ab**aba**b.
After the second operation, the text $t$ becomes **ababa**b.
After the third operation, the text $t$ becomes **ababab**.