# Betting Simulation

practicing OOP and multithreading in c++ on a custom made problem

### Problem statement

We will simulate a betting excercise, similiar to the dog races.
There are 100 players with 100 dollars betting on 5 dogs. The Betting company makes the bets, such that whatever the outcome is, it is winning money.

The betting will cosist of n rounds

1. The betting company discloses the quotes for every dog, and the player pay the participation fee of 1dollar.
2. The betting starts, we randomly select a player, and after a random bid of 1 dollars, we modify the quotes on the dogs, such that whatever the next bid is, the betting company still wins 10 dollars.

3. The race begins, and the outcome is a random dog win (according to the initial quotes). The players get back the money, if they betted on the right dog.



There are 4 types of player (they form the diamond of death problem):

1. Ordinary
2. Agressive, who bets twice the amount as an ordinary
3. VIP doesn't have to pay for participation, and bets as an ordinary player
4. Agressive VIP player, bets as an agressive and don't pay for participation



Touched concepts:

1. Inheritance
2. Multiple inheritance
3. Diamond of death
4. Virtual destructor
5. Virtual inheritance


p.s. I don't care about dog races.