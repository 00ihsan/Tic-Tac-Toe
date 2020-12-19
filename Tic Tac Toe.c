#include "Game.h"

int main()
{
    Player Players[2] = {{"NULL", 0, 'X'}, {"NULL",0 ,'O'}};

    int success = initPlayers(&Players[0], &Players[1]);
    if (success == 1)
    {
    setDefaultGrid();
        //start the main game. 

        int currentPlayer = 0;
        while (1)
        {
            printScore(&Players[0], &Players[1]);
            printGrid();
            printf("%s, Your turn.\n", Players[currentPlayer].Name);
            char command[10] = "NULL";
            printf("Where do you want to put %c? ", &Players[currentPlayer].Icon);
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