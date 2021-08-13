#include "Game.h"

int main()
{
    int nextPlayer = 0;
    Player Players[2] = {{"NULL", 0, 'X'}, {"NULL",0 ,'O'}};

    int success = initPlayers(&Players[0], &Players[1]);
    if (success)
    {
    setDefaultGrid();
        //start the main game. 

        int currentPlayer = 0;
        while (1) //main game loop.
        {    
            char wonchar = '\n';       
            if (checkPlayerWon(&wonchar)) //checks if a player has won the game.
            {
                Player* playerWon = NULL;
                if (Players[0].Icon == wonchar)
                {
                   playerWon = &Players[0];
                   Players[0].Score++;
                   nextPlayer = 1;
                }
                else if (Players[1].Icon == wonchar)
                {
                    playerWon = &Players[1];
                    Players[1].Score++;
                    nextPlayer = 0;
                }
                printScore(&Players[0], &Players[1]);
                printGrid();
                printf("%s won this round!\nPlay again? (yes/no) ", playerWon->Name);
                char choice[4] = {"NULL"};
                scanf("%s", choice);
                if (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0)
                {
                    clearPositions();
                    setDefaultGrid();
                    currentPlayer = nextPlayer;
                }
                else if (strcmp(choice, "No") == 0 || strcmp(choice, "no") == 0)
                {
                    if (Players[1].Score > Players[0].Score)
                    {
                        printf("Allright!\n%s won this game by +%d!\nSee you later %s and %s!\n",Players[1].Name, Players[1].Score-Players[0].Score, Players[0].Name, Players[1].Name);
                    }
                    else if (Players[0].Score > Players[1].Score)
                    {
                        printf("Allright!\n%s won this game by +%d!\nSee you later %s and %s!\n",Players[0].Name, Players[0].Score-Players[1].Score, Players[0].Name, Players[1].Name);
                    }
                    else if (Players[0].Score == Players[1].Score)
                    {
                        printf("Allright!\nNobody won this game, its a tie!\nSee you later %s and %s!\n", Players[0].Name, Players[1].Name);
                    }
                    else { return -1; }
                    return 0;
                }
                else
                {
                    printf("Unknown: %s", choice);
                }
            }
            else
            {            
                if (checkGridFull()) //check if it's a tie.
                {
                    printGrid();
                    printf("It's a tie!\nPlay again? (yes/no) ");
                    char choice[4] = {"NULL"};
                    scanf("%s", choice);
                    int exitTheTieState = 0;
                    while (exitTheTieState == 0)
                    {
                        if (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0)
                        {
                            clearPositions();
                            setDefaultGrid();
                            currentPlayer = nextPlayer;
                            exitTheTieState = 1;
                        }
                        else if (strcmp(choice, "No") == 0 || strcmp(choice, "no") == 0 || strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0)
                        {
                            printf("Allright! See you later %s and %s!\n", Players[0].Name, Players[1].Name);
                            return 0;
                        }
                        else
                        {
                            printf("Unknown command: %s", choice);
                        }
                    }
                }
            }
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
            clearScreen();
        }
    }
    else if (success == 2)
    {
        printf("Same names are not allowed!\nExitting!");
        return 0;
    }
    else
    {
        printf("Something went wrong! Error: %d\nExitting", success);
        return 0;
    }
    return -1;
}
