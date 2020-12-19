#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include "Player.h"
#include <string.h>

int initPlayers(Player* Player1, Player* Player2);

void printGrid();

void printScore(Player* player1, Player* player2);

void setDefaultGrid();

#endif