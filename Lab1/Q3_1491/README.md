## Moon Cake

Time Limit: 1 Sec Memory Limit: 128 MB Special Judge

## Description

There are $n$ students in CS203 DSAA. Dr. Tang has mm moon cakes for students to celebrate the Mid-Autumn Festival. The radius of moon cake are $r_1,r_2,…,r_m$. Dr. Tang hopes every student can get **exactly one** equal-sized moon cake.

To meet this goal, some moon cakes may be cut. If a moon cake is cut, it is split into two parts and each part can be seemed as a new moon cake.

To make the problem easier, all the moon cake has the same thickness and the cut is legal if and only if the cutting surface is perpendicular to the circular surface.

## Input

The first line of the input contains two integers $n$ and $m(1≤n,m≤106)$ ---- the number of students and the number of moon cakes.

The second line contains mm integers $r_i(1≤r_i≤10^3)$ ---- the radius of ii-th moon cake

## Output

Print the maximum area of moon cake for each student

## Sample Input

```
12 3
2 2 2
```

## Sample Output

```
3.1415926
```

## HINT

We use special judge in this problem, i.e., you only need to guarantee abs(your answer - suggested answer) $≤10^-5$.

Note: It is suggestive for you to use Math.floor() in java when you turn the result of double decision into integer. For cpp user, please use printf() to print your answer.