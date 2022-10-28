## Problem B: Cinema

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

SUSTech Cinema is open for business! There are two ticket offices and all the students form two queues. It takes each student one minute to buy his ticket(s). The students can be separated into $n$ groups each with one or two people. **To save time, two students in the same group will not queue up in the same line.**

For the two-students group, if one group member has bought the tickets, **the other one will leave the queue immediately**. Also, if two students get to the ticket windows at the same time, then **they will buy their own ticket respectively**.

Now LowbieH will give the description of the queueing situation, can you tell him the waiting time for each group?

## Input

The first line contains three integer $n, p, q(1≤p, q≤n≤100000)$, which are the number of groups and the lengths of the two queues. The following two lines consist of serial numbers (range from $1$ to $n$) in each queue separately. Two same serial numbers stand for a two-people group.

## Output

Output the waiting time of each group in order.

## Sample Input

```
5 4 5
1 2 3 4
2 4 1 3 5
```

## Sample Output

```
1 1 2 2 3
```

## HINT

Minute 0: 1 2 3 4; 2 1 4 3 5

Minute 1: 3 4; 4 3 5


Minute 2: Nobody; 5
