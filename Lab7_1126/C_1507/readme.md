## Problem C: Funny Fluffy Tuzi

Time Limit: 3 Sec Memory Limit: 512 MB

## Description

Fluffy Funny **Tuzi** (FFT) has $N$ piles of carrot lining up in a line, the $i$-th of which has $a_i$ carrots.

**Tuzi** wants as many carrots as possible. It can magically merge two adjacent piles $a_i,a_{i+1}$ to produce a new pile with $(a_i⊕a_{i+1})+1$ carrots. Here $⊕$ means binary xor.

Nevertheless, **Tuzi** does not want to think optimally. Everytime it will pick the pile with the least carrots, and merge it with one of its adjacent pile(s) so that the new pile has the maximum possible number of carrots.

- If multiple piles contain the least number of carrots, then the left-most such pile is chosen.
- If for the chosen pile there are two merge choices and both choices yield a pile with the same number of carrots, the the left adjacent pile is merged.

**Tuzi** will keep merging until there is only one pile of carrots. It wonders how many carrots it can eventually obtain.

## Input

The first line contains an integer $N$.

The second line contains $N$ integers $a_1,a_2,…,a_N$.

### Input Limit

- $1≤N≤500000$
- $0≤a_i<2^{30}$

It is guaranteed that anytime any pile contains less than $2^{31}$ carrots.

## Output

Output a single number: the number of carrots in the final pile.

## Sample Input

```
5
3 6 6 7 1 
```

## Sample Output

```
7
```

## HINT

**Do NOT use any STL related to Heap and BST!**

