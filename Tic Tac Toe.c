#include "Game.h"

int main()
{
    Player Players[2] = {{"NULL", 0, 'X'}, {"NULL", 'O'0}};

    int success = initPlayers(&Players[0], &Players[1]);
    if (success == 1)
    {
    setDefaultGrid();
        //start the main game. 
        while (1)
        {
            printScore(Players[0], Players[1]);
            printGrid();
            
            char command[10] = "NULL";
            scanf("%s",&command);
            if (strcmp(command, "exit\0") == 0) { return 0; }
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