## Problem E: [Middle] Gift

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Dateri's birthday is coming. LowbieH wants to buy Dateri a big bear as a birthday present. Unfortunately, LowbieH has no money, so he plans to send a necklace to Dateri. This is a kind of special necklace which contains a sequence of diamonds with letters in, and it can be regarded as a string. LowbieH gives you a semi-finished necklace and askes you to add as few as possible diamonds to the head or tail of the necklace to make the necklace consist of at least two same circulation sections. A circulation section of a string is a substring which could build the original string by repeating the circulation section several times. Please answer the number of diamonds that you should add.

## Input

The first line contains an integer $n$, which is the number of test cases. $(1≤n≤1000) $

For each case, there is only one line of string containing lowercase letters, which indicates the semi-finished necklace. The length of each string is no more than $200,000$.

## Output

The output for each test case is an integer which is the number of diamonds that Amayama should add.

## Sample Input

```
2
wawawa
failed
```

## Sample Output

```
0
6
```