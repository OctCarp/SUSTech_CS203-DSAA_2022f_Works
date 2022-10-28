## Problem D: Dateri's Investment In Stocks

Time Limit: 1 Sec Memory Limit: 32 MB

## Description

Dateri is a smart boy who is thirsty for making a big fortune. Recently, he decides to invest in stocks to try his luck. Unfortunately, due to the miserable state of the economy and lack of knowledge and experience, he suffered a great loss of money. He has no choice but to ask LowbieH for help. LowbieH offers him a predictor which can forecast the stock index of the upcoming $n$ days. Dateri is very excited and can't wait to make money. He wants to know the minimum days that he needs to wait to get a rise in the index if making a buy-in on the $k$-th day.

## Input

The first line is an integer $T(1≤T≤12)$, meaning the number of the test cases.

For each test case, an integer $n(1≤n≤2∗10^5)$ denotes the number of the forecasted upcoming days, followed by $n$ stock indexes for each day: $index_1,⋯,index_n(1≤index_i≤10^9,1≤i≤n)$.

The next line contains an integer $q(1≤q≤2∗10^5)$ denoting the number of the queries. For each query, there's an integer $k$, which means that Dateri will make a buy-in on the $k$-th day.

## Output

Print the answer of each query in $q$ lines. If Dateri can't get a rise within the upcoming $n$ days, print `−1`.

## Sample Input

```
1
5
2 3 3 5 4
5
1 2 3 4 5
```

## Sample Output

```
1
2
1
-1
-1
```

## HINT


"rise" should be understood as "strictly bigger than".

Huge input and output. You are recommended to use fast I/O.
