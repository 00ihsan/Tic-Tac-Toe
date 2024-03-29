#include "Game.h"
#include <unistd.h>

char grid[9] = {'1'-'0','2'-'0','3'-'0','4'-'0','5'-'0','6'-'0','7'-'0','8'-'0','9'-'0'};

int usedPositions[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int AskCancelGame(Player* Player1, Player* Player2)
{
    char choice[4] = {"NULL"};
    scanf("%s", choice);
    if (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0 || strcmp(choice, "Y") == 0 || strcmp(choice, "y") == 0)
    {
        clearPositions();
        setDefaultGrid();
        return 0;
    }
    else if (strcmp(choice, "No") == 0 || strcmp(choice, "no") == 0 || strcmp(choice, "N") == 0 || strcmp(choice, "n") == 0)
    {
        if (Player2->Score > Player1->Score)
        {
            printf("Allright!\n%s won this game by +%d!\nSee you later %s and %s!\n",&Player2->Name, Player2->Score-Player1->Score, Player1->Name, Player2->Name);
        }
        else if (Player1->Score > Player2->Score)
        {
            printf("Allright!\n%s won this game by +%d!\nSee you later %s and %s!\n",&Player1->Name, Player1->Score-Player2->Score, Player1->Name, Player2->Name);
        }
        else if (Player1->Score == Player2->Score)
        {
            printf("Allright!\nNobody won this game, its a tie!\nSee you later %s and %s!\n", Player1->Name, Player2->Name);
        }
        else { return -1; }
        return 1;
    }
    else
    {
        printf("Unknown: %s", choice);
    }
}

int initPlayers(Player* Player1, Player* Player2)
{
    //temp to store scanf
    char name11[32] = "NULL11";
    char name22[32] = "NULL22";
    printf("Player 1 name: ");
    scanf("%s", &name11);
    printf("Player 2 name: ");
    scanf("%s", &name22);
    //copy temp name in struct.
    strcpy(Player1->Name, name11);
    strcpy(Player2->Name, name22);
    printf("Hi %s and %s!\n\n", &Player1->Name, &Player2->Name);
    if (strcmp(Player1->Name, Player2->Name) == 0 ) { return 2; }
    else if (strcmp(name22, "NULL22") && strcmp(name11, "NULL11")) { return 1; }
    else { return 0; }
    return -1;
}

void printGrid()
{
    printf("\n");
    printf("    %c  |  %c  |  %c  \n", grid[0], grid[1], grid[2]);
    printf("  -----+-----+-----\n");
    printf("    %c  |  %c  |  %c  \n", grid[3], grid[4], grid[5]);
    printf("  -----+-----+-----\n");
    printf("    %c  |  %c  |  %c  \n", grid[6], grid[7], grid[8]);
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

void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

int checkGridFull()
{
    uint16_t result = 0;
    for (int i = 0; i < 9; i++)
    {
        result = (result << 1) | usedPositions[i];
    }

    if (result == 511) { return 1; }
    else {return 0;}
}

void clearPositions()
{
    for (int i = 0; i < 9; i++)
    {
        usedPositions[i] = 0;
    }
}

int checkPlayerWon(char* wonChar)
{
    if (grid[0] == grid[1] && grid[1] == grid[2])
    {
        *wonChar = grid[1];
        return 1;
    }
    else if (grid[3] == grid[4] && grid[4] == grid[5])
    {
        *wonChar = grid[4];
        return 1;
    }
    else if (grid[6] == grid[7] && grid[7] == grid[8])
    {
        *wonChar = grid[7];
        return 1;
    }
    else if (grid[0] == grid[3] && grid[3] == grid[6])
    {
        *wonChar = grid[6];
        return 1;
    }
    else if (grid[1] == grid[4] && grid[4] == grid[7])
    {
        *wonChar = grid[4];
        return 1;
    }
    else if (grid[2] == grid[5] && grid[5] == grid[8])
    {
        *wonChar = grid[5];
        return 1;
    }
    else if (grid[2] == grid[4] && grid[4] == grid[6])
    {
        *wonChar = grid[4];
        return 1;
    }
    else if (grid[0] == grid[4] && grid[4] == grid[8])
    {
        *wonChar = grid[4];
        return 1;
    }
    
    return 0;
}
