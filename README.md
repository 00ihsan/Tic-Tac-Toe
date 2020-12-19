# Tic-Tac-Toe
Tic Tac Toe game written in C

## Location
the main function is located in Tic "Tac Toe.c".
everything to do with the game is located in "Game.c".

## Main()
The game starts when success == 1. 

```C
int success = initPlayers(&Players[0], &Players[1]);
    if (success == 1)
    {
        //start the main game.
    }
```
