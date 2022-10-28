## Problem D: String Problem D

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

Given two strings $S,T$, you are required to judge if you can obtain one of the two strings by rotating the other one

## Input

Two lines, indicating two strings $S,T (1≤|S|,|T|≤10^6)$ 

## Output

One line, "`Yes`" (with out quotes) if you can obtain one of the two strings by rotating the other one, "`No`" (with out quotes) otherwise.

## Sample Input

```
abcde
cdeab
```

## Sample Output

```
Yes
```

## HINT

$abcde$ and $cdeab$ -> Yes

$abcde$ and $edcba$ -> No

$abcdeabcde$ and $abcde$ -> No

Example of rotating a string:

$abcde$ -> $bcdea$ -> $cdeab$ -> $deabc$ -> $eabcd$ -> $abcde$
