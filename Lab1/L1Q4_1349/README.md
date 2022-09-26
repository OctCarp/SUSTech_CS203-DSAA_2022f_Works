## Chasing the Robot

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

CC has just finished the lecture of DSAA, when she realized that her robot is missing. The robot is her project for Digital Design, so she must find it as soon as possible.

The robot is actually walking away by itself. Now it is at $(x_r,y_r)$ on a two-dimensional plane. And it is **periodically** moving according to a sequence of instructions. The sequence only contains characters of 'U', 'D', 'L', 'R' denoting that it will cost one minute to move up, down, left or right for one unit.

Now, CC is at $(x_c,y_c)$ and she starts chasing the robot. In each minute, CC can choose one direction among up, down, left and right and moves one unit in this direction, or she can choose to stay at the position.

Do you know how many minutes CC needs at least to get her robot?

## Input

The first line contains four integers $x_r,y_r,x_c,y_c(0≤x_r,y_r,x_c,y_c≤10^9)$, indicating the initial coordinates of CC and her robot (the robot at $(x_r,y_r)$ and CC at $(x_c,y_c)$. It's guaranteed that they do not start at the same position.

The second line contains an integer $N(1≤N≤10^5)$, indicating the length of the sequence of instructions.

The third line contains the sequence $S$, which only contains 'U', 'D', 'L', 'R'.

## Output

Output the minimum minutes CC needs to get her robot.

If she cannot get it forever, print -1.

## Sample Input

```
5 7 1 1
4
DDDD
```

## Sample Output

```
5
```