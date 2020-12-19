#include "Game.h"

char grid[9] = {'1'-'0','2'-'0','3'-'0','4'-'0','5'-'0','6'-'0','7'-'0','8'-'0','9'-'0'};

int usedPositions[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int initPlayers(Player* Player1, Player* Player2)
{
    //temp to store scanf
    char name11[32] = "NULL11";
    char name22[32] = "NULL22";
    printf("Welcome to Tic Tac Toe v1.0\n(C) Ihsansoft 2020\n");
    printf("Player 1 name: ");
    scanf("%s", &name11);
    printf("Player 2 name: ");
    scanf("%s", &name22);
    //copy temp name in struct.
    strcpy(Player1->Name, name11);
    strcpy(Player2->Name, name22);
    printf("Hi %s and %s!\n", &Player1->Name, &Player2->Name);
    if (strcmp(Player1->Name, Player2->Name) == 0 ) { return 2; }
    else if (strcmp(name22, "NULL22") && strcmp(name11, "NULL11")) { return 1; }
    else { return 0; }
    return -1;
}

void printGrid()
{
    printf("\n");
    printf("   %c  |  %c  |  %c  \n", grid[0], grid[1], grid[2]);
    printf("------+-----+------\n");
    printf("   %c  |  %c  |  %c  \n", grid[3], grid[4], grid[5]);
    printf("------+-----+------\n");
    printf("   %c  |  %c  |  %c  \n", grid[6], grid[7], grid[8]);
    printf("\n");
}

int checkPosition(int position)
{
    if (usedPositions[position - 1]) { return 1; } else { return 0; }
    return -1;
}

void printScore(Player* player1, Player* player2)
{
    printf("%s: %d (%c)    %s: %d (%c)\n", player1->Name, player1->Score, player1->Icon, player2->Name, player2->Score, player2->Icon);
}

int draw(int position, Player p)
{
    if (position > 0 && position < 10)
    {
        int used = checkPosition(position);
        if (!used)
        {
            usedPositions[position-1] = 1;
            grid[position-1] = p.Icon;
            return 0;
        } 
        else { return -2; }
    }
    return -1;
}

void setDefaultGrid()
{
    for (int i = 0; i < 9; i++)
    {
        sprintf(&grid[i], "%d", i+1);
        // grid[i] = (char)(i+1) - (char)'0';
    }
}