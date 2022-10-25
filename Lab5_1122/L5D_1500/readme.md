## Problem D: Long Long Road

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

There are two robots on the plane, each with a track. Initially, they are each located at the starting point of their respective tracks. You need to move them to the destination. Each time, you can give the robot a moving command, either 'N', 'S', 'E', or 'W'. If the robot can move along the track in the specified direction, it will move 1 unit in that direction. Otherwise, the robot does not move.

Note that the track may pass through the same coordinates, but they are not the same place of the track. For example, a track is (0,0)-(0,-1)-(0,-2)-(-1,-2)-(-1,-1)-(0,-1)-(1,-1). And a robot is on the sixth point, (0,-1). It can move to the fifth point by 'W' or to the seventh point by 'E'. Otherwise, it won't move. In other words, if the current position is the $i$-th point, the robot can only move to the $(i−1)$-th point or the $(i+1)$-th point according to the command.

However, you find that the control system is malfunctioning and you can only give the same command to both robots at the same time.

Now you are giving the track of the two robots. If it is possible to let them reach their destinations at the same time?

## Input

The first line of the input contains a single integer $n(2≤n≤1000000)$, which is the length of the track.

The second line of the input contains a string which has $n−1$ characters, each of them is either 'N', 'E', 'S', or 'W'. It is the track of the first robot from the starting point to the destination.

The third line of the input contains a string which has $n−1$ characters, each of them is either 'N', 'E', 'S', or 'W'. It is the track of the second robot from the starting point to the destination.

It is guaranteed that the track won't have ambiguous cases like (1,1)-(2,1)-(1,1).

## Output

Print "YES" if it is possible for both robots to stay at the destination at the same time. Otherwise, print "NO".

## Sample Input

```
7
SSWNEE
NENENE
```

## Sample Output

```
YES
```

## HINT

For the sample, you can give the following command: "SSWNEENENE" to let both robots stay at the destinations at the same time.