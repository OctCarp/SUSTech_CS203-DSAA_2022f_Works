## Problem B: Shopping

Time Limit: 1 Sec Memory Limit: 512 MB

## Description

After DSAA class, Jackie wants to buy lunch food.

There are n shops in a circle, which are labelled from 1 to $n$. Each shop has infinity food, and the price of the food at $i$-th shop is $A_i$. Jackie will start his shopping by following the circle “1 -> 2 -> 3 … -> $n$ -> 1” to buy food. In $i$-th shop, if Jackie has enough money to buy one unit food in this shop, he will pay $A_i$ to buy it and go to the next shop, otherwise he will go to the next shop. If he could not buy anything, he will stop shopping.

Now the money in Jackie’s pocket is $m$, he wants to know the total amount of food he can buy.

## Input

The first line contains two integers $n, m (1 ≤ n ≤ 200000, 0 ≤ m ≤ 10^{18})$, denotes the number of the shop and the money Jackie has.

The second line contains $n$ integers, the $i$-th integer $A_i (1 ≤ A_i ≤ 10^9)$ denotes the unit price of the food in $i$-th shop.

## Output

One line an integer, denotes the amount of food Jackie can buy.

## Sample Input

```
3 6
1 2 2
```

## Sample Output

```
4
```

## HINT

Jackie will stop buying when he has paid 1+2+2+1=6. Thus, the total amount of food he can get is 4.