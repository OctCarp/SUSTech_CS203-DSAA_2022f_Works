## Problem F: Plants vs. Zombies

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

You want your plants be more stronger to against the zombies. You have $n$ plants, each plant has two attributes: height and strength. Crazy Dave has two kinds of fertilizer $F_h$ and $F_s$. Each bag of $F_h$ can make one plant double its height, and each bag of $F_s$ can make one plant's strength equals its height. Crazy Dave gives you $p$ bags of $F_h$ and $q$ bags of $F_s$. You want to maximize the sum of your plants' strength.

More formally, you are given $n$ pair of integers < $h_i,s_i$ >, which indicates the height and strength of the $i$-th plant. You can use at most $p$ times $F_h$ and at most $q$ times $F_s$

If you give a $F_h$ to the $i$-th plant, then $h_i=h_i∗2$;

If you give a $F_s$ to the $i$-th plant, then $s_i=h_i$.

You want to maximize the $∑s_i$

## Input

The first line of the input contains three integers $n,p,q$.

For the next $n$ lines, each line contains two integers $h_i,s_i$, indicates the height and strength of the $i$-th plant.

For all cases, $1≤n≤2∗10^5, 0≤p≤20, 0≤q≤2∗10^5, 1≤h_i,s_i≤10^9$.

## Output

Print one integer indicates the maximum of $∑s_i$.

## Sample Input

```
2 1 1
10 8
6 1
```

## Sample Output

```
21
```
