#include "Game.h"

char grid[9] = {"1","2","3","4","5","6","7","8","9"};

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
    printf("+-----+-----+-----+");
    printf("|  %c  |  %c  |  %c  |\n", &grid[0], grid[1], &grid[2]);
    printf("+-----+-----+-----+");
        printf("|  %c  |  %c  |  %c  |\n", &grid[3], grid[4], &grid[5]);
    printf("+-----+-----+-----+");
        printf("|  %c  |  %c  |  %c  |\n", &grid[6], grid[7], &grid[8]);
    printf("+-----+-----+-----+");
}