# Tiger-Card-Game
Simple C++ console card game - Academic Project

1. Player Starts with a hand of 1-15 cards at random. Hand size depends on how many rounds the player chooses at the start. Cards are organized as follows:
     a. 4 suits: Purple, Orange, Black, & Tiger
     b. Each suit has a unique ranking system (15 purple cards ranked 1-15, 10 orange cards ranked 1-10, 5 black cards ranked 6-10, and Tiger with rank 10).
     c. The value of cards can be calculated as follows...
         i. Purple card values are equal to their rank (ex. purple:2 has a value of 2).
         ii. Orange card values are double their rank (ex. orange:2 has a value of 4).
         iii. Black card values are triple their rank (ex. black:6 has a value of 18).
         iv. Tiger card is a special card, being worth 50 points, and on being played will immediately end the game.
2.  The computer will make the first move every round. The card it plays is selected randomly.
3.  The player will select a card by typing an integer, with cards in player's hand being numbered from 1 upwards.
4.  Whichever player has the larger card value will win the current round. The winner will receive points equal to the sum of the two cards played.
     a. Ex. If computer played "orange:6" and player played "black:9", the player would win and be awarded 39 points.
   
   
