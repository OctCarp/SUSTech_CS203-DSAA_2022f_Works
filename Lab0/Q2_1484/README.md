
## All in at the river

* Time Limit: 1 Sec
* Memory Limit: 128 MB

* * *

### Description

Paul is learning a Poker game. The game includes 52 cards, and each card has a suit (Diamonds — D, Clubs — C, Spades — S, or Hearts — H), and a rank (2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, or A). Paul has 5 cards in his hands, and the dealer will show a card.Paul will choose to all in if and only if at least one of his card has the same suit or rank as the dealer's card.Determine whether Paul will all in or not.

### Input

The first line of the input contains one string which describes the dealer's card. The second line contains five strings which describe the cards in Paul's hands.Each string is two characters long. The first character denotes the rank and belongs to the set{2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A}. The second character denotes the suit and belongs to the {D, C, S, H}.All the cards in the input are different.

### Output

Print "All in" if Paul will choose to all in. Otherwise, print "Fold" (without quotes).

### Sample Input

```
AS
2H 4C TH JH AD
```

### Sample Output

```
All in
```