#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "Player.h"
#include <string.h>

char grid[9] = {"1","2","3","4","5","6","7","8","9"};

int initPlayers(Player* Player1, Player* Player2);

void printGrid();

#endif