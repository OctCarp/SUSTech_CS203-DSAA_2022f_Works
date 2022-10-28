## Problem D: Mahhjong

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Please determine whether one can win with the 14 tiles in her hands or not.

In Mahhjong, there are 34 kinds of tiles, which are divided into four suites, named as bing, suo, wan, and zi. The bing, suo, wan have 9 kinds for each suite and zi tiles has only 7 kinds. To simplify the problem, each tile is represented with a number and a suite, for example 1b, 2s, 7w, 3z.

The rules in Mahhjong are similar with those in Mahjong, except that in Mahhjong there is **an infinite number of each kind**, while in Mahjong one kind usually contains up to 4 tiles. Also, we consider a combination of tiles winning if and only if the combination consists of four kezi or shunzi and an additional quetou.

If you are not familiar with Mahjong, here is a brief explanation:

- kezi: kezi is a set of 3 identical tiles.
	For example, {1s, 1s, 1s}, {3z, 3z, 3z} are kezi, but {1s, 2s, 1s} is not.

- shunzi: shunzi is a set of 3 continuous tiles of the same suite, but please aware that suite zi cannot form shunzi.
	For example, {1s, 2s, 3s}, {6b, 7b, 8b} are shunzi, but {5z, 6z, 7z} and {3w, 4w, 5s} are not.

- quetou: quetou is a pair of identical tiles:
	For example, {7z, 7z}, {6w, 6w} are quetou, but {1b, 2b} is not.

- special combination (winning status): we consider a combination of tiles winning if and only if the combination consists of four kezi or shunzi and an additional quetou.
	For example, {1w, 2w, 2w, 2w, 3w, 4b, 5b, 5b, 6b, 6b, 7b, 9s, 9s, 9s} is a special combination, because we can divide the set of tiles into three shunzi, a kezi and a quetou: {{1w, 2w, 3w}, {4b, 5b, 6b}, {5b, 6b, 7b}, {9s, 9s, 9s}, {2w, 2w}}

## Input

The input contains multiple test cases. 

The first line includes a single integer $T(1≤T≤10000)$--- the number of test cases.

Each of the next T lines indicates a test case. It contains a string s of 28 characters, describing the 14 tiles that Satori has. For every $1≤i≤14$, the i-th tile is described by the $(2i−1)$-th and $2i$-th characters in the string: the former is a digit denoting the rank of the tile in its suite and the latter is one of {w, b, s, z}, which means the suite wan, bing, suo and zi respectively. It is guaranteed that all the s in the input are valid and legal.

## Output

For each test case, output a single line. If one reached the winning status, print "`Blessing of Heaven`", otherwise print "`Bad luck`" (without quotes)

## Sample Input

```
5
1w2w3w4b5b6b7s8s9s1b1b1z2z6z
1w2w3w4b5b6b7s8s9s1b1b2z2z6z
1w2w3w4b5b6b7s8s9s1b1b2z2z2z
1b2b3b4b5b6b2s4s5s5s5s6s7s8s
1b1b1b2b3b4b5b6b7b8b9b9b9b1s
```

## Sample Output

```
Bad luck
Bad luck
Blessing of Heaven
Bad luck
Bad luck
```