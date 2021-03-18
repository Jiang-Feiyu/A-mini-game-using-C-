# engg1340comp2113
**Introduction of our game**
We would like to design a game which will display a 5 * 5 board at beginning. There are four kinds of symbols on the board, which displays numbers from “0” to “3”, while the player’s position will be displayed as “A”. The game is designed for two players and we will use player1 and player2 below. Number “1” represents the beginning places of players, which is opposite on the board. Number “2” is assigned by the computer at random. In case of assigning “2” at “1” or “3”, the “2”s will not appear on the left and right column of the board. There are total three “2” point, meaning the wall. Players cannot move through the wall. And the number “3” means the shortcut, which are distributed on the opposite corner of the board. The chess can move to the opposite door directly on either sides. Number “0” means safe zone. 
For the player, they can control the direction of moving the chess from the beginning position. Namely they can move their chess up, down, left and right on the safe zone. Their chess can not go through or go into the wall. They can use strategy to use the shortcut to save distance as well as time. The first one who arrive at the beginning position of the other player will be the winner. Once the winner appears, the game over. 

**Features to implement**
1. Using random variables to initialize the array and save changes the player make .
2. Judging whether the player’s assigned point is 0/1/2/3, and make the default reaction.
3. Shows the turn and the result when the game is over.

**Match code requirement**
1-Random generation: Using random to assign the walls. 
2-Data structures: Using arrays to create a game map with numbers. 
3-Dynamic memory:Refresh after each turn.
4-File input/output: Allow players to move the chess freely and record the player’s position. 
5-Multiple files: Main body, displaying the board, examination of victory.
