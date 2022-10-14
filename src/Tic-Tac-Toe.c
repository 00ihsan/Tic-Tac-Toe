#include "Game.h"

int main()
{
    Player Players[2] = {{"NULL", 0, 'X'}, {"NULL",0 ,'O'}};
    clearScreen();
    printf("Welcome to Tic Tac Toe V3!\n\r");
    printf("(C) Ihsansoft 2022\n\r");
    int success = initPlayers(&Players[0], &Players[1]);
    if (success)
    {
        clearScreen();
        setDefaultGrid();
        //start the main game. 

        int currentPlayer = 0;
        while (1) //main game loop.
        {    
            clearScreen();
            char wonchar = '\n';       
            if (checkPlayerWon(&wonchar)) //checks if a player has won the game.
            {
                Player* playerWon = NULL;
                if (Players[0].Icon == wonchar)
                {
                   playerWon = &Players[0];
                   Players[0].Score++;
                   currentPlayer = 1;
                }
                else if (Players[1].Icon == wonchar)
                {
                    playerWon = &Players[1];
                    Players[1].Score++;
                    currentPlayer = 0;
                }
                printScore(&Players[0], &Players[1]);
                printGrid();
                printf("%s won this round!\nPlay again? (yes/no) ", playerWon->Name);
		if (AskCancelGame(Players[0], Players[1])) {return 0;} 
            }
            else if (checkGridFull()) //check if it's a tie.
            {
                printGrid();
                printf("It's a tie!\nPlay again? (yes/no) ");
                if (AskCancelGame(Players[0], Players[1])) {return 0;}
                clearPositions();
                setDefaultGrid();
            }
            else // continue playing
            {
                printScore(&Players[0], &Players[1]);
                printGrid();
                printf("%s, Your turn.\n", Players[currentPlayer].Name);
                char command[10] = "NULL";
                printf("Where do you want to put %c? ", Players[currentPlayer].Icon);
                int successScan = scanf("%s",&command);
                if (strcmp(command, "exit\0") == 0) { return 0; }
                else
                {
                    int successDraw = draw((int)((char)command[0] - (char)'0'), Players[currentPlayer]);
                    if (successDraw == -1)
                    {
                        printf("Something went wrong!\n");
                    }
                    else if (successDraw == -2)
                    {
                        printf("Choose one that is not used.\n");
                    }
                    else if (successDraw == 0)
                    {
                        if (currentPlayer) { currentPlayer = 0; } else { currentPlayer = 1; }
                    }
                }
            }
        }
    }
    else if (success == 2)
    {
        printf("Same names are not allowed!\n");
        main();
    }
    else
    {
        printf("Something went wrong! Error: %d\nExitting", success);
        return success;
    }
    return -1;
}
