## Problem C: Connected Chain

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

There are **n** chains, each chain has a single node with weight value. We will connect two chains by a sequence of operators. Last, please print the weight of the **q-th** node in each chain.

## Input

The first line three numbers, **n**, **p, q  (1<n, p<1e6 , 0<q<10)**

Next line, **n** integers (int) represents **weight** of node 1 to node n 

Next **p** lines, each line two numbers **a , b ,** it connected chains a and b (i.e., set the head of chain b as the tail of chain a (guaranteed that a and b are both head of chains)).

## Output

For each node from node 1 to node n 

If the node is the chain head and this chain has more than q points, output the weight of **q-th** point on it.

All output is separated by space

## Sample Input

```
5 3 2
1 2 3 4 5
1 3
1 4
2 5
```

## Sample Output

```
3 5
```

## HINT

For the sample, chains link like this

1->3->4

2->5
