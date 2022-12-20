## Problem F: BuyBuyBuy [Medium]

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

The capacity of Hong’s pocket is so small that it can only contain $M$ gifts. Considering the diversity of his gifts, Hong would not buy two of the same kind.

Hong will visit $N$ shops one by one along the shopping street. There is **ONLY ONE** type of gift sold in each shop. However, he has such a poor memory that he can’t remember how many shops sell gift $K$. So, he will write a number $L$ on each gift after buying it, to indicate how many shops selling gift $K$. In Hong’s opinion, the smaller the number $L$ is, the better the gift is.

When Hong stops in a shop which sells gift $K$, there are three situations he might come across.

1. If there is no gift $K$ in his pocket and he still has some place for it, he will buy it without hesitation. Before putting it into the pocket, he will write down the number `1` on the gift to indicate that he has only seen one shop selling it.
2. If there is a gift $K$ already in his pocket, he will just add L by one, which means that there are $L+1$ shops selling gift $K$.
3. If there is no gift $K$ in his pocket and the pocket is full, he would consider that there is no shop selling gift $K$ (because he cannot remember whether he has met gift $K$), so he will have to discard one gift in his pocket to release a place for the gift $K$. But it will refer to the following rules to determine which gifts to be discarded:

He chooses the gift that has the biggest number $L$ on it. If several gifts have the same biggest number L, he will discard the one which has been put into the pocket at the earliest time. After discarding the gift, he will put gift $K$ into his pocket and write number `1` on gift $K$.

Now, your task is to write a program to record the number of these gifts which have been discarded by Hong.

## Input

The first line will be an integer $T(1≤T≤10)$, which is the number of test cases.

For each test data:

The first line has two positive integers $M$ and $N(M≤50000,N≤100000)$ where $M$ (the capacity of pocket) shows how many gifts it can take, and $N$ is the number of shops in the street. The second line has $N$ positive integers $K_i(K_i<2^{20},i=1,2,⋯,N)$ indicating the type of gift sold in the $i$-th shop.

## Output

For each test case you should output one integer, the number of discarded gifts as indicated in the sample output.

## Sample Input

```
6
3 5
1 2 3 2 4
2 4
1 2 2 1
2 6
1 2 2 1 1024 1
2 10
1 2 3 2 4 2 3 6 7 8
2 1
1048575
6 16
10 1 2 3 4 5 6 1 2 3 6 5 4 10 1 6
```

## Sample Output

```
1
0
2
7
0
3
```