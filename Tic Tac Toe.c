#include "Game.h"

int main()
{
    Player Players[2] = {{"NULL", 0}, {"NULL", 0}};

    int success = initPlayers(&Players[0], &Players[1]);
    if (success == 1)
    {
        //start the main game. 
        printGrid();
        while (true)
        {
            
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