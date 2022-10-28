## Problem A: Canteen

Time Limit: 1 Sec Memory Limit: 128 MB

## Description

It's lunch time now! Students are queuing in a **queue** and each student has **one specific kind of favorite food**. The canteen offers different kinds of food in a **stack**. If the food on the top of the stack matches one's favorite food in his turn, he will take it and leave the queue. **Otherwise, he will go back to the end of the line to queue up again.**

The canteen will open for $T$ time slots. LowbieH now gives you the event of each time slot. There are 3 types of events in total:

*Event 1:* `NewFood NameOfNewFood` (Push new food into the stack.)

*Event 2:* `NewComer NameOfFavouriteFood` (A new student will join the queue with his favorite food.)

*Event 3:* `TakeFood` (The first student in the queue will make his choice. **If the food stack is empty, he will do nothing.**)

After $T$ time slots, the canteen will stop providing new food. The remaining students in the queue will take the food or queue again successively **until the food stack is empty or nobody could get his favorite food**. After that the canteen will close.

Can you tell LowbieH that how many students will be left to starve when the canteen closes?

## Input

The first line contains an integer $T(0≤T≤10000)$. The following $T$ lines are the events that mentioned in the description above. The input is guaranteed to be valid.

## Output

If everyone had taken his favorite food, you should print "`Qi Fei!`"(without quotation marks). Otherwise, please tell LowbieH the number of the remaining hungry students.

## Sample Input

```
6
NewComer SpicyHotPot
NewComer BarbecuedPorkCombo
NewFood BarbecuedPorkCombo
TakeFood
NewFood SpicyHotPot
NewFood BarbecuedPorkCombo
```

## Sample Output

```
Qi Fei!
```
